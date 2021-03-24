#ifndef MAP_HPP
# define MAP_HPP
# include "mapIterators.hpp"
# include <iostream>

namespace   ft
{
    /**
     * Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.
     * 
     * In a map, the key values are generally used to sort and uniquely identify the elements, while the mapped values store the content associated to this key.
     * Internally, the elements in a map are always sorted by its key following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).
     * map containers are generally slower than unordered_map containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order.
     * The mapped values in a map can be accessed directly by their corresponding key using the bracket operator ((operator[]).
     * 
     * Maps are typically implemented as binary search trees.
     */
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<Key,T> > >
    class map
    {
        public:
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef ft::pair<const key_type,mapped_type>        value_type;
            typedef Compare                                     key_compare;
        //    typedef blablabla                                   value_compare;
            typedef Alloc                                       allocator_type;
            typedef typename allocator_type::reference                   reference;
            typedef typename allocator_type::const_reference             const_reference;
            typedef typename allocator_type::pointer                     pointer;
            typedef typename allocator_type::const_pointer               const_pointer;
            typedef mapIterator<Key, T>                         iterator;
            typedef const mapIterator<Key, T>                   const_iterator;
            typedef ptrdiff_t                                   difference_type;
            typedef size_t                                      size_type;

        private:
			btree<Key, T>                       *_c_root;
            size_type                           _c_size;
            allocator_type				        _c_value_allocator;
			std::allocator<btree<Key, T> >	    _c_node_allocator;
			key_compare 						_cmp;

			btree<Key, T>	*findSuccessor(btree<Key, T> *tmp)
			{
				if (tmp->r_flag == true)
					return (tmp->right);

				tmp = tmp->right;
				while (tmp->l_flag == false)
					tmp = tmp->left;
				return (tmp);
			}

			btree<Key, T>	*findPredecessor(btree<Key, T> *tmp)
			{
				if (tmp->l_flag == true)
					return (tmp->left);

				tmp = tmp->left;
				while (tmp->r_flag == false)
					tmp = tmp->right;
				return (tmp);
			}

			btree<Key, T>	*eraseA(btree<Key, T> *tmp_root, btree<Key, T> *node, btree<Key, T> *tmp)
			{
				//if node to be deleted is root
				if (node == NULL)
				{
					tmp_root = NULL;
				}

				//if node to be deleted is left of its parent
				else if (tmp == node->left)
				{
					node->l_flag = true;
					node->left = tmp->left;
				}
				else
				{
					node->r_flag = true;
					node->right = tmp->right;
				}

				//destroy/free the element
				this->_c_value_allocator.destroy(&tmp->element);
				this->_c_node_allocator.deallocate(tmp, 1);

				return (tmp_root);
			}

			btree<Key, T>	*eraseB(btree<Key, T> *tmp_root, btree<Key, T> *node, btree<Key, T> *tmp)
			{
				btree<Key, T>		*child;

				if (tmp->l_flag == false)
					child = tmp->left;
				else
					child = tmp->right;

				if (node == NULL)
					tmp_root = child;
				else if (tmp == node->left)
					node->left = child;
				else
					node->right = child;

				btree<Key, T>		*suc = findSuccessor(tmp);
				btree<Key, T>		*pred = findPredecessor(tmp);

				if (tmp->l_flag == false)
					pred->right = suc;
				else
				{
					if (tmp->r_flag == false)
						suc->left = pred;
				}

				//destroy/free the element
				this->_c_value_allocator.destroy(&tmp->element);
				this->_c_node_allocator.deallocate(tmp, 1);

				return (tmp_root);
			}

			btree<Key, T>	*eraseC(btree<Key, T> *tmp_root, btree<Key, T> *node, btree<Key, T> *tmp)
			{
				btree<Key, T>	*pSuc = tmp;
				btree<Key, T>	*suc = tmp->right;

				while (suc->l_flag == false)
				{
					pSuc = suc;
					suc = suc->left;
				}

				tmp->element = suc->element;

				if (suc->l_flag == true && suc->r_flag == true)
					tmp_root = eraseA(tmp_root, node, tmp);
				else
					tmp_root = eraseB(tmp_root, node, tmp);
				return (tmp_root);
			}

	public:
        
            /**
             * Empty container constructor.
             * 
             * Constructs an empty container, with no elements.
             * 
             * @comp : Binary predicate that, taking two element keys as argument, returns true if the first argument goes before the second argument in the strict weak ordering it defines, and false otherwise.
             * @alloc : Allocator object.
             */
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                this->_c_value_allocator = alloc;
                this->_cmp = comp;
                this->_c_root = this->_c_node_allocator.allocate(1);
                this->_c_value_allocator.construct(&this->_c_root->element, value_type());
                this->_c_root->r_flag = true;
                this->_c_root->l_flag = false;
                this->_c_root->right = this->_c_root;
                this->_c_root->left = this->_c_root;
                this->_c_size = 0;
            }

