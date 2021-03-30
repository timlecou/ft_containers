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


	template <class Iterator> class reverse_iterator
	{
	public : //REVERSE_ITERATOR TYPEDEF
		typedef	Iterator									iterator_type;
		typedef typename Iterator::pointer					pointer;
		typedef	typename Iterator::reference				reference;
		typedef	typename Iterator::value_type				value_type;
		typedef ptrdiff_t   								difference_type;

	private:
		iterator_type it;

	public :
		//REVERSE_ITERATOR CONSTRUCTOR DESTRUCTOR
		explicit reverse_iterator(){ it = iterator_type(); }
		explicit reverse_iterator(const iterator_type &it_to_reverse){ it = it_to_reverse; }

		template<class It>
		reverse_iterator(const reverse_iterator<It> &x){ it = x.base(); }

		~reverse_iterator(){}

		iterator_type base() const { return (it); }

		//REVERSE_ITERATOR OPERATOR
		template<class It>
		reverse_iterator &operator=(const reverse_iterator<It> &x){ it = x.base(); return (*this); }

		reference   operator[](difference_type n) const { return (it[-n - 1]); }
		reference   operator*() const { return (*--base()); }
		pointer     operator->() const { return (&(*--base())); }

		template<class It>
		bool operator==(const reverse_iterator<It> &x) const { return (it == x.base() ? 1 : 0); }
		template<class It>
		bool operator!=(const reverse_iterator<It> &x) const { return (it != x.base() ? 1 : 0); }
		template<class It>
		bool operator<(const reverse_iterator<It> &x) const { return (it > x.base() ? 1 : 0); }
		template<class It>
		bool operator>(const reverse_iterator<It> &x) const { return (it < x.base() ? 1 : 0); }
		template<class It>
		bool operator>=(const reverse_iterator<It> &x) const { return (it <= x.base() ? 1 : 0); }
		template<class It>
		bool operator<=(const reverse_iterator<It> &x) const { return (it >= x.base() ? 1 : 0); }

		reverse_iterator &operator+=(int n){ it -= n; return (*this); }
		reverse_iterator &operator-=(int n){ it += n; return (*this); }
		reverse_iterator &operator++(){ --it; return (*this); }
		reverse_iterator &operator--(){ ++it; return (*this); }
		reverse_iterator operator++(int n)
		{
			reverse_iterator    x(*this);

			it.operator--(n);
			return(x);
		}
		reverse_iterator operator--(int n)
		{
			reverse_iterator    x(*this);

			it.operator++(n);
			return(x);
		}

		reverse_iterator operator+(int n) const
		{
			reverse_iterator    x(base() - n);

			return(x);
		}
		reverse_iterator operator-(int n) const
		{
			reverse_iterator    x(base() + n);

			return(x);
		}
		friend reverse_iterator operator+(int n, const reverse_iterator &t)
		{
			return(t + n);
		}
		friend reverse_iterator operator-(int n, const reverse_iterator &t)
		{
			return(t - n);
		}
		template <class It>
		int operator-(const reverse_iterator<It> &rhs)
		{
			return(-(base() - rhs.base()));
		}
	};


}

#endif