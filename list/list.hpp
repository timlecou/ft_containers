

#ifndef	LIST_HPP
# define LIST_HPP
# include "listIterators.hpp"
# include <cstddef>

namespace	ft
{
	/**
	 * Lists are sequence containers that allow constant time insert and
	 * erase operations anywhere within the sequence, and iteration in both directions.
	 */
	template < class T, class Alloc = std::allocator<T> >
	class list
	{
		public:
			typedef	T											value_type;
			typedef	Alloc										allocator_type;
			typedef	value_type &								reference;
			typedef	value_type const &							const_reference;
			typedef	value_type *								pointer;
			typedef	value_type const *							const_pointer;
			typedef	ft::listIterator<T>							iterator;
			typedef	ft::listConstIterator<T>					const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::const_reverse_iterator<const_iterator>	const_reverse_iterator;
			typedef	ptrdiff_t									difference_type;
			typedef	size_t										size_type;

		protected:
			node<T>						*_c_node;
			allocator_type				_c_value_allocator;
			std::allocator<node<T> >	_c_node_allocator;
			size_type					_c_size;

		public:

			/**
			 * Empty container constructor (Default constructor).
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
				this->_c_node = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&this->_c_node->content, value_type());
				this->_c_node->next = this->_c_node;
				this->_c_node->previous = this->_c_node;
				this->_c_size = 0;
				assign(n, val);
			}

			/**
			 * Range constructor.
			 *
			 * Constructs a container with as many elements as the range [first,last), with
			 * each element constructed from its corresponding element in that range, in the same order.
			 * @first/@last : Input iterators to the initial and final positions in a range.
			 * @alloc : Allocator object.
			 */
			template <class InputIterator>
			list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()): _c_value_allocator(alloc)
			{
				this->_c_node = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&this->_c_node->content, value_type());
				this->_c_node->next = this->_c_node;
				this->_c_node->previous = this->_c_node;
				this->_c_size = 0;
				assign(first, last);
			}

			/**
			 * Copy constructor.
			 *
			 * Constructs a container with a copy of each of the elements in x, in the same order.
			 * @x : Another list object of the same type (with the same class
			 * template arguments), whose contents are either copied or acquired.
			 */
			list (const list& x)
			{
				this->_c_node = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&this->_c_node->content, value_type());
				this->_c_node->next = this->_c_node;
				this->_c_node->previous = this->_c_node;
				this->_c_size = 0;
				assign(x.begin(), x.end());
			}

			/**
			 * Destructor.
			 */
			virtual	~list (void)
			{
				clear();
			}

			/**
			 * Assign new content.
			 *
			 * Assigns new contents to the container, replacing its current contents,
			 * and modifying its size accordingly.
			 * @x : A list object of the same type.
			 * @return : *this.
			 */
			list& operator= (const list& x)
			{
				assign(x.begin(), x.end());
				return (*this);
			}

			//ITERATORS

			/**
		 	* Return iterator to beginning.
		 	*
		 	* Returns an iterator pointing to the first element in the list.
		 	*/
			iterator	begin (void)
			{
				return (iterator(this->_c_node->next));
			}

			/**
			 * Return iterator to beginning.
			 *
			 * Returns an iterator pointing to the first element in the list.
			 */
			const_iterator	begin (void) const
			{
				return (const_iterator(this->_c_node->next));
			}

			/**
			 * Return iterator to end.
			 *
			 * Returns an iterator pointing to the last element in the list.
			 */
			iterator end (void)
			{
				return (iterator(this->_c_node));
			}

			/**
		 	* Return iterator to end.
			 *
			 * Returns an iterator pointing to the last element in the list.
			 */
			const_iterator end (void) const
			{
				return (const_iterator(this->_c_node));
			}

			/**
			 * Return reverse iterator to reverse beginning.
			 *
			 * Returns a reverse iterator pointing to the last element in the container.
			 *
			 * @return : A reverse iterator to the reverse beginning of the sequence container.
			 */
			reverse_iterator rbegin (void)
			{
				return (reverse_iterator(end()));
			}

			/**
			 * Return const reverse iterator to reverse beginning.
			 *
			 * Returns a const reverse iterator pointing to the last element in the container.
			 *
			 * @return : A const reverse iterator to the reverse beginning of the sequence container.
			 */
			const_reverse_iterator rbegin (void) const
			{
				return (const_reverse_iterator(end()));
			}

			/**
			 * Return reverse iterator to reverse end.
			 *
			 * Returns a reverse iterator pointing to the first element in the container.
			 *
			 * @return : A reverse iterator to the reverse end of the sequence container.
			 */
			reverse_iterator rend (void)
			{
				return (reverse_iterator(begin()));
			}

			/**
			 * Return const reverse iterator to reverse end.
			 *
			 * Returns a const reverse iterator pointing to the first element in the container.
			 *
			 * @return : A const reverse iterator to the reverse end of the sequence container.
			 */
			const_reverse_iterator rend (void) const
			{
				return (const_reverse_iterator(begin()));
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
				if (this->_c_size > 0)
					return (false);
				else
					return (true);
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
			
			/**
			 * Assign new content to container.
			 *
			 * Assigns new contents to the list container, replacing its
			 * current contents, and modifying its size accordingly.
			 * @first/@last : Input iterators to the initial and final positions in a sequence.
			 */
			template <class InputIterator>
			void assign (InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
			{
				clear();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
			}

			/**
			 * Assign new content to container. (fill)
			 *
			 * Assigns new contents to the list container, replacing its
			 * current contents, and modifying its size accordingly.
			 * @n : New size for the container.
			 * @val : Value to fill the container with.
			 */
			void assign (size_type n, const value_type& val)
			{
				size_type	i = 0;

				clear();
				while (i++ < n)
					push_back(val);
			}

			/**
			 * Add element at beginning.
			 *
			 * Adds a new element at beginning of the list container, before its current first element.
			 * @val : Value to be copied (or moved) to the new element.
			 */
			void push_front (const value_type& val)
			{
				node<T>	*new_node;

				//allocating/constructing new element
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
				node<T>	*tmp;

				tmp = this->_c_node->next;
				this->_c_node->next = this->_c_node->next->next;
				
				//	destroying/freeing the element and its value
				this->_c_value_allocator.destroy(&tmp->content);
				this->_c_node_allocator.deallocate(tmp, 1);

				this->_c_size--;
			}

			/**
			 * Add element at the end.
			 *
			 * Adds a new element at the end of the list container, after its current last element.
			 * @val : Value to be copied (or moved) to the new element.
			 */
			void push_back (const value_type& val)
			{
				node<T>	*new_node;

				//allocating/constructing new element
				new_node = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&new_node->content, val);

				new_node->next = this->_c_node;
				new_node->previous = this->_c_node->previous;
				this->_c_node->previous->next = new_node;
				this->_c_node->previous = new_node;
				this->_c_size++;
			}

			/**
			 * Delete last element.
			 *
			 * Removes the last element in the list container, effectively reducing its size by one.
			 */
			void pop_back (void)
			{
				node<T>	*tmp;

				tmp = this->_c_node->previous->previous;

				//	destroying/freeing the element and its value
				this->_c_value_allocator.destroy(&this->_c_node->previous->content);
				this->_c_node_allocator.deallocate(this->_c_node->previous, 1);

				tmp->next = this->_c_node;
				this->_c_node->previous = tmp;
				
				this->_c_size--;
			}

			/**
			 * Insert elements. (single element)
			 *
			 * The container is extended by inserting new elements before the element at the specified position.
			 * @position : Position in the container where the new elements are inserted.
			 * @val : Value to be copied (or moved) to the inserted elements.
			 * @return : an iterator to the inserted element.
			 */
			iterator insert (iterator position, const value_type& val)
			{
				node<T>	*new_node;
				node<T>	*tmp;
				size_type	pos = 0;

				tmp = this->_c_node->next;

				//find the node where we have to insert the elements
				for (iterator it = this->begin(); it != position; it++)
				{
				   	tmp = tmp->next;
					pos++;
				}

				//allocating/constructing new element
				new_node = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&new_node->content, val);

				//insertingthe new element into the list
				tmp->previous->next = new_node;
				new_node->previous = tmp->previous;
				tmp->previous = new_node;
				new_node->next = tmp;

				this->_c_size++;

				iterator	ret = begin();
				while (pos--)
					ret++;
				return (ret);
			}

			/**
			 * Insert elements. (fill)
			 *
			 * The container is extended by inserting new elements before the element at the specified position.
			 * @position : Position in the container where the new elements are inserted.
			 * @n : Number of elements to insert.
			 * @val : Value to be copied (or moved) to the inserted elements.
			 */
			void insert (iterator position, size_type n, const value_type& val)
			{
				while (n--)
				{
					insert(position, val);
				}
			}

			 /**
			  * Insert elements. (range)
			  *
			  * The container is extended by inserting new elements before the element at the specified position.
			  * @position : Position in the container where the new elements are inserted.
			  * @first/@last : Iterators specifying a range of elements.
			  */
			template <class InputIterator>
			void insert (iterator position, InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
			{
				while (first != last)
				{
					insert(position, *first++);
				}
			}

			 /**
			  * Erase elements. (single)
			  *
			  * Removes from the list container either a single element (position) or a range of elements ([first,last)).
			  * @position : Iterator pointing to a single element to be removed from the list.
			  * @return : An iterator pointing to the element that followed the last element erased by the function call.
			  */
			iterator erase (iterator position)
			{
				node<T>	*tmp = this->_c_node->next;

				for (iterator it = begin(); it != position; it++)
					tmp = tmp->next;

				tmp->next->previous = tmp->previous;
				tmp->previous->next = tmp->next;

				this->_c_value_allocator.destroy(&tmp->content);
				this->_c_node_allocator.deallocate(tmp, 1);

				this->_c_size--;

				return (--position);
			}

			/**
			 * Erase elements. (range)
			 *
			 * Removes from the list container either a single element (position) or a range of elements ([first,last)).
			 * @first/@last : Iterators specifying a range within the list to be removed.
			 * @return : An iterator pointing to the element that followed the last element erased by the function call.
			 */
			iterator erase (iterator first, iterator last)
			{
				while (first != last)
					erase(first++);
				return (first);
			}


			/**
			 * Swap content.
			 *
			 * Exchanges the content of the container by the content of x, which is another list of the same type.
			 * @x : Another list container of the same type.
			 */
			void swap (list& x)
			{
				node<T>		*tmp_node = this->_c_node;
				size_type	tmp_size = this->_c_size;

				//swaping the sizes
				this->_c_size = x.size();
				x._c_size = tmp_size;

				//swaping the lists
				this->_c_node = x._c_node;
				x._c_node = tmp_node;
			}

			/**
			 * Change size.
			 *
			 * Resizes the container so that it contains n elements.
			 * @n : New container size, expressed in number of elements.
			 * @val : Object whose content is copied to the added elements in case
			 * that n is greater than the current container size.
			 */
			void resize (size_type n, value_type val = value_type())
			{
				while (n < this->_c_size)
					pop_back();
				while (n > this->_c_size)
					push_back(val);
			}

			/**
			 * Clear content.
			 *
			 * Removes all elements from the list container (which are destroyed),
			 * and leaving the container with a size of 0.
			 */
			void clear (void)
			{
				while (this->_c_size)
					pop_back();
			}

		//OPERATIONS

			/**
			 * Transfer elements from list to list. (entire list)
			 *
			 * Transfers elements from x into the container, inserting them at position.
			 * @position : Position within the container where the elements of x are inserted.
			 * @x : A list object of the same type.
			 */
			void splice (iterator position, list& x)
			{
				splice(position, x, x.begin(), x.end());
			}

			/**
			 * Transfer elements from list to list. (single element)
			 *
			 * Transfers elements from x into the container, inserting them at position.
			 * @position : Position within the container where the elements of x are inserted.
			 * @x : A list object of the same type.
			 * @i : Iterator to an element in x.
			 */
			void splice (iterator position, list& x, iterator i)
			{
				node<T>	*pos = reinterpret_cast<node<T> *>(&*position);
				node<T>	*pos_i = reinterpret_cast<node<T> *>(&*i);

				pos_i->next->previous = pos_i->previous;
				pos_i->previous->next = pos_i->next;
	
				pos_i->next = pos;
				pos_i->previous = pos->previous;

				pos->previous->next = pos_i;
				pos->previous = pos_i;

				++this->_c_size;
				--x._c_size;
			}

			/**
			 * Transfer elements from list to list. (element range)
			 *
			 * Transfers elements from x into the container, inserting them at position.
			 * @position : Position within the container where the elements of x are inserted.
			 * @x : A list object of the same type.
			 * @first/@last : Iterators specifying a range of elements in x.
			 */
			void splice (iterator position, list& x, iterator first, iterator last)
			{
				while (first != last)
					splice(position, x, first++);
			}

			/**
			 * Remove elements with specific value.
			 *
			 * Removes from the container all the elements that compare equal to val.
			 * @val : Value of the elements to be removed.
			 */
			void remove (const value_type& val)
			{
				for (iterator it = begin(); it != end(); it++)
					if (*it == val)
						erase(it);
			}

			/**
			 * Remove elements fullfilling condition.
			 *
			 * Removes from the container all the elements for which Predicate pred returns true.
			 * @pred : Unary predicate that, taking a value of the same type as
			 * those contained in the forward_list object, returns true for those
			 * values to be removed from the container, and false for those remaining.
			 */
			template <class Predicate>
			void remove_if (Predicate pred)
			{
				for (iterator it = begin(); it != end(); it++)
					if (pred(*it) == true)
						erase(it);
			}

			/**
			 * Remove duplicate values.
			 *
			 * This version removes all but the first element
			 * from every consecutive group of equal elements in the container.
			 */
			void unique (void)
			{
				iterator	it1 = begin();

				it1++;
				for (iterator it = begin(); it != end(); it1++)
				{
					if (*it == *it1)
						it = erase(it1);
					else
						it++;
				}
			}

			/**
			 * Remove duplicate values.
			 *
			 * This version takes as argument a specific comparison
			 * function that determine the "uniqueness" of an element.
			 * @binary_pred : Binary predicate that, taking two values of the
			 * same type than those contained in the list, returns true to remove
			 * the element passed as first argument from the container, and false otherwise.
			 */
			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
				iterator	it1 = begin();

				it1++;
				for (iterator it = begin(); it != end(); it1++)
				{
					if (binary_pred(*it, *it1))
						it = erase(it1);
					else
						it++;
				}
			}

			/**
			 * Merge sorted lists.
			 *
			 * Merges x into the list by transferring all of
			 * its elements at their respective ordered positions into
			 * the container (both containers shall already be ordered).
			 * @x : A list object of the same type.
			 */
			void merge (list& x)
			{
				if (&x == this || x.empty())
					return ;
				insert(begin(), x.begin(), x.end());
				sort();
				x.clear();
			}

			/**
			 * Merge sorted lists.
			 *
			 * Merges x into the list by transferring all of
			 * its elements at their respective ordered positions into
			 * the container (both containers shall already be ordered).
			 * @x : A list object of the same type.
			 * @comp : Binary predicate that, taking two values of the same
			 * type than those contained in the list, returns true if the first
			 * argument is considered to go before the second in the strict weak
			 * ordering it defines, and false otherwise.
			 */
			template <class Compare>
			void merge (list& x, Compare comp)
			{
				if (&x == this || x.empty())
					return ;
				insert(begin(), x.begin(), x.end());
				sort(comp);
				x.clear();
			}

			/**
			 * Sort elements in container.
			 *
			 * Sorts the elements in the list, altering their position within the container.
			 */
			void sort (void)
			{
				iterator	it1 = begin();
				iterator	it2 = it1;
				iterator	beg = it1;
				iterator	en = end();

				++it2;
				while (it2 != en)
				{
					if (*it2 < *it1)
					{
						splice(it1, *this, it2);
						it1 = begin();
						it2 = it1;
					}
					else
						++it1;
					++it2;
				}
			}

			/**
			 * Sort elements in container.
			 *
			 * Sorts the elements in the list, altering their position within the container.
			 * @comp : Binary predicate that, taking two values of the same type
			 * of those contained in the list, returns true if the first argument
			 * goes before the second argument in the strict weak ordering it defines, and false otherwise.
			 */
			template <class Compare>
			void sort (Compare comp)
			{
				iterator	it1 = begin();
				iterator	it2 = it1;
				iterator	beg = it1;
				iterator	en = end();

				++it2;
				while (it2 != en)
				{
					if (comp(*it2, *it1))
					{
						splice(it1, *this, it2);
						it1 = begin();
						it2 = it1;
					}
					else
						++it1;
					++it2;
				}
			}

			/**
			 * Reverse the order of elements.
			 *
			 * Reverses the order of the elements in the list container.
			 */
			void reverse (void)
			{
				iterator it = end();
				iterator last = end();
				node<T>	 *tmp_node;
				node<T>	 *tmp_elem;

				do
				{
					tmp_node = reinterpret_cast<node<T> *>(&*it);
					tmp_elem = tmp_node->previous;
					tmp_node->previous = tmp_node->next;
					tmp_node->next = tmp_elem;
					++it;
				}
				while (it != last);
			}

			/**
			 * Exchanges the contents of two lists.
			 *
			 * The contents of container x are exchanged with those of y.
			 * Both container objects must be of the same type (same template parameters), although sizes may differ.
			 * @x/@y : list containers of the same type.
			 */
  			void swap (list<T,Alloc>& x, list<T,Alloc>& y)
			{
				list	tmp;

				tmp = x;
				x = y;
				y = tmp;
			}

		/**
		 * Relational operators for list.
		 *
		 * Performs the appropriate comparison operation between the list containers lhs and rhs.
		 */

			bool operator== (const list<T,Alloc>& rhs)
			{
				if (this->size() != rhs.size())
					return (false);
				list::iterator	it1 = this->begin();
				list::iterator	it2 = rhs.begin();
				while (it1 != this->end() || it2 != rhs.end())
				{
					if (*it1 != *it2)
						return (false);
					it1++;
					it2++;
				}
				return (true);
			}

			bool operator!= (const list<T,Alloc>& rhs)
			{
				if (*this == rhs)
					return (false);
				else
					return (true);
			}

			bool operator> (const list<T,Alloc>& rhs)
			{
				if (this->size() != rhs.size())
					return (false);
				list::iterator	it1 = this->begin();
				list::iterator	it2 = rhs.begin();
				while (it1 != this->end() || it2 != rhs.end())
				{
					if (*it1 > *it2)
						return (true);
					it1++;
					it2++;
				}
				return (false);
			}

			bool operator< (const list<T,Alloc>& rhs)
			{
				if (this->size() != rhs.size())
					return (false);
				list::iterator	it1 = this->begin();
				list::iterator	it2 = rhs.begin();
				while (it1 != this->end() || it2 != rhs.end())
				{
					if (*it1 < *it2)
						return (true);
					it1++;
					it2++;
				}
				return (false);
			}

			bool operator>= (const list<T,Alloc>& rhs)
			{
				if (this->size() != rhs.size())
					return (false);
				list::iterator	it1 = this->begin();
				list::iterator	it2 = rhs.begin();
				while (it1 != this->end() || it2 != rhs.end())
				{
					if (*it1 < *it2)
						return (false);
					it1++;
					it2++;
				}
				return (true);
			}

			bool operator<= (const list<T,Alloc>& rhs)
			{
				if (this->size() != rhs.size())
					return (false);
				list::iterator	it1 = this->begin();
				list::iterator	it2 = rhs.begin();
				while (it1 != this->end() || it2 != rhs.end())
				{
					if (*it1 > *it2)
						return (false);
					it1++;
					it2++;
				}
				return (true);
			}

	};
}

#endif