            /**
             * Range constructor.
             * 
             * Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range.
             * 
             * @first / @last : Input iterators to the initial and final positions in a range.
             * @comp : Binary predicate that, taking two element keys as argument, returns true if the first argument goes before the second argument in the strict weak ordering it defines, and false otherwise.
             * @alloc : Allocator object.
             */
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                this->_c_value_allocator = alloc;
                this->_cmp = comp;
                this->_c_root = this->_c_node_allocator.allocate(1);
                this->_c_value_allocator.construct(&this->_c_root->element, value_type());
                this->_c_root->r_flag = true;
                this->_c_root->l_flag = false;
                this->_c_root->right = this->_c_root;
                this->_c_root->left = this->_c_root;
                this->_c_size = 0;
                insert(first, last);
            }

            /**
             * Copy constructor.
             * 
             * Constructs a container with a copy of each of the elements in x.
             * 
             * @x : Another map object of the same type (with the same class template arguments Key, T, Compare and Alloc), whose contents are either copied or acquired.
             */
            map (const map& x)
            {
                this->_c_root = x._c_root;
                this->_c_size = x.size();
            }

            /**
             * Destructor.
             */
            ~map (void) {}

        //ITERATORS
        
            iterator    begin (void)
            {
                btree<Key, T>       *node = this->_c_root->left;

                while (node->l_flag == true)
                    node = node->left;
                return (iterator(node));
            }

            const_iterator    begin (void) const
            {
                btree<Key, T>       *node = this->_c_root->left;

                while (node->l_flag == true)
                    node = node->left;
                return (const_iterator(node));
            }

            iterator    end (void)
            {
                return (iterator(this->_c_root));
            }

            const_iterator    end (void) const
            {
                return (const_iterator(this->_c_root));
            }

        //CAPACITY

            /**
             * Test wether the container is empty.
             * 
             * Returns whether the map container is empty (i.e. whether its size is 0).
             * 
             * @return : true if the container size is 0, false otherwise.
             */
            bool empty() const
            {
                if (this->_c_size > 0)
                    return (false);
                return (true);
            }

            /**
             * Return container size.
             * 
             * Returns the number of elements in the map container.
             * 
             * @return : The number of elements in the container.
             */
            size_type size() const
            {
                return (this->_c_size);
            }

            /**
             * Return maximum size.
             * 
             * Returns the maximum number of elements that the map container can hold.
             * 
             * @return : The maximum number of elements a map container can hold as content.
             */
            size_type max_size() const
            {
                return (this->_c_node_allocator.max_size());
            }

        //ELEMENTS ACCESS

            /**
             * Access element.
             * 
             * If k matches the key of an element in the container, the function returns a reference to its mapped value.
             * 
             * @k : Key value of the element whose mapped value is accessed.
             * @return : A reference to the mapped value of the element with a key value equivalent to k.
             */
            mapped_type& operator[] (const key_type& k)
            {
                iterator    it = find(k);
                if (it == end())
                {
                    ft::pair<Key, T>    elem;
                    elem.first = k;
                    //elem.second = 0;
                    return (insert(elem).first->second);
                }
                else
                    return (it->second);
                
            }

        //MODIFIERS

            /**
             * Insert elements. (single element)
             * 
             * Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
             * 
             * @val : Value to be copied to (or moved as) the inserted element.
             * @return : a pair, with its member pair::first set to an iterator pointing to either the newly inserted element or to the
             * element with an equivalent key in the map. The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.
             */
            ft::pair<iterator,bool> insert (const value_type& val)
            {
                btree<Key, T>   *node = this->_c_node_allocator.allocate(1);
                ft::pair<iterator, bool>            ret;

                ret.second = false;

                //if there is no value in the tree
                if (this->_c_root->left == this->_c_root && this->_c_root->right == this->_c_root)
                {
                    this->_c_value_allocator.construct(&node->element, val);
                    node->left = this->_c_root->left;
                    node->l_flag = this->_c_root->l_flag;
                    node->r_flag = false;
                    node->right = this->_c_root->right;

                    //add the element at the left of the dummy_node
                    this->_c_root->left = node;
                    this->_c_root->l_flag = true;
                    this->_c_size++;
                    ret.first = iterator(node);
                    ret.second = true;
                    return (ret);
                }

                node = this->_c_root->left;
                while (true)
                {
                    if (_cmp(node->element.first, val.first))
                    {
                        btree<Key, T>   *new_node = this->_c_node_allocator.allocate(1);
                        this->_c_value_allocator.construct(&new_node->element, val);
                        if (node->r_flag == false)
                        {
                            new_node->right = node->right;
                            new_node->r_flag = node->r_flag;
                            new_node->l_flag = false;
                            new_node->left = node;

                            //inserting node in the right
                            node->r_flag = true;
                            node->right = new_node;
                            this->_c_size++;
                            ret.first = iterator(new_node);
                            ret.second = true;
                            return (ret);
                        }
                        else
                            node = node->right;
                    }
                    
                    else if (_cmp(val.first, node->element.first))
                    {
                        btree<Key, T>   *new_node = this->_c_node_allocator.allocate(1);
                        this->_c_value_allocator.construct(&new_node->element, val);
                        if (node->l_flag == false)
                        {
                            new_node->left = node->left;
                            new_node->l_flag = node->l_flag;
                            new_node->r_flag = false;
                            new_node->right = node;

                            //inserting node in the left
                            node->l_flag = true;
                            node->left = new_node;
                            this->_c_size++;
                            ret.first = iterator(new_node);
                            ret.second = true;
                            return (ret);
                        }
                        else
                            node = node->left;
                    }
                    else
                    {
                        ret.first = iterator(node);
                        ret.second = false;
                        return (ret);
                    }
                }
                return (ret);
            }

            /**
             * Insert elements. (with hint)
             * 
             * Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
             * 
             * @position : Hint for the position where the element can be inserted.
             * @val : Value to be copied to (or moved as) the inserted element.
             * @return : an iterator pointing to either the newly inserted element or to the element that already had an equivalent key in the map.
             */
            iterator insert (iterator position, const value_type& val)
            {
                (void)position;
                return (insert(val).first);
            }

            /**
             * Insert elements.
             * 
             * Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
             * 
             * @first / @last : Iterators specifying a range of elements.
             */
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                while (first != last)
                    insert(*first++);
            }

            /**
             * Removes elements.
             *
             * Removes from the map container either a single element or a range of elements ([first,last)).
             *
             * @param position : Iterator pointing to a single element to be removed from the map.
             */
			void erase (iterator position)
			{
				erase(position->first);
			}

			/**
			 * Removes elements.
			 *
			 * Removes from the map container either a single element or a range of elements ([first,last)).
			 *
			 * @param k : Key of the element to be removed from the map.
			 * @return : The number of elements erased.
			 */
			size_type erase (const key_type& k)
			{
				btree<Key, T>		*tmp = this->_c_root->left;
				btree<Key, T>		*node = NULL;
				btree<Key, T>		*tmp_root = this->_c_root;
				bool				found = false;

				while (tmp != NULL)
				{
					if (tmp->element.first == k)
					{
						found = true;
						break ;
					}
					node = tmp;
					if (_cmp(tmp->element.first, k))
					{
						if (tmp->l_flag == true)
							tmp = tmp->left;
						else
							break ;
					}
					else if (_cmp(k, tmp->element.first))
					{
						if (tmp->r_flag == true)
							tmp = tmp->right;
						else
							break ;
					}
				}

				if (found == false)
					return (0);
				else if (tmp->l_flag == false && tmp->r_flag == false)	//two children
					tmp_root = eraseA(tmp_root, node, tmp);
				else if (tmp->l_flag == false)							//only left child
					tmp_root = eraseB(tmp_root, node, tmp);
				else if (tmp->r_flag == false)							//only right child
					tmp_root = eraseC(tmp_root, node, tmp);
				else													//no child
					tmp_root = eraseA(tmp_root, node, tmp);
				this->_c_root = tmp_root;
				this->_c_size--;
				return (1);
			}

            /**
             * Swap content.
             * 
             * Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
             * 
             * @x : Another map container of the same type as this (i.e., with the same template parameters, Key, T, Compare and Alloc) whose content is swapped with that of this container.
             */
            void swap (map& x)
            {
                map tmp;

                tmp = *this;
                *this = x;
                x = tmp;
            }

        //OPERATIONS

            /**
             * Get iterator to element.
             * 
             * Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
             * 
             * @k : Key to be searched for.
             * @return : An iterator to the element, if an element with specified key is found, or map::end otherwise.
             */
            iterator find (const key_type& k)
            {
                for (iterator it = begin(); it != end(); it++)
                {
                    if (it->first == k)
                        return (it);
                }
                return (end());
            }

            /**
             * Get const_iterator to element.
             * 
             * Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns a const_iterator to map::end.
             * 
             * @k : Key to be searched for.
             * @return : A const_iterator to the element, if an element with specified key is found, or map::end otherwise.
             */
            const_iterator find (const key_type& k) const
            {
                for (const_iterator it = begin(); it != end(); it++)
                {
					if (it->first == k)
                        return (it);
                }
                return (end());
            }

            /**
             * Count elements with specific keys.
             * 
             * Searches the container for elements with a key equivalent to k and returns the number of matches.
             * Because all elements in a map container are unique, the function can only return 1 (if the element is found) or zero (otherwise).
             * 
             * @k : key to search.
             * @return : 1 if the container contains an element whose key is equivalent to k, or zero otherwise.
             */
            size_type count (const key_type& k) const
            {
                for (iterator it = begin(); it != end(); it++)
                {
                    if (it->first == k)
                        return (1);
                }
                return (0);
            }
    };
}

#endif