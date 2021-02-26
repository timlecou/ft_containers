#include <iostream>

/**
 * The namespace "ft" contains the Vector class
 */
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	Vector
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
		allocator_type 	_allocator;
		size_type		_size;
		size_type		_capacity;

	private:
		/*void			realloc(size_type previous_size)
		{
			value_type	*tmp;

			if (!(tmp = (value_type*)malloc(sizeof(value_type))))
				return (NULL);
		}*/

	public:

		/**
		 * Empty container constructor
		 *
		 * Constructs an empty container, with no elements.
		 * @param alloc : Allocator object
		 */
		Vector(const allocator_type& alloc = allocator_type())
		{
			this->_allocator = alloc;
			this->_c_container = NULL;
			this->_size = 0;
			this->_capacity = 0;
		}

		/**
		 * Fill constructor
		 *
		 * Constructs a container with n elements. Each element is a copy of val.
		 * @param n : Initial container size
		 * @param val : Value to fill the container with
		 * @param alloc : Allocator object
		 */
		Vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		{
			this->_allocator = alloc;
			this->_c_container = this->_allocator.allocate(n);
			for (size_type i = 0; i < n; ++i)
				this->_c_container[i] = val;
			this->_size = n;
			this->_capacity = n;
		}

		/**
		 * Destructor of the container
		 */
		~Vector(void)
		{

		}

		//CAPACITY METHODS

		/**
		 * Returns the number of elements in the vector.
		 * @return : The number of elements in the container.
		 */
		size_type	size(void)
		{
			return (this->_size);
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
		size_type max_size() const
		{
			return (this->_allocator.max_size());
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
		reference front()
		{
			return (this->_c_container[0]);
		}

		/**
		 * Access first element
		 *
		 * Returns a const reference to the first element in the vector.
		 * @return : A reference to the first element in the vector container.
		 */
		const_reference front() const
		{
			return (this->_c_container[0]);
		}

		/**
		 * Access last element
		 *
		 * Returns a reference to the last element in the vector.
		 * @return : A reference to the last element in the vector container.
		 */
		reference back()
		{
			return (this->_c_container[this->_size - 1]);
		}

		/**
		 * Access last element
		 *
		 * Returns a const reference to the last element in the vector.
		 * @return : A reference to the last element in the vector container.
		 */
		const_reference back() const
		{
			return (this->_c_container[this->_size - 1]);
		}


		/**
		 * Request a change in capacity
		 *
		 * Requests that the vector capacity be at least enough to contain n elements.
		 * @param n : Minimum capacity for the vector.
		 */
		void reserve (size_type n)
		{
			if (n > this->_capacity)
			{
				this->realloc(n);
			}
		}

		/**
		 * Test whether vector is empty
		 *
		 * Returns whether the vector is empty
		 * @return : true if the container size is 0, false otherwise.
		 */
		bool	empty(void) const
		{
			return (size() == 0);
		}
	};
}
