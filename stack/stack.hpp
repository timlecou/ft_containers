#ifndef	STACK_HPP
# define STACK_HPP
# include "../list/list.hpp"

namespace	ft
{
	/**
	 * Stacks are a type of container adaptor, specifically designed to operate
	 * in a LIFO context (last-in first-out), where elements are inserted and
	 * extracted only from one end of the container.
	 */
	template <class T, class Container = ft::list<T> >
	class stack
	{
		public:
			typedef	T			value_type;
			typedef	Container	container_type;
			typedef	size_t		size_type;

		private:
			container_type		_container;

		public:
			/**
			 * Stack construtor
			 *
			 * Constructs a stack container adaptor object.
			 * @ctnr : Container object.
			 */
			explicit stack (const container_type& ctnr = container_type())
			{
				this->_container = ctnr;
			}

			/**
			 * Stack copy construtor
			 *
			 * Constructs a copy of stack in a stack container.
			 * @stack : a stack container.
			 */
			stack (const stack &stack)
			{
				*this = stack;
			}

			/**
			 * Stack destructor
			 *
			 * Destructs the container.
			 */
			~stack (void)
			{
				return ;
			}

			/**
			 * Returns wether the stack is empty
			 *
			 * @return : true if the underlying container's size is 0, false otherwise.
			 */
			bool empty (void) const
			{
				return (this->_container.empty());
			}

			/**
			 * Returns the number of elements in the stack.
			 *
			 * @return : The number of elements in the underlying container.
			 */
			size_type size (void) const
			{
				return (this->_container.size());
			}

			/**
			 * Returns a reference to the top element in the stack.
			 *
			 * @return : A reference to the top element in the stack.
			 */
			value_type& top (void)
			{
				return (this->_container.back());
			}

			/**
			 * Returns a const reference to the top element in the stack.
			 *
			 * return : A const reference to the top element in the stack.
			 */
			const value_type& top (void) const
			{
				return (this->_container.back());
			}

			/**
			 * Inserts a new element at the top of the stack, above its current top element.
			 *
			 * @val : Value to which the inserted element is initialized.
			 */
			void push (const value_type& val)
			{
				this->_container.push_back(val);
			}

			/**
			 * Removes the element on top of the stack, effectively reducing its size by one.
			 */
			void	pop (void)
			{
				this->_container.pop_back();
			}

			/**
			 * Relationnal operators for stack
			 *
			 * Performs the appropriate comparison operation between lhs and rhs.
			 */

			bool operator==(const stack& rhs)
			{
				return (this->_container == rhs._container);
			}
			bool operator!=(const stack& rhs)
			{
				return (this->_container != rhs._container);
			}
			bool operator<(const stack& rhs)
			{
				return (this->_container < rhs._container);
			}
			bool operator>(const stack& rhs)
			{
				return (this->_container > rhs._container);
			}
			bool operator>=(const stack& rhs)
			{
				return (this->_container >= rhs._container);
			}
			bool operator<=(const stack& rhs)
			{
				return (this->_container <= rhs._container);
			}
	};
}

#endif
