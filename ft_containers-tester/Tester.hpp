#ifndef TESTER_HPP
# define TESTER_HPP

# include "Config.hpp"
# include <algorithm>
# include <map>
# include <cassert>
# include <iostream>
# include <list>
# include <unistd.h>
# include <cstdlib>
# include <wait.h>
#include <sstream>

typedef void (*fn_ptr)();
typedef std::list<std::string> wanted_tests_type;

template <typename T> bool isConst(T& x)
{
	(void)x;
	return false;
}

template <typename T> bool isConst(T const& x)
{
	(void)x;
	return true;
}

void announce_test(const std::string &test_name);
void success_test(const std::string &test_name);
void launch_test(const std::string &func_name);
void error_test(const std::string &test_name, const int &status);
void announce_errors(const int fail_number);

struct Tester {
private:
	std::list<std::string> failed_containers;

	bool contains(const std::string containerName) {
		return ((std::find(failed_containers.begin(), failed_containers.end(), containerName) != failed_containers.end()));
	}

public:
	int total_fail;

	bool hasFailedContainers() const {
		return (!failed_containers.empty());
	}

	void failContainer(const std::string containerName) {
		if (!this->contains(containerName)) {
			failed_containers.push_back(containerName);
		}
	}

	const std::string getFailedContainers() const {
		std::_List_const_iterator<std::basic_string<char> > begin = failed_containers.begin();
		std::ostringstream __construct;
		__construct << "[";
		while (begin != failed_containers.end()) {
			__construct << *begin;
			begin++;
			if (begin != failed_containers.end()) {
				__construct << ", ";
			}
		}
		__construct << "]";
		return __construct.str();
	}
};

Tester tester;

struct Global
{
	std::map<std::string, fn_ptr> funcs;
	std::string className;
	int errors;

	void start_test(wanted_tests_type tests)
	{
		errors = 0;
		if (tests.empty())
		{
			std::map<std::string, fn_ptr>::iterator begin = funcs.begin();
			while (begin != funcs.end())
			{
				launch_test(begin->first);
				begin++;
			}
		}
		else
		{
			wanted_tests_type::iterator begin = tests.begin();
			while (begin != tests.end())
			{
				launch_test(*begin);
				begin++;
			}
		}
		if (!STOP_IF_KO && errors) {
			announce_errors(errors);
			tester.failContainer(className);
		}
	}
};

Global global;

void register_test(const std::string &func_name, fn_ptr ptr)
{
	global.funcs[func_name] = ptr;
}

void launch_test(const std::string &func_name)
{
	int status;
	if (global.funcs.find(func_name) == global.funcs.end())
	{ throw std::invalid_argument("\"" + func_name + "\" function is not registered so it cannot be launched"); }
	announce_test(func_name);
	pid_t pid = fork();
	if (pid == 0)
	{
		global.funcs[func_name]();
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
	{ success_test(func_name); }
	else
	{
		error_test(func_name, status);
		if (STOP_IF_KO) {
			exit(status);
		} else {
			global.errors++;
			tester.total_fail++;
		}
	}
}

void display_failed_containers() {
	if (tester.hasFailedContainers() && !(STOP_IF_KO)) {
		std::cout << "\n\033[01;31m" << "|- \033[0;31mContainers that contains error : " << tester.getFailedContainers() << ".\nTotal [KO] : " << tester.total_fail << "\033[0;0m" << std::endl;
	} else if (!tester.hasFailedContainers()) {
		std::cout << "\n\033[01;32m" << "|- \033[01;32mAll your containers are good for this tester.\033[0;0m"
				 << std::endl;
	}
}

void register_test_and_launch(const std::string &func_name, fn_ptr ptr)
{
	register_test(func_name, ptr);
	launch_test(func_name);
}

void new_type(const std::string &class_name)
{
	global.funcs.clear();
	global.className = class_name;
	std::cout << "\033[01;36m" << "[ TESTS : " << class_name << " ]\033[0;0m" << std::endl;
}

void category(const std::string &category)
{
	std::cout << "\033[01;33m" << "|-- category : " << category << "\033[0;0m" << std::endl;
}

void announce_test(const std::string &test_name)
{
	std::cout << "\033[0;35m" << "|- starting test " << test_name << "\033[0;0m" << std::endl;
}

void success_test(const std::string &test_name)
{
	std::cout << "\033[01;32m" << "|- \033[0;32m[OK]\033[01;32m test " << test_name << " is a success\033[0;0m"
			  << std::endl;
}

void error_test(const std::string &test_name, const int &status)
{
	if (status == SIGSEGV)
		std::cout << "⚠️ There is a segfault in your container (or maybe in the tests)" << std::endl;
	std::cout << "\033[01;31m" << "|- \033[0;31m[KO]\033[01;31m test " << test_name << " contains an error "
			  << "(status code : " << status << ")" << "\033[0;0m" << std::endl;
}

void announce_errors(const int fail_number)
{
	std::cout << "\033[01;31m" << "|- \033[0;31mThe container " << global.className << " contains " << fail_number << " error(s).\033[0;0m" << std::endl;
}

#endif