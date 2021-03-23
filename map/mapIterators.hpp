#ifndef MAPITERATORS_HPP
# define MAPITERATORS_HPP
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
            btree<Key, T>               *_i_root;

        public:

            /**
             * Default constructor.
             */
            mapIterator<Key, T> (void)
            {
                this->_i_root = NULL;
            }

            /**
             * Copy constructor.
             *
             * @param it : an iterator of the same type as this.
             */
            mapIterator<Key, T> (const mapIterator<Key, T> &it)
			{
            	this->_i_root = it._i_root;
			}

			/**
			 * Assignation construtor.
			 *
			 * @param root : the root of a binary tree;
			 */
			mapIterator<Key, T> (const btree<Key, T> &root)
			{
            	this->_i_root = root;
			}

			/**
			 * Assignation operator.
			 *
			 * assigns the value of it to this.
			 * @param it : an iterator of the same type as this.
			 * @return : *this;
			 */
			mapIterator<Key, T>	&operator= (const mapIterator<Key, T> &it)
			{
            	this->_i_root = it._i_root;
            	return (*this);
			}

			/**
			 * Destructor.
			 */
			~mapIterator (void) {}

			/**
			 * Equality operator.
			 *
			 * @param it : an iterator of the same type as this.
			 * @return : true is the two values are equals, otherwise it returns false.
			 */
			bool	operator== (const mapIterator<Key, T> &it) { return (this->_i_root == it._i_root); }

			/**
			 * Inequality operator.
			 *
			 * @param it : an iterator of the same type as this.
			 * @return : true is the two values are different, otherwise it returns false.
			 */
			bool	operator!= (const mapIterator<Key, T> &it) { return (this->_i_root != it._i_root); }

			/**
			 * Dereference operator.
			 *
			 * @return : the value of the dereferenced container.
			 */
			reference	operator* (void) const { return (this->_i_root->element); }

			/**
			 * Dereference operator.
			 *
			 * @return : the value of the dereferenced container.
			 */
			pointer		operator-> (void) const { return (&this->_i_root->element); }

		//	mapIterator<Key, T> &operator++ (void)
		//	{
		//		return (*this);
		//	}
    };
}

#endif