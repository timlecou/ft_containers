#include <iostream>

/**
 * The namespace "ft" contains the Vector class
 */
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{
	public:
		typedef	T				value_type;
		typedef	Alloc			allocator_type;
		typedef	T				&reference;
		typedef	T	const		&const_reference;
		typedef	T*				pointer;
		typedef	T*	const		const_pointer;
		typedef	ptrdiff_t		difference_type;
		typedef	size_t			size_type;

	protected:
		value_type		*_c_container;
		allocator_type 	_c_allocator;
		size_type		_c_size;
		size_type		_c_capacity;

	public:
		class	iterator
		{
			private:
				pointer	_i_container;

			public:

				/**
				 * Default constructor.
				 */
				explicit	iterator (void): _i_container(NULL)
				{
				}

				/**
				 * Assignation constructor.
				 *
				 * @container : the container to assign.
				 */
				explicit	iterator (pointer container): _i_container(container)
				{
				}

				/**
				 * Copy constructor.
				 *
				 * @it : the iterator to copy.
				 */
				iterator (const iterator &it): _i_container(it._i_container)
				{
				}

				//OPERATORS

				/**
				 * Assignation operator.
				 *
				 * Copies all the elements from x into the container.
				 * @param it : the iterator to assign.
				 * @return : *this.
				 */
				iterator &operator= (iterator const &it)
				{
					_i_container = it._i_container;
					return (*this);
				}

				/**
				 * Offset dereference operator.
				 *
				 * @return : the value of the dereferenced container.
				 */
				value_type	operator[] (size_type n) const { return (_i_container[n]); }

				/**
				 * Dereference operator.
				 *
				 * @return : the value of the dereferenced container.
				 */
				value_type	operator* (void) const { return (*_i_container); }

				/**
				 * Dereference operator.
				 *
				 * @return : the value of the dereferenced container.
				 */
				value_type	operator-> (void) const { return (_i_container); }

				/**
				 * Equality operator.
				 *
				 * @return : true if the 2 containers are equals, otherwise it returns false.
				 */
				bool	operator== (const iterator &it) const	{ return (it._i_container == _i_container); }

				/**
				 * Disequality operator.
				 *
				 * @return : true if the 2 containers are not equals, otherwise it returns false.
				 */
				bool	operator!= (const iterator &it) const	{ return (it._i_container != _i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A < B, otherwise it returns false.
				 */
				bool	operator< (const iterator &it) const { return (it._i_container < _i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A > B, otherwise it returns false.
				 */
				bool	operator> (const iterator &it) const { return (it._i_container < _i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A <= B, otherwise it returns false.
				 */
				bool	operator<= (const iterator &it) const { return (it._i_container < _i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A >= B, otherwise it returns false.
				 */
				bool	operator>= (const iterator &it) const { return (it._i_container < _i_container); }

				/**
				 * Incrementation operator.
				 *
				 * @n : the value to add.
				 */
				iterator &operator+= (int n) { _i_container = _i_container + n; return (*this); }

				/**
				 * Decrementation operator.
				 *
				 * @n : the value to substract.
				 */
				iterator &operator-= (int n) { _i_container -= n; return (*this); }

				/**
				 * Incrementation operator.
				 */
				iterator &operator++ (void) { _i_container++; return (*this); }

				/**
				 * Decrementation operator.
				 */
				iterator &operator-- (void) { _i_container--; return (*this); }

				/**
				 * Increment operator.
				 *
				 * @return : the iterator increased by 1.
				 */
				iterator operator++ (int n)
				{
					iterator	it(*this);

					(void)n;
					++this->_i_container;
					return (it);
				}

				/**
				 * Decrement operator.
				 *
				 * @return : the iterator decreased by 1.
				 */
				iterator operator-- (int n)
				{
					iterator	it(*this);

					(void)n;
					--this->_i_container;
					return (it);
				}

				/**
				 * Addition operator.
				 *
				 * @param n : number to add.
				 * @return : increased iterator.
				 */
				iterator operator+ (int n)
				{
					iterator	it(*this);

					it._i_container += n;
					return (it);
				}

				/**
				 * Substraction operator.
				 *
				 * @param n : number to substract.
				 * @return : substracted iterator.
				 */
				iterator operator- (int n)
				{
					iterator	it(*this);

					it._i_container -= n;
					return (it);
				}
		};

		class	const_iterator
		{
			private:
				pointer	_i_container;

			public:

				/**
				 * Default constructor.
				 */
				const_iterator (void): _i_container(NULL)
				{
				}

				/**
				 * Assignation constructor.
				 *
				 * @container : the container to assign.
				 */
				const_iterator (const_pointer container): _i_container(container)
				{
				}

				/**
				 * Copy constructor.
				 *
				 * @it : the iterator to copy.
				 */
				const_iterator (const const_iterator &it): _i_container(it._i_container)
				{
				}

				const_iterator (const iterator &it)
				{
					*this = it;
				}

				~const_iterator (void) {}

				//OPERATORS

				/**
				 * Assignation operator.
				 *
				 * Copies all the elements from x into the container.
				 * @param it : the iterator to assign.
				 * @return : *this.
				 */
				const_iterator &operator= (const_iterator const &it)
				{
					_i_container = it._i_container;
					return (*this);
				}

				/**
				 * Offset dereference operator.
				 *
				 * @return : the value of the dereferenced container.
				 */
				value_type	operator[] (size_type n) const { return (_i_container[n]); }

				/**
				 * Dereference operator.
				 *
				 * @return : the value of the dereferenced container.
				 */
				reference	operator* (void) const { return (*_i_container); }

				/**
				 * Dereference operator.
				 *
				 * @return : the value of the dereferenced container.
				 */
				value_type	operator-> (void) const { return (_i_container); }

				/**
				 * Equality operator.
				 *
				 * @return : true if the 2 containers are equals, otherwise it returns false.
				 */
				bool	operator== (const iterator &it) const	{ return (it._i_container == _i_container); }

				/**
				 * Disequality operator.
				 *
				 * @return : true if the 2 containers are not equals, otherwise it returns false.
				 */
				bool	operator!= (const iterator &it) const	{ return (it._i_container != _i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A < B, otherwise it returns false.
				 */
				bool	operator< (const iterator &it) const { return (it._i_container < _i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A > B, otherwise it returns false.
				 */
				bool	operator> (const iterator &it) const { return (it._i_container < _i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A <= B, otherwise it returns false.
				 */
				bool	operator<= (const iterator &it) const { return (it._i_container < _i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A >= B, otherwise it returns false.
				 */
				bool	operator>= (const iterator &it) const { return (it._i_container < _i_container); }

		};

	private:
		void			realloc(size_type new_capacity)
		{
			value_type	*tmp;

			//if (new_capacity > max_size())
			//	throw length_error;
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
		vector (const allocator_type& alloc = allocator_type())
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
		 * @param n : Initial container size
		 * @param val : Value to fill the container with
		 * @param alloc : Allocator object
		 */
		vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			this->_c_size = 0;
			this->_c_allocator = alloc;
			this->_c_container = this->_c_allocator.allocate(n);
			this->_c_capacity = n;
			assign(n, val);
		}

		/**
		 * Destructor of the container
		 */
		~vector (void)
		{
			clear();
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


		//CAPACITY METHODS

		/**
		 * Returns the number of elements in the vector.
		 * @return : The number of elements in the container.
		 */
		size_type	size (void)
		{
			return (this->_c_size);
		}

		/**
		 * Return maximum size.
		 *
		 * Returns the maximum number of elements that the vector can hold.
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
		 * @param n : New container size, expressed in number of elements.
		 * @param val : Object whose content is copied to the added elements in case that n is greater than the current container size.
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
		 * Returns whether the vector is empty
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
		 * @n : Minimum capacity for the vector.
		 */
		void reserve (size_type n)
		{
			if (n > this->_c_size)
				realloc(n);
		}

		//ELEMENT ACCESS METHODS

		/**
		 * Access element
		 *
		 * Returns a reference to the element at position n in the vector container.
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
		 * @param n : New size for the container
		 * @param val : Value to fill the container with.
		 */
		void assign (size_type n, const value_type& val)
		{
			for (size_type i = this->_c_size; i; i--)
				pop_back();
			for (size_type j = 0; j < n; ++j)
				push_back(val);
		}

		/**
		 * Add element at the end.
		 *
		 * Adds a new element at the end of the vector, after its current last element.
		 * @val : Value to be copied (or moved) to the new element.
		 */
		void push_back (const value_type& val)
		{
			if (this->_c_capacity <= this->_c_size)
				reserve(this->_c_size + 1);
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
			if (this->_c_size + 1 > this->_c_capacity)
				reserve(this->_c_size + 1);
			while (end > pos)
			{
				this->_c_allocator.destroy(&this->_c_container[end]);
				this->_c_allocator.construct(&this->_c_container[end], this->_c_container[end - 1]);
				end--;
			}
			this->_c_size++;
			this->_c_allocator.construct(&this->_c_container[end], val);
			return (begin() + pos);
		}

		/**
		 * Insert elements. (fill)
		 *
		 * The vector is extended by inserting new elements before the element at the specified position,
		 * effectively increasing the container size by the number of elements inserted.
		 * @position : Position in the vector where the new elements are inserted.
		 * @n : Number of elements to insert.
		 * @val : Value to be copied (or moved) to the inserted elements.
		 */
		void insert (iterator position, size_type n, const value_type& val)
		{
			size_type	pos = 0;
			size_type	end = this->_c_size + n;

			for (iterator it = begin(); it != position; it++)
				pos++;
			if (end > this->_c_capacity)
				reserve(end);
			while (end > pos + n)
			{
				this->_c_allocator.destroy(&this->_c_container[end]);
				this->_c_allocator.construct(&this->_c_container[end], this->_c_container[end - n]);
				end--;
			}
			while (end > pos)
			{
				this->_c_allocator.construct(&this->_c_container[end], val);
				end--;
			}
			this->_c_size += n;
		}

		/**
		 * Insert elements. (range)
		 *
		 * The vector is extended by inserting new elements before the element at the specified position,
		 * effectively increasing the container size by the number of elements inserted.
		 * @position : Position in the vector where the new elements are inserted.
		 * @first : Iterators specifying a range of elements.
		 * @last : Iterators specifying a range of elements.
		 */
//		template <class InputIterator>
  //  	void insert (iterator position, InputIterator first, InputIterator last)
	//	{
			//TODO
	//	}

		/**
		 * Erase elements.
		 *
		 * Removes from the vector either a single element (position) or a range of elements ([first,last)).
		 * @position : Iterator pointing to a single element to be removed from the vector.
		 * @return : An iterator pointing to the new location of the element
		 * that followed the last element erased by the function call.
		 */
		iterator erase (iterator position)
		{
			size_type	pos = 0;
			size_type	end = this->_c_size;

			for (iterator it = begin(); it != position; it++)
				pos++;
			this->_c_allocator.destroy(&this->_c_container[pos]);
			while (pos < end)
			{
				this->_c_allocator.construct(&this->_c_container[pos], this->_c_container[pos + 1]);
				pos++;
			}
			this->_c_size--;
			this->_c_allocator.destroy(&this->_c_container[end]);
			return (begin() + pos);
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
			size_type	pos = 0;
			int			cnt = 0;
			iterator	it = begin();

			for (iterator itb = begin(); itb != first; itb++)
				cnt++;
			while (it != last)
			{
				pos++;
				it++;
			}
			while (pos >= cnt)
			{
				this->_c_allocator.destroy(&this->_c_container[pos]);
				this->_c_allocator.construct(&this->_c_container[pos], this->_c_container[this->_c_size - 1]);
				this->_c_allocator.destroy(&this->_c_container[this->_c_size - 1]);
				it--;
				pos--;
				this->_c_size--;
			}
			return (begin() + pos);
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
			size_type	i = 0;
			size_type	size = this->_c_size;

			for (iterator it = begin(); i < size; i++)
				erase(it++);
		}
	};
}
