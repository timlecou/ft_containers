

#ifndef	LIST_HPP
# define LIST_HPP

#include <iostream>

namespace	ft
{
	template < typename T >
	struct	Node
	{
		T			content;
		Node<T>		*previous;
		Node<T>		*next;

		Node (void)
		{
			content = T();
			previous = NULL;
			next = NULL;
		}
	};

	/**
	 * Lists are sequence containers that allow constant time insert and
	 * erase operations anywhere within the sequence, and iteration in both directions.
	 */
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef	T						value_type;
			typedef	Alloc					allocator_type;
			typedef	value_type &			reference;
			typedef	value_type const &		const_reference;
			typedef	value_type *			pointer;
			typedef	value_type const *		const_pointer;
			typedef	ptrdiff_t				difference_type;
			typedef	size_t					size_type;

		protected:
			Node<value_type>	*_c_begin;
			Node<value_type>	*_c_end;
			allocator_type		_c_allocator;
			size_type			_c_size;

		private:

			/**
			 * Initialise the linked list.
			 */
			void		init_linked_list(void)
			{
				this->_c_begin = new Node<value_type>();
				this->_c_end = this->_c_begin;
				this->bounds();
			}

			void		bounds(void)
			{
				this->_c_begin = this->_c_end;
				this->_c_end->previous = this->_c_begin;
				this->_c_end->next = this->_c_begin;
			}

		public:

			/**
			 * Empty container constructor (Default cnstructor).
			 *
			 * Constructs an empty container, with no elements.
			 * @alloc : Allocator object.
			 */
			explicit list (const allocator_type& alloc = allocator_type())
			{
				this->_c_allocator = alloc;
				this->_c_begin = NULL;
				this->_c_end = NULL;
				this->_c_size = 0;
				this->init_linked_list();
			}

			/**
			 * Fill constructor.
			 *
			 * Constructs a container with n elements. Each element is a copy of val.
			 * @n : Initial container size.
			 * @val : Value to fill the container with.
			 * @alloc : Allocator object.
			 */
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			{
				this->_allocator = alloc;
				this->_c_begin = NULL;
				this->_c_end = NULL;
				this->_c_size = 0;
				this->init_linked_list();
				this->assign(n, val);
			}
	};
}

#endif
