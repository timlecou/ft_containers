#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace   ft
{

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
		class reverse_iterator
		{
			public:
				typedef	Iterator									iterator_type;
				typedef typename Iterator::pointer					pointer;
				typedef	typename Iterator::reference				reference;
				typedef	typename Iterator::value_type				value_type;
                typedef ptrdiff_t   								difference_type;

			private:
				iterator_type	_base;

			public:

				/**
				 * Default constructor.
				 *
				 * Constructs a reverse vectorIterator<T> that points to no object.
				 */
				reverse_iterator<Iterator> (void)
				{
					this->_base = Iterator();
				}

				/**
				 * Initialization constructor.
				 *
				 * Constructs a reverse vectorIterator<T> from some original vectorIterator<T> it.
				 *
				 * @it : An vectorIterator<T>, whose sense of iteration is inverted in the constructed object.
				 */
				reverse_iterator<Iterator> (iterator_type it)
				{
					this->_base = it;
				}

				/**
				 * Copy / Type-cast constructor.
				 *
				 * Constructs a vectorReverseIterator<Iterator> from some other vectorReverseIterator<Iterator>.
				 *
				 * @rev_it : An vectorReverseIterator<Iterator> of a vectorReverseIterator<Iterator> type, whose sense of iteration is preserved.
				 */
				reverse_iterator<Iterator> (const reverse_iterator<Iterator> &rev_it)
				{
					*this = rev_it;
				}
				
				/**
				 * Destructor.
				 */
				~reverse_iterator<Iterator> (void) {}

				/**
				 * Return base iterator.
				 * 
				 * Returns a copy of the base iterator.
				 * 
				 * A copy of the base iterator, which iterates in the opposite direction.
				 */
				iterator_type	base (void) const
				{
					return (this->_base);
				}

				/**
				 * Assignation operator for vectorReverseIterator.
				 * 
				 * Assigns the content of rev_it in this.
				 */
				template<class It>
				reverse_iterator<It>	&operator= (const reverse_iterator<It> &rev_it)
				{
					this->_base = rev_it.base();
					return (*this);
				}

				/**
				 * Dereference operator.
				 */
				reference	operator* (void) const { return (*(this->_base)); }

                /**
                 * Addition operator.
                 * 
                 * Returns a reverse iterator pointing to the element located n positions away from the element the iterator currently points to.
                 * 
                 * @n : Number of elements to offset.
                 * @return : An iterator pointing to the element n positions away.
                 */
				reverse_iterator<Iterator> operator+ (difference_type n) const
				{
					return (reverse_iterator(this->base() - n));
				}

				/**
                 * Substraction operator.
                 * 
                 * Returns a reverse iterator pointing to the element located n positions before from the element the iterator currently points to.
                 * 
                 * @n : Number of elements to offset.
                 * @return : An iterator pointing to the element n positions away.
                 */
				reverse_iterator<Iterator> operator- (difference_type n) const
				{
					return (reverse_iterator(this->base() + n));
				}

				/**
				 * Increment iterator position.
				 * 
				 * Advances the reverse_iterator by one position.
				 * 
				 * @return : *this.
				 */
				reverse_iterator& operator++ (void)
				{
					this->_base--;
					return (*this);
				}

				/**
				 * Increment iterator position.
				 * 
				 * Advances the reverse_iterator by one position.
				 * 
				 * @return : the value *this had before the call.
				 */
				reverse_iterator  operator++ (int)
				{
					reverse_iterator	tmp = *this;
					++(*this);
					return (tmp);
				}

				/**
				 * Decrement iterator position.
				 * 
				 * Decreases the reverse_iterator by one position.
				 * 
				 * @return : *this.
				 */
				reverse_iterator& operator-- (void)
				{
					this->_base++;
					return (*this);
				}

				/**
				 * Decrement iterator position.
				 * 
				 * Decreases the reverse_iterator by one position.
				 * 
				 * @return : the value *this had before the call.
				 */
				reverse_iterator  operator-- (int)
				{
					reverse_iterator	tmp = *this;
					--(*this);
					return (tmp);
				}

				/**
				 * Advance iterator.
				 * 
				 * Advances the reverse_iterator by n element positions.
				 * 
				 * @n : Number of elements to offset.
				 * @return : The reverse iterator itself (*this).
				 */
				reverse_iterator& operator+= (difference_type n)
				{
					(*this) += n;
					return (*this);
				}

				/**
				 * Retrocede iterator.
				 * 
				 * Retrocedes the reverse_iterator by n element positions.
				 * 
				 * @n : Number of elements to offset.
				 * @return : The reverse iterator itself (*this).
				 */
				reverse_iterator& operator-= (difference_type n)
				{
					(*this) -= n;
					return (*this);
				}

				/**
				 * Dereference operator.
				 * 
				 * Returns a pointer to the element pointed to by the iterator (in order to access one of its members).
				 * 
				 * @return : A pointer to the element pointed by the iterator.
				 */
				pointer operator->() const
				{
					return (&(operator*()));
				}

				/**
				 * Dereference iterator with offset.
				 * 
				 * Accesses the element located n positions away from the element currently pointed to by the iterator.
				 * 
				 * @n : Number of elements to offset.
				 * @return : A reference to the element n positions away from the element currently pointed by the iterator.
				 */
				reference operator[] (difference_type n) const
				{
					return (base()[-n-1]);
				}

				/**
				 * Relationnale operators for reverse_iterator.
				 * 
				 * Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
				 * 
				 * @rhs : reverse_iterator objects.
				 * @return : true if the condition holds, and false otherwise.
				 */
				bool operator== (const reverse_iterator<Iterator>& rhs)
				{
					return (base() == rhs.base());
				}

				/**
				 * Relationnal operators for reverse_iterator.
				 * 
				 * Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
				 * 
				 * @rhs : reverse_iterator objects.
				 * @return : true if the condition holds, and false otherwise.
				 */
				bool operator!= (const reverse_iterator<Iterator>& rhs)
				{
					return (base() != rhs.base());
				}

				/**
				 * Relationnal operators for reverse_iterator.
				 *
				 * Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
				 *
				 * @rhs : reverse_iterator objects.
				 * @return : true if the condition holds, and false otherwise.
				 */
				bool operator< (const reverse_iterator<Iterator>& rhs)
				{
					return (base() > rhs.base());
				}

				/**
				 * Relationnal operators for reverse_iterator.
				 *
				 * Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
				 *
				 * @rhs : reverse_iterator objects.
				 * @return : true if the condition holds, and false otherwise.
				 */
				bool operator<= (const reverse_iterator<Iterator>& rhs)
				{
					return (base() >= rhs.base());
				}

				/**
				 * Relationnal operators for reverse_iterator.
				 *
				 * Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
				 *
				 * @rhs : reverse_iterator objects.
				 * @return : true if the condition holds, and false otherwise.
				 */
				bool operator> (const reverse_iterator<Iterator>& rhs)
				{
					return (base() < rhs.base());
				}

				/**
				 * Relationnal operators for reverse_iterator.
				 *
				 * Performs the appropriate comparison operation between the reverse_iterator objects lhs and rhs.
				 *
				 * @rhs : reverse_iterator objects.
				 * @return : true if the condition holds, and false otherwise.
				 */
				bool operator>= (const reverse_iterator<Iterator>& rhs)
				{
					return (base() <= rhs.base());
				}

		};

}

#endif