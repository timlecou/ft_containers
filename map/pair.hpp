#ifndef PAIR_HPP
# define PAIR_HPP

namespace   ft
{
    template <class T1, class T2>
    struct pair
    {
        typedef T1          first_type;
        typedef T2          second_type;

        first_type          first;
        second_type         second;

        /**
         * Default constructor.
         * 
         * Constructs a pair object with its elements value-initialized.
         */
        pair (void): first(0), second(0) {}

        /**
         * Copy constructor.
         * 
         * The object is initialized with the contents of the pr pair object.
         * 
         * @pr : Another pair object.
         */
        template<class U, class V>
        pair (const pair<U,V>& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
        }

        /**
         * Initialization constructor.
         * 
         * Member first is constructed with a and member second with b.
         * 
         * @a : An object of the type of first, or some other type implicitly convertible to it.
         * @b : An object of the type of second, or some other type implicitly convertible to it.
         */
        pair (const first_type& a, const second_type& b)
        {
            this->first = a;
            this->second = b;
        }

        /**
         * Assign contents.
         * 
         * Assigns pr as the new content for the pair object.
         * 
         * @pr : Another pair object.
         * @return : *this.
         */
        pair& operator= (const pair& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }
    };
}

#endif