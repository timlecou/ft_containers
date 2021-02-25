

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
			node					*_c_node;
			allocator_type			_c_value_allocator;
			std::allocator<node>	_c_node_allocator;
			size_type				_c_size;

		public:

			/**
			 * Empty container constructor (Default cnstructor).
			 *
			 * Constructs an empty container, with no elements.
			 * @alloc : Allocator object.
			 */
			explicit list (const allocator_type& alloc = allocator_type()) : _c_value_allocator(alloc)
			{
				this->_c_node = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&this->_c_node->content, value_type());
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
			explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _c_value_allocator(alloc)
			{
				node	*tmp;
				tmp = this->_c_node;
				for (size_type i = 0; i < n; ++i)
				{
					this->_c_node = this->_c_node_allocator.allocate(1);
					this->_c_value_allocator.construct(&this->_c_node->content, val);
					this->_c_node->next->previous = this->_c_node;
					this->_c_node = this->_c_node->next;
				}
				this->_c_node->previous = tmp;
				this->_c_size = n;
			}

			//CAPACITY METHODS

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

			/**
			 * Return maximum size.
			 *
			 * Returns the maximum number of elements that the list container can hold.
			 * @return : The maximum number of elements the object can hold as content.
			 */
			size_type max_size (void) const
			{
				return (this->_c_node_allocator.max_size());
			}

			//ELEMENT ACCESS METHODS
			
			/**
			 * Access first element.
			 *
			 * Returns a reference to the first element in the list container.
			 * @return : A reference to the first element in the list container.
			 */
			reference front (void)
			{
				return (this->_c_node->next->content);
			}

			/**
			 * Access first element.
			 *
			 * Returns a const reference to the first element in the list container.
			 * @return : A const reference to the first element in the list container.
			 */
			const_reference front (void) const
			{
				return (this->_c_node->next->content);
			}

			/**
			 * Access last element.
			 *
			 * Returns a reference to the last element in the list container.
			 * @return : A reference to the last element in the list container.
			 */
			reference back (void)
			{
				return (this->_c_node->previous->content);
			}
			
			/**
			 * Access last element.
			 *
			 * Returns a const reference to the last element in the list container.
			 * @return : A const reference to the flast element in the list container.
			 */
			const_reference back (void) const
			{
				return (this->_c_node->previous->content);
			}

			//MODIFIERS METHODS
			
			void assign (size_type n, const value_type& val)
			{
				(void)n;
				(void)val;
			}

			/**
			 * Add element at the end.
			 *
			 * Adds a new element at the end of the list container, after its current last element.
			 * @val : Value to be copied (or moved) to the new element.
			 */
			void push_back (const value_type& val)
			{
				node	*new_node;

				new_node = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&new_node->content, val);
				new_node->next = this->_c_node;
				new_node->previous = this->_c_node->previous;
				this->_c_node->previous->next = new_node;
				this->_c_node->previous = new_node;
				this->_c_size++;
			}

			/**
			 * Add element at beginning.
			 *
			 * Adds a new element at beginning of the list container, before its current first element.
			 * @val : Value to be copied (or moved) to the new element.
			 */
			void push_front (const value_type& val)
			{
				node	*new_node;

				new_node = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&new_node->content, val);
				new_node->next = this->_c_node->next;
				new_node->previous = this->_c_node;
				this->_c_node->next->previous = new_node;
				this->_c_node->next = new_node;
				this->_c_size++;
			}

			/**
			 * Delete first element.
			 *
			 * Removes the first element in the list container, effectively reducing its size by one.
			 */
			void pop_front (void)
			{
				node	*tmp;

				tmp = this->_c_node->next;
				this->_c_node->next = this->_c_node->next->next;
				
				//	destroying/freeing the element and its value
				this->_c_value_allocator.destroy(&tmp->content);
				this->_c_node_allocator.deallocate(tmp, 1);

				this->_c_size--;
			}

			/**
			 * Delete last element.
			 *
			 * Removes the last element in the list container, effectively reducing its size by one.
			 */
			void pop_back (void)
			{
				node	*tmp;

				tmp = this->_c_node->previous;
				this->_c_node->previous = this->_c_node->previous->previous;
				this->_c_node->previous->previous->next = this->_c_node;
				
				//	destroying/freeing the element and its value
				this->_c_value_allocator.destroy(&tmp->content);
				this->_c_node_allocator.deallocate(tmp, 1);

				this->_c_size--;
			}
	};
}

#endif
