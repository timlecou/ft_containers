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
		typedef	T				*pointer;
		typedef	T	const		*const_pointer;
		typedef	ptrdiff_t		difference_type;
		typedef	size_t			size_type;

	protected:
		value_type		*_c_container;
		allocator_type 	_c_allocator;
		size_type		_c_size;
		size_type		_c_capacity;

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
			this->_c_allocator = alloc;
			this->_c_container = this->_c_allocator.allocate(n);
			for (size_type i = 0; i < n; ++i)
				this->_c_allocator.construct(&this->_c_container[i], val);
			this->_c_size = n;
			this->_c_capacity = n;
		}

		/**
		 * Destructor of the container
		 */
		~vector (void)
		{

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
		 * Assign : Fill version
		 *
		 * Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		 * @param n : New size for the container
		 * @param val : Value to fill the container with.
		 */
		/*void assign (size_type n, const value_type& val)
		{
			this->_size = n;
			this->_capacity = n;
		}*/

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

		//MODIFIERS METHODS
		
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
			this->_c_container[this->_c_size] = val;
			this->_c_size++;
		}
	};
}
