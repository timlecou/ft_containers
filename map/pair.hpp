#ifndef PAIR_HPP
# define PAIR_HPP

namespace   ft
{
	template<class T1, class T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1      first;
		T2      second;

		pair() : first(first_type()), second(second_type()) {}

		template<class U, class V>
		pair(const pair<U, V>& pr) : first(pr.first), second(pr.second) {}

		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

        template <class U, class V>
		pair<T1, T2>    &operator= (const pair<U, V> &pr)
		{
			first = std::move(pr.first);
			second = pr.second;

			return (*this);
		}

		bool operator==(const pair &pr) const
        {
            return (first == pr.first && second == pr.second);
        }
        bool operator!=(const pair &pr) const
        {
            return (first != pr.first || second != pr.second);
        }
        bool operator<(const pair &pr) const
        {
            return (first < pr.first || (!(pr.first < first) && second < pr.second));
        }
        bool operator>(const pair &pr) const
        {
            return (!(*this <= pr));
        }
         bool operator<=(const pair &pr) const
        {
            return !(pr < *this);
        }
        bool operator>=(const pair &pr) const
        {
            return !(*this < pr);
        }
	};
}

#endif