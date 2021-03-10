#ifndef VECTOR_HPP
# define VECTOR_HPP
# include "vectorIterators.hpp"

/**
 * The namespace "ft" contains the Vector class
 */
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public:
			typedef	T										value_type;
			typedef	Alloc									allocator_type;
			typedef	T										&reference;
			typedef	T	const								&const_reference;
			typedef	T*										pointer;
			typedef	T*	const								const_pointer;
			typedef	vectorIterator<T>					iterator;
			typedef	vectorConstIterator<T>				const_iterator;
			typedef vectorReverseIterator<T>			reverse_iterator;
			typedef	ptrdiff_t							difference_type;
			typedef	size_t								size_type;

		protected:
			value_type		*_c_container;
			allocator_type 	_c_allocator;
			size_type		_c_size;
			size_type		_c_capacity;

		private:
			void			realloc(size_type new_capacity)
			{
				value_type	*tmp;

				if (new_capacity > max_size())
					throw std::length_error("vector::resize");
				tmp = this->_c_allocator.allocate(new_capacity);
				for (size_type i = 0; i < this->_c_size; i++)
					tmp[i] = this->_c_container[i];
				for (size_type j = 0; j < this->_c_size; j++)
					this->_c_allocator.destroy(&this->_c_container[j]);
				this->_c_container = tmp;
				this->_c_capacity = new_capacity;
			}

		public:

		/**
		 * Empty container constructor
		 *
		 * Constructs an empty container, with no elements.
		 * @param alloc : Allocator object
		 */
		explicit	vector (const allocator_type& alloc = allocator_type())
		{
			this->_c_allocator = alloc;
			this->_c_container = NULL;
			this->_c_size = 0;
			this->_c_capacity = 0;
		}

		/**
		 * Fill constructor
		 *
		 * Constructs a container with n elements. Each element is a copy of val.
		 *
		 * @param n : Initial container size
		 * @param val : Value to fill the container with
		 * @param alloc : Allocator object
		 */
		explicit	vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _c_allocator(alloc)
		{
			this->_c_size = 0;
			this->_c_container = this->_c_allocator.allocate(n);
			this->_c_capacity = n;
			assign(n, val);
		}

		/**
		 * Range constructor.
		 *
		 * Constructs a container with as many elements as the range [first,last),
		 * with each element constructed from its corresponding element in that range, in the same order.
		 *
		 * @first/@last : Input iterators to the initial and final positions in a range.
		 * @alloc : Allocator object.
		 */
		template <class InputIterator>
		vector (InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()): _c_allocator(alloc)
		{
			this->_c_size = 0;
			this->_c_container = this->_c_allocator.allocate(1);
			assign(first, last);
		}

		/**
		 * Copy constructor.
		 *
		 * Constructs a container with a copy of each of the elements in x, in the same order.
		 *
		 * @x : Another vector object of the same type (with the same class template
		 * arguments T and Alloc), whose contents are either copied or acquired.
		 */
		vector (const vector& x)
		{
			this->_c_size = 0;
			this->_c_container = this->_c_allocator.allocate(1);
			assign(x.begin(), x.end());
		}

		/**
		 * Destructor of the container
		 */
		~vector (void)
		{
			clear();
		}

		vector& operator= (const vector& x)
		{
			this->_c_container = x._c_container;
			this->_c_size = x.size();
			return (*this);
		}

	//ITERATORS

		/**
		 * Return iterator to beginning.
		 *
		 * Returns an iterator pointing to the first element in the vector.
		 */
		iterator begin (void)
		{
			return (iterator(this->_c_container));
		}
		
		/**
		 * Return const iterator to beginning.
		 *
		 * Returns an const iterator pointing to the first element in the vector.
		 */
		const_iterator begin (void) const
		{
			return (const_iterator(this->_c_container));
		}

		/**
		 * Return iterator to end.
		 *
		 * Returns an iterator pointing to the last element in the vector.
		 */
		iterator end (void)
		{
			return (iterator(this->_c_container + this->_c_size));
		}
		
		/**
		 * Return const iterator to last.
		 *
		 * Returns an const iterator pointing to the last element in the vector.
		 */
		const_iterator end (void) const
		{

			return (const_iterator(this->_c_container + this->_c_size));
		}

		/**
		 * Return a reverse iterator to reverse beginning.
		 *
		 * Returns a reverse iterator pointing to the last element in the vector.
		 */
		reverse_iterator rbegin (void)
		{
			return (reverse_iterator(this->_c_container + this->_c_size - 1));
		}

		/**
		 * Return a const reverse iterator to reverse beginning.
		 *
		 * Returns a const reverse iterator pointing to the last element in the vector.
		 */
