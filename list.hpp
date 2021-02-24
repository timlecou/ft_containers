

#ifndef	LIST_HPP
# define LIST_HPP

#include <iostream>

namespace	ft
{
	/**
	 * Lists are sequence containers that allow constant time insert and
	 * erase operations anywhere within the sequence, and iteration in both directions.
	 */
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		private:
			struct	node
			{
				T					content;
				struct	node		*previous;
				struct	node		*next;
			};

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
			node				*_c_node;
			allocator_type		_c_allocator;
			size_type			_c_size;

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
				this->_c_node = this->_c_allocator.allocate(1);
				this->_c_allocator.construct(&this->_c_size->content, value_type());
				this->_c_node->next = this->_c_node;
				this->_c_node->previous = this->_c_node;
				this->_c_size = 0;
			}

			/**
			 * Fill constructor.
			 *
			 * Constructs a container with n elements. Each element is a copy of val.
			 * @n : Initial container size.
			 * @val : Value to fill the container with.
			 * @alloc : Allocator object.
			 */
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			{
				this->_c_allocator = alloc;
				this->_c_node = this->_c_allocator.allocate(n);
				for (size_type i = 0; i < n; ++i)
					this->_c_allocator.construct(&this->_c_node->content, val);
				this->_c_size = n;
			}

			/**
			 * Test whether container is empty.
			 *
			 * Returns whether the list container is empty.
			 * @return : true if the container size is 0, false otherwise.
			 */
			bool	empty (void) const
			{
				return (this->_c_size > 0);
			}

			/**
			 * Return size.
			 *
			 * Returns the number of elements in the list container.
			 * @return : The number of elements in the container.
			 */
			size_type size (void) const
			{
				return (this->_c_size);
			}
	};
}

#endif
