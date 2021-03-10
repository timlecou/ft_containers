#ifndef VECTORITERATORS_HPP
# define VECTORITERATORS_HPP
# include <iostream>
# include "utils.hpp"
# include "vector.hpp"

namespace	ft
{
	template <typename T>
	class	vectorConstIterator;

	template <typename T>
	class	vectorIterator
	{
		public:
			typedef	T					value_type;
			typedef	T&					reference;
			typedef	T*					pointer;
			typedef	std::ptrdiff_t		difference_type;
		private:
			pointer	_i_container;

		public:

			/**
			 * Default constructor.
			 */
			vectorIterator<T> (void)
			{
				this->_i_container = NULL;
			}
	
			/**
			 * Assignation constructor.
			 *
			 * @container : the container to assign.
			 */
			vectorIterator<T> (pointer container)
			{
				this->_i_container = container;
			}

			/**
			 * Copy constructor.
			 *
			 * @it : the vectorIterator<T> to copy.
			 */
			vectorIterator<T> (const vectorIterator<T> &it)
			{
				this->_i_container = it._i_container;
			}

			/**
			 * Copy constructor.
			 *
			 * @it : the vectorIterator<T> to copy.
			 */
			vectorIterator<T> (const vectorConstIterator<T> &it)
			{
				this->_i_container = it._icontainer;
			}

			~vectorIterator<T> (void) {}
			//OPERATORS

			/**
			 * Assignation operator.
			 *
			 * Copies all the elements from x into the container.
			 * @param it : the vectorIterator<T> to assign.
			 * @return : *this.
			 */
			vectorIterator<T> &operator= (vectorIterator<T> const &it)
			{
				_i_container = it._i_container;
				return (*this);
			}

			/**
			 * Assignation operator.
			 *
			 * Copies all the elements from x into the container.
			 * @param it : the vectorIterator<T> to assign.
			 * @return : *this.
			 */
			vectorIterator<T> &operator= (vectorConstIterator<T> const &it)
			{
				this->_i_container = &*it;
				return (*this);
			}

			operator vectorConstIterator<T>()
			{
				return (vectorConstIterator<T>(this->_i_container));
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
			reference	operator* (void) const { return (*(this->_i_container)); }

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
			bool	operator== (const vectorIterator<T> &it) const	{ return (it._i_container == _i_container); }

			/**
			 * Disequality operator.
			 *
			 * @return : true if the 2 containers are not equals, otherwise it returns false.
			 */
			bool	operator!= (const vectorIterator<T> &it) const	{ return (it._i_container != _i_container); }

			/**
			 * Comparison operator.
			 *
			 * @return : true if the A < B, otherwise it returns false.
			 */
			bool	operator< (const vectorIterator<T> &it) const { return (_i_container < it._i_container); }

			/**
			 * Comparison operator.
			 *
			 * @return : true if the A > B, otherwise it returns false.
			 */
			bool	operator> (const vectorIterator<T> &it) const { return (_i_container > it._i_container); }

			/**
			 * Comparison operator.
			 *
			 * @return : true if the A <= B, otherwise it returns false.
			 */
			bool	operator<= (const vectorIterator<T> &it) const { return (_i_container <= it._i_container); }

			/**
			 * Comparison operator.
			 *
			 * @return : true if the A >= B, otherwise it returns false.
			 */
			bool	operator>= (const vectorIterator<T> &it) const { return (_i_container >= it._i_container); }

			/**
			 * Incrementation operator.
			 *
			 * @n : the value to add.
			 */
			vectorIterator<T> &operator+= (int n) { _i_container = _i_container + n; return (*this); }

			/**
			 * Decrementation operator.
			 *
			 * @n : the value to substract.
			 */
			vectorIterator<T> &operator-= (int n) { _i_container -= n; return (*this); }

			/**
			 * Incrementation operator.
			 */
			vectorIterator<T> &operator++ (void) { _i_container++; return (*this); }

			/**
			 * Decrementation operator.
			 */
			vectorIterator<T> &operator-- (void) { _i_container--; return (*this); }

			/**
			 * Increment operator.
			 *
			 * @return : the vectorIterator<T> increased by 1.
			 */
			vectorIterator<T> operator++ (int n)
			{
				vectorIterator<T>	it(*this);
	
				(void)n;
				++this->_i_container;
				return (it);
			}

			/**
			 * Decrement operator.
			 *
			 * @return : the vectorIterator<T> decreased by 1.
			 */
			vectorIterator<T> operator-- (int n)
			{
				vectorIterator<T>	it(*this);

				(void)n;
				--this->_i_container;
				return (it);
			}

			/**
			 * Addition operator.
			 *
			 * @param n : number to add.
			 * @return : increased vectorIterator<T>.
			 */
			vectorIterator<T> operator+ (int n)
			{
				vectorIterator<T>	it(*this);

				it._i_container += n;
				return (it);
			}

			/**
			 * Substraction operator.
			 *
			 * @param n : number to substract.
			 * @return : substracted vectorIterator<T>.
			 */
			vectorIterator<T> operator- (int n)
			{
				vectorIterator<T>	it(*this);

				it._i_container -= n;
				return (it);
			}
	};

		template <typename T>
		class	vectorConstIterator
		{
			private:
				pointer	_i_container;

			public:

				/**
				 * Default constructor.
				 */
				vectorConstIterator<T> (void)
				{
					this->_i_container = NULL;
				}

				/**
				 * Assignation constructor.
				 *
				 * @container : the container to assign.
				 */
				vectorConstIterator<T> (pointer container)
				{
					this->_i_container = container;
				}

