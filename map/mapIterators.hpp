#ifndef MAPITERATORS_HPP
# define MAPIYERATORS_HPP
# include "btree.h"

namespace   ft
{
    template <class Key, class T>
    class   mapIterator
    {
        public:
            typedef	T					value_type;
			typedef	T					&reference;
			typedef	T	const			&const_reference;
			typedef	T					*pointer;
			typedef	T	const			*const_pointer;
			typedef	std::ptrdiff_t		difference_type;
        
        private:
            btree<Key, T>               _i_node;

        public:

            /**
             * Default constructor.
             */
            mapIterator<Key, T> (void)
            {
                
            }
    };
}

#endif