//		const_reverse_iterator rbegin (void) const
//		{
//			return (reverse_iterator(this->_c_container + this->_c_size - 1));
//		}

		/**
		 * Return a reverse iterator to reverse end.
		 *
		 * Returns a reverse iterator pointing to the theoretical element
		 * preceding the first element in the vector.
		 */
		reverse_iterator rend (void)
		{
			return (reverse_iterator(this->_c_container - 1));
		}

		/**
		 * Return a const reverse iterator to reverse end.
		 *
		 * Returns a const reverse iterator pointing to the theoretical element
		 * preceding the first element in the vector.
		 */
//		const_reverse_iterator rend (void) const
//		{
//			return (reverse_iterator(this->_c_container - 1));
//		}


	//CAPACITY METHODS

		/**
		 * Returns the number of elements in the vector.
		 *
		 * @return : The number of elements in the container.
		 */
		size_type	size (void) const
		{
			return (this->_c_size);
		}

		/**
		 * Return maximum size.
		 *
		 * Returns the maximum number of elements that the vector can hold.
		 *
		 * @return : The maximum number of elements a vector container can hold as content.
		 */
		size_type max_size (void) const
		{
			return (this->_c_allocator.max_size());
		}

		/**
		 * Change size.
		 *
		 * Resizes the container so that it contains n elements.
		 *
		 * @param n : New container size, expressed in number of elements.
		 * @param val : Object whose content is copied to the added elements in case
		 * that n is greater than the current container size.
		 */
		void resize (size_type n, value_type val = value_type())
		{
			if (n < this->_c_size)
				while (this->_c_size != n)
					pop_back();
			else
				while (this->_c_size != n)
					push_back(val);
		}

		/**
		 * Return size of allocated storage capacity.
		 *
		 * Returns the size of the storage space currently allocated for
		 * the vector, expressed in terms of elements.
		 *
		 * @return : The size of the currently allocated storage capacity
		 * in the vector, measured in terms of the number elements it can hold.
		 */
		size_type capacity() const
		{
			return (this->_c_capacity);
		}

		/**
		 * Test whether vector is empty
		 *
		 * Returns whether the vector is empty.
		 *
		 * @return : true if the container size is 0, false otherwise.
		 */
		bool	empty (void) const
		{
			return (this->_c_size == 0);
		}

		/**
		 * Request a change in capacity.
		 *
		 * Requests that the vector capacity be at least enough to contain n elements.
		 *
		 * @n : Minimum capacity for the vector.
		 */
		void reserve (size_type n)
		{
			if (n == 0)
				realloc(1);
			if (n > this->_c_size)
				realloc(n);
		}

	//ELEMENT ACCESS METHODS

		/**
		 * Access element
		 *
		 * Returns a reference to the element at position n in the vector container.
		 *
		 * @param n : Position of an element in the container.
		 * @return : The element at the specified position in the vector.
		 */
		reference operator[] (size_type n)
		{
			return (this->_c_container[n]);
		}

		/**
		 * Access element
		 *
		 * Returns a const reference to the element at position n in the vector container.
		 *
		 * @param n : Position of an element in the container.
		 * @return : The element at the specified position in the vector.
		 */
		const_reference operator[] (size_type n) const
		{
			return (this->_c_container[n]);
		}

		/**
		 * Access element.
		 *
		 * Returns a reference to the element at position n in the vector.
		 *
		 * @param n : Position of an element in the container.
		 * @return : The element at the specified position in the container.
		 */
		reference at (size_type n)
		{
			return (this->_c_container[n]);
		}

		/**
		 * Access element.
		 *
		 * Returns a const reference to the element at position n in the vector.
		 *
		 * @param n : Position of an element in the container.
		 * @return : The element at the specified position in the container.
		 */
		const_reference at (size_type n) const
		{
			return (this->_c_container[n]);
		}

		/**
		 * Access first element
		 *
		 * Returns a reference to the first element in the vector.
		 *
		 * @return : A reference to the first element in the vector container.
		 */
		reference front (void)
		{
			return (this->_c_container[0]);
		}

		/**
		 * Access first element
		 *
		 * Returns a const reference to the first element in the vector.
		 *
		 * @return : A reference to the first element in the vector container.
		 */
		const_reference front (void) const
		{
			return (this->_c_container[0]);
		}

		/**
		 * Access last element
		 *
		 * Returns a reference to the last element in the vector.
		 *
		 * @return : A reference to the last element in the vector container.
		 */
		reference back (void)
		{
			return (this->_c_container[this->_c_size - 1]);
		}

		/**
		 * Access last element
		 *
		 * Returns a const reference to the last element in the vector.
		 * @return : A reference to the last element in the vector container.
		 */
		const_reference back (void) const
		{
			return (this->_c_container[this->_c_size - 1]);
		}


	//MODIFIERS METHODS
		
		/**
		 * Assign : Fill version
		 *
		 * Assigns new contents to the vector, replacing its current
		 * contents, and modifying its size accordingly.
		 *
		 * The new contents are n elements, each initialized to a copy of val.
		 *
		 * @param n : New size for the container
		 * @param val : Value to fill the container with.
		 */
		void assign (size_type n, const value_type& val)
		{
			clear();
			reserve(n);
			for (size_type j = 0; j < n; ++j)
				push_back(val);
		}

		/**
		 * Assign : Range version.
		 *
		 * Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		 *
		 * The new contents are elements constructed from each of the elements
		 * in the range between first and last, in the same order.
		 *
		 * @first/@last : Input iterators to the initial and final positions in a sequence.
		 */
		template <class InputIterator>
		void assign (InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
		{
			int		i = 0;

			for (InputIterator tmp = first; tmp != last; tmp++)
				i++;
			clear();
			reserve(i);
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		/**
		 * Add element at the end.
		 *
		 * Adds a new element at the end of the vector, after its current last element.
		 *
		 * @val : Value to be copied (or moved) to the new element.
		 */
		void push_back (const value_type& val)
		{
			if (this->_c_capacity <= this->_c_size)
				reserve(this->_c_size * 2);
			this->_c_allocator.construct(&this->_c_container[this->_c_size], val);
			this->_c_size++;
		}

		/**
		 * Delete last element.
		 *
		 * Removes the last element in the vector, effectively reducing the container size by one.
		 */
		void pop_back (void)
		{
			this->_c_allocator.destroy(&this->_c_container[this->_c_size]);
			this->_c_size--;
		}

		/**
		 * Insert elements. (single element)
		 *
		 * The vector is extended by inserting new elements before the element at the specified position,
		 * effectively increasing the container size by the number of elements inserted.
		 *
		 * @param position : Position in the vector where the new elements are inserted.
		 * @param val : Value to be copied (or moved) to the inserted elements.
		 * @return : An iterator that points to the first of the newly inserted elements.
		 */
		iterator insert (iterator position, const value_type& val)
		{
			size_type	pos = 0;
			size_type	end = this->_c_size;

			for (iterator it = begin(); it != position; it++)
				pos++;
			if (this->_c_size <= this->_c_capacity)
				reserve(this->_c_size + 1);
			while (end > pos)
			{
				this->_c_allocator.destroy(&this->_c_container[end]);
				this->_c_allocator.construct(&this->_c_container[end], this->_c_container[end - 1]);
				end--;
			}
			this->_c_size++;
			this->_c_allocator.construct(&this->_c_container[end], val);
			return (begin() + end);
		}

		/**
		 * Insert elements. (fill)
		 *
		 * The vector is extended by inserting new elements before the element at the specified position,
		 * effectively increasing the container size by the number of elements inserted.
		 *
		 * @position : Position in the vector where the new elements are inserted.
		 * @n : Number of elements to insert.
		 * @val : Value to be copied (or moved) to the inserted elements.
		 */
		void insert (iterator position, size_type n, const value_type& val)
		{
			while (n--)
				position = insert(position, val);
		}

		/**
		 * Insert elements. (range)
		 *
		 * The vector is extended by inserting new elements before the element at the specified position,
		 * effectively increasing the container size by the number of elements inserted.
		 *
		 * @position : Position in the vector where the new elements are inserted.
		 * @first : Iterators specifying a range of elements.
		 * @last : Iterators specifying a range of elements.
		 */
		template <class InputIterator>
   		void insert (iterator position, InputIterator first, typename ft::enable_if<!is_integral<InputIterator>::value, InputIterator>::type last)
		{
			while (first != last)
			{
				position = insert(position, *first++);
				position++;
			}
		}

		/**
		 * Erase elements.
		 *
		 * Removes from the vector either a single element (position) or a range of elements ([first,last)).
		 *
		 * @position : Iterator pointing to a single element to be removed from the vector.
		 * @return : An iterator pointing to the new location of the element
		 * that followed the last element erased by the function call.
		 */
		iterator erase (iterator position)
		{
			iterator	ret(position);
			iterator	save_end(end());

			while (position  + 1 != save_end)
				*position++ = *(position + 1);
			this->_c_allocator.destroy(&*position);
			--this->_c_size;
			return (ret);
		}

		/**
		 * Erase elements.
		 *
		 * Removes from the vector either a single element (position) or a range of elements ([first,last)).
		 * @first : Iterators specifying a range within the vector] to be removed: [first,last).
		 * @last : Iterators specifying a range within the vector] to be removed: [first,last).
		 * @return : An iterator pointing to the new location of the element
		 * that followed the last element erased by the function call.
		 */
		iterator erase (iterator first, iterator last)
		{
			iterator	ret(first);
			iterator	save_end(end());

			while (last != save_end)
				*first++ = *last++;
			while (first != save_end)
			{
				this->_c_allocator.destroy(&*(first++));
				this->_c_size--;
			}
			return (ret);
		}

		/**
		 * Swap content.
		 *
		 * Exchanges the content of the container by the content of x,
		 * which is another vector object of the same type.
		 * @x : Another vector container of the same type whose content is
		 * swapped with that of this container.
		 */
		void swap (vector& x)
		{
			vector		tmp;
			size_type	size = x.size();

			tmp.reserve(size);
			for (size_type i = 0; i < size; i++)
				tmp.push_back(x[i]);
			while (x.size() > 0)
				x.pop_back();
			for (size_type j = 0; j < this->_c_size; j++)
				x.push_back(this->_c_container[j]);
			while (this->_c_size > 0)
				pop_back();
			for (size_type k = 0; k < tmp.size(); k++)
				push_back(tmp[k]);
		}

		/**
		 * Clear content.
		 *
		 * Removes all elements from the vector (which are destroyed),
		 * leaving the container with a size of 0.
		 */
		void clear (void)
		{
			erase(begin(), end());
		}

		/**
		 * Exchanges contents of vectors.
		 *
		 * The contents of container x are exchanged with those of y.
		 * @x/@y : vector containers of the same type.
		 */
		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			vector	tmp = x;

			x = y;
			y = tmp;
		}

	/**
	 * Relational operators for vector.
	 *
	 * Performs the appropriate comparison operation between the vector containers lhs and rhs.
	 */
		bool operator== (const vector<T,Alloc>& rhs)
		{
			if (this->_c_size != rhs.size())
				return (false);

			iterator	it1 = begin();
			iterator	it2 = rhs.begin();
			while (it1 != end() || it2 != rhs.end())
			{
				if (*it1 != *it2)
					return (false);
				it1++;
				it2++;
			}
			return (true);
		}

		bool operator!= (const vector<T,Alloc>& rhs)
		{
			iterator	it1 = begin();
			iterator	it2 = rhs.begin();
			while (it1 != end() || it2 != rhs.end())
			{
				if (*it1 == *it2)
					return (false);
				it1++;
				it2++;
			}
			return (true);
		}

		bool operator< (const vector<T,Alloc>& rhs)
		{
			iterator	it1 = begin();
			iterator	it2 = rhs.begin();
			while (it1 != end() || it2 != rhs.end())
			{
				if (*it1 < *it2)
					return (true);
				it1++;
				it2++;
			}
			return (false);
		}

		bool operator<= (const vector<T,Alloc>& rhs)
		{
			iterator	it1 = begin();
			iterator	it2 = rhs.begin();
			while (it1 != end() || it2 != rhs.end())
			{
				if (*it1 > *it2)
					return (false);
				it1++;
				it2++;
			}
			return (true);
		}

		bool operator> (const vector<T,Alloc>& rhs)
		{
			iterator	it1 = begin();
			iterator	it2 = rhs.begin();
			while (it1 != end() || it2 != rhs.end())
			{
				if (*it1 > *it2)
					return (true);
				it1++;
				it2++;
			}
			return (false);
		}

		bool operator>= (const vector<T,Alloc>& rhs)
		{
			iterator	it1 = begin();
			iterator	it2 = rhs.begin();
			while (it1 != end() || it2 != rhs.end())
			{
				if (*it1 < *it2)
					return (false);
				it1++;
				it2++;
			}
			return (true);
		}

	};
}

#endif