				/**
				 * Copy constructor.
				 *
				 * @it : the vectorIterator<T> to copy.
				 */
				vectorConstIterator<T> (const vectorIterator<T> &it)
				{
					this->_i_container = it._i_container;
				}

				/**
				 * Copy constructor.
				 *
				 * @it : the vectorIterator<T> to copy.
				 */
				vectorConstIterator<T> (const vectorConstIterator<T> &it)
				{
					this->_i_container = it._i_container;
				}

				/**
				 * Destructor.
				 */
				~vectorConstIterator<T> (void) {}

				//OPERATORS

				/**
				 * Assignation operator.
				 *
				 * Copies all the elements from x into the container.
				 * @param it : the vectorIterator<T> to assign.
				 * @return : *this.
				 */
				vectorConstIterator<T>	&operator= (vectorConstIterator<T> const &it)
				{
					_i_container = it._i_container;
					return (*this);
				}

				/**
				 * Assignation operator.
				 *
				 * Copies all the elements from x into the container.
				 * @param it : the vectorIterator<T> to assign.
				 * @return : *this.
				 */
				vectorConstIterator<T> &operator= (vectorIterator<T> const &it)
				{
					_i_container = &*it;
					return (*this);
				}

				operator	vectorIterator<T>()
				{
					return (vectorIterator<T>(this->_i_container));
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
				const_reference	operator* (void) const { return (*(this->_i_container)); }

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
				bool	operator== (const vectorConstIterator<T> &it) const	{ return (it._i_container == _i_container); }

				/**
				 * Disequality operator.
				 *
				 * @return : true if the 2 containers are not equals, otherwise it returns false.
				 */
				bool	operator!= (const vectorConstIterator<T> &it) const	{ return (it._i_container != _i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A < B, otherwise it returns false.
				 */
				bool	operator< (const vectorConstIterator<T> &it) const { return (_i_container < it._i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A > B, otherwise it returns false.
				 */
				bool	operator> (const vectorConstIterator<T> &it) const { return (_i_container > it._i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A <= B, otherwise it returns false.
				 */
				bool	operator<= (const vectorConstIterator<T> &it) const { return (it._i_container <= it._i_container); }

				/**
				 * Comparison operator.
				 *
				 * @return : true if the A >= B, otherwise it returns false.
				 */
				bool	operator>= (const vectorConstIterator<T> &it) const { return (_i_container >= it._i_container); }

				/**
				 * Incrementation operator.
				 */
				vectorConstIterator<T> &operator++ (void) { _i_container++; return (*this); }

				/**
				 * Decrementation operator.
				 */
				vectorConstIterator<T> &operator-- (void) { _i_container--; return (*this); }

				/**
				 * Increment operator.
				 *
				 * @return : the vectorIterator<T> increased by 1.
				 */
				vectorConstIterator<T> operator++ (int n)
				{
					vectorConstIterator<T>	it(*this);

					(void)n;
					++this->_i_container;
					return (it);
				}

				/**
				 * Decrement operator.
				 *
				 * @return : the vectorIterator<T> decreased by 1.
				 */
				vectorConstIterator<T> operator-- (int n)
				{
					vectorConstIterator<T>	it(*this);

					(void)n;
					--this->_i_container;
					return (it);
				}

				/**
				 * Addition operator.
				 *
				 * @param n : number to add.
				 * @return : increased vectorIterator<T>.
				 */
				vectorConstIterator<T> operator+ (int n)
				{
					vectorConstIterator<T>	it(*this);

					it._i_container += n;
					return (it);
				}

				/**
				 * Substraction operator.
				 *
				 * @param n : number to substract.
				 * @return : substracted vectorIterator<T>.
				 */
				vectorConstIterator<T> operator- (int n)
				{
					vectorConstIterator<T>	it(*this);

					it._i_container -= n;
					return (it);
				}
		};
		
		/**
		 * This class reverses the direction in which a bidirectional or
		 * random-access vectorIterator<T> iterates through a range.
		 *
		 * A copy of the original vectorIterator<T> (the base vectorIterator<T>) is kept internally
		 * and used to reflect the operations performed on the reverse_vectorIterator<T>:
		 * whenever the reverse_vectorIterator<T> is incremented, its base vectorIterator<T> is decreased,
		 * and vice versa. A copy of the base vectorIterator<T> with the current state can be
		 * obtained at any time by calling member base.
		 */
		template <class Iterator>
		class vectorReverseIterator<T>
		{
			public:
				typedef	Iterator	iterator_type;

			private:
				iterator_type	_base;

			public:

				/**
				 * Default constructor.
				 *
				 * Constructs a reverse vectorIterator<T> that points to no object.
				 */
				reverse_iterator<T>(void)
				{
					this->_base = NULL;
				}

				/**
				 * Initialization constructor.
				 *
				 * Constructs a reverse vectorIterator<T> from some original vectorIterator<T> it.
				 *
				 * @it : An vectorIterator<T>, whose sense of iteration is inverted in the constructed object.
				 */
				explicit reverse_iterator<T> (iterator_type it)
				{
					this->_base = it;
				}

				/**
				 * Copy / Type-cast constructor.
				 *
				 * Constructs a reverse vectorIterator<T> from some other reverse vectorIterator<T>.
				 *
				 * @rev_it : An vectorIterator<T> of a reverse_vectorIterator<T> type, whose sense of iteration is preserved.
				 */
		};
}

#endif
