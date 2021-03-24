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
			mapIterator<Key, T> (btree<Key, T> *root)
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
			reference	operator* (void) const { return (this->_i_root->element.second); }

			/**
			 * Dereference operator.
			 *
			 * @return : the value of the dereferenced container.
			 */
			pointer		operator-> (void) const { return (&this->_i_root->element.second); }

			/**
			 * Increment operator.
			 * 
			 * Increments the iterator by 1.
			 */
			mapIterator<Key, T> &operator++ (void)
			{
				if (this->_i_root->r_flag == false)
					this->_i_root = this->_i_root->right;
				else
				{
					this->_i_root = this->_i_root->right;
					while (this->_i_root->l_flag == true)
						this->_i_root = this->_i_root->left;
				}
				return (*this);
			}

			/**
			 * Decrement operator.
			 * 
			 * Decrements the iterator by 1.
			 */
			mapIterator<Key, T> &operator-- (void)
			{
				if (this->_i_root->l_flag == false)
					this->_i_root = this->_i_root->left;
				else
				{
					this->_i_root = this->_i_root->left;
					while (this->_i_root->r_flag == true)
						this->_i_root = this->_i_root->right;
				}
				return (*this);
			}

			/**
			 * Increment operator.
			 * 
			 * Increments the iterator by 1.
			 * @return : the iterator before the incrementation.
			 */
			mapIterator<Key, T> operator++ (int n)
			{
				(void)n;
				mapIterator<Key, T>		tmp(*this);
				
				if (this->_i_root->r_flag == false)
					this->_i_root = this->_i_root->right;
				else
				{
					this->_i_root = this->_i_root->right;
					while (this->_i_root->l_flag == true)
						this->_i_root = this->_i_root->left;
				}
				return (tmp);
			}

			/**
			 * Decrement operator.
			 * 
			 * Decrements the iterator by 1.
			 * @return : the iterator before the decrementation.
			 */
			mapIterator<Key, T> operator-- (int n)
			{
				(void)n;
				mapIterator<Key, T>		tmp(*this);
				
				if (this->_i_root->l_flag == false)
					this->_i_root = this->_i_root->left;
				else
				{
					this->_i_root = this->_i_root->left;
					while (this->_i_root->r_flag == true)
						this->_i_root = this->_i_root->right;
				}
				return (tmp);
			}
    };
}

#endif