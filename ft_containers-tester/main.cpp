/*

   ___            _        _
  / __\___  _ __ | |_ __ _(_)_ __   ___ _ __ ___
 / /  / _ \| '_ \| __/ _` | | '_ \ / _ \ '__/ __|
/ /__| (_) | | | | || (_| | | | | |  __/ |  \__ \
\____/\___/|_| |_|\__\__,_|_|_| |_|\___|_|  |___/

 _            _
| |_ ___  ___| |_ ___ _ __
| __/ _ \/ __| __/ _ \ '__|
| ||  __/\__ \ ||  __/ |
 \__\___||___/\__\___|_|

 llaurent (https://profile.intra.42.fr/users/llaurent)

 Le testeur ne DOIT PAS déterminer si le projet est vrai ou faux -- il se peut que le testeur ne soit pas parfait
 */

#include "Tester_Include.hpp"

// Mettre ici les headers de vos containers
#include "../list/list.hpp"
#include "../vector/vector.hpp"
#include "../map/map.hpp"
#include "../queue/queue.hpp"
#include "../stack/stack.hpp"

int main()
{
	/*
	 * Pour lancer un test spécifique, passez en paramètre un std::list<string> qui contient le nom des tests voulu
	 * Pour plus d'informations, se référer au README
	 */
	exec_test_list<ft::list<int> >();
	exec_test_map<ft::map<int, int> >();
	exec_test_vector<ft::vector<int> >();
	exec_test_queue<ft::queue<int> >();
	exec_test_stack<ft::stack<int> >();

	/*
	 * Ne pas toucher à cette ligne
	 */
	display_failed_containers();
	return (0);
}
