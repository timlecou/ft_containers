#ifndef MAP_HPP
# define MAP_HPP
# include "mapIterators.hpp"
# include "../reverse_iterator.hpp"
# include <iostream>
# include <cstddef>

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
            typedef Key                                         	key_type;
            typedef T                                           	mapped_type;
            typedef ft::pair<const key_type, mapped_type>        	value_type;
            typedef Compare                                     	key_compare;
            typedef Alloc                                       	allocator_type;
            typedef typename allocator_type::reference              reference;
            typedef typename allocator_type::const_reference        const_reference;
            typedef typename allocator_type::pointer                pointer;
            typedef typename allocator_type::const_pointer          const_pointer;
            typedef mapIterator<Key, T>                     	    iterator;
            typedef mapConstIterator<Key, T>                   		const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<iterator>					const_reverse_iterator;
            typedef std::ptrdiff_t                                 	difference_type;
            typedef size_t                                      	size_type;

        private:
			btree<Key, T>                       *_c_root;
            size_type                           _c_size;
            allocator_type				        _c_value_allocator;
			std::allocator<btree<Key, T> >	    _c_node_allocator;
			key_compare 						_cmp;

            /**
             * This function finds the node which in the ultimate left of the tree.
             * 
             * @node : the root of the tree.
             * @return : the node wich in the ultimate left of the tree.
             */
            btree<Key, T>   *leftNode (btree<Key, T> *node)
            {
                while (node->l_flag == true)
                    node = node->left;
                return (node);
            }

            /**
             * This function finds the node which in the ultimate right of the tree.
             * 
             * @node : the root of the tree.
             * @return : the node wich in the ultimate right of the tree.
             */
            btree<Key, T>   *rightNode (btree<Key, T> *node)
            {
                while (node->r_flag == true)
                    node = node->right;
                return (node);
            }

            /**
             * This function finds the inorder predecessor of tmp.
             * 
             * @tmp : the node wich the predecessor is searched.
             * @return : tmp's predecessor.
             */
			btree<Key, T>	*inorderSuccessor (btree<Key, T> *tmp)
			{
				if (tmp->l_flag == false)
					return (tmp->left);

				tmp = tmp->left;
				while (tmp->r_flag == true && tmp != this->_c_root)
					tmp = tmp->right;
				return (tmp);
			}

            /**
             * This function will delete a node wich have no child.
             * 
             * @tmp : the node to be deleted.
             * @node : the parent of tmp.
             */
            void    deleteNodeWithNoChild (btree<Key, T> *tmp)
            {
                if (tmp->previous == this->_c_root)               //need to delete root
                {
                    this->_c_root->left = NULL;
                    this->_c_root->l_flag = false;
                    this->_c_root->r_flag = false;
                    this->_c_root->left = this->_c_root;
                    this->_c_root->right = this->_c_root;
                }
                else if (tmp == tmp->previous->left)    //tmp is a left child
                {
					tmp->previous->l_flag = false;
					tmp->previous->left = tmp->left;
                    if (tmp->left == this->_c_root)
                        this->_c_root->right = tmp->previous;
                }
                else                            //tmp is right child
                {
					tmp->previous->r_flag = false;
					tmp->previous->right = tmp->right;
                    if (tmp->right == this->_c_root)
                        this->_c_root->left = tmp->previous;
                }
				this->_c_value_allocator.destroy(&tmp->element);
				this->_c_node_allocator.deallocate(tmp, 1);
            }

            /**
             * This function will delete a node wich have only a right child.
             * 
             * @tmp : the node to delete.
             * @node : the parent of tmp.
             */
            void    deleteNodeWithLeftChild (btree<Key, T> *tmp)
            {
                if (tmp->previous == this->_c_root)   //the node to delete is the root of the tree.
                {
                	tmp->left->previous = this->_c_root;
                    this->_c_root->right = tmp->left;
                    return ;
                }
                if (tmp->previous->right == tmp)
                    tmp->previous->right = tmp->left;
                else
                    tmp->previous->left = tmp->left;

                tmp->left->previous = tmp->previous;
				this->_c_value_allocator.destroy(&tmp->element);
				this->_c_node_allocator.deallocate(tmp, 1);
            }

            /**
             * This function will delete a node wich have only a left child.
             * 
             * @tmp : the node to delete.
             * @node : the parent of tmp.
             */
            void    deleteNodeWithRightChild (btree<Key, T> *tmp)
            {
                if (tmp->previous == this->_c_root)   //the node to delete is the root of the tree.
                {
					tmp->right->previous = this->_c_root;
					this->_c_root->right = tmp->right;
                    return ;
                }
                if (tmp->previous->left == tmp)
                    tmp->previous->left = tmp->right;
                else
                    tmp->previous->right = tmp->right;

                tmp->right->previous = tmp->previous;
				this->_c_value_allocator.destroy(&tmp->element);
				this->_c_node_allocator.deallocate(tmp, 1);
            }

            /**
             * This function will a node wich have two children.
             * 
             * @tmp : the node to delete.
             * @node : the parent of tmp.
             */
            void    deleteNodeWithTwoChildren (btree<Key, T> *tmp)
            {
            	tmp->element = rightNode(tmp->left)->element;
            	if (rightNode(tmp->left)->r_flag == false && rightNode(tmp->left)->l_flag == false)
            		deleteNodeWithNoChild(rightNode(tmp->left));
            	else if (rightNode(tmp->left)->r_flag == false)
            		deleteNodeWithLeftChild(rightNode(tmp->left));
            	else
					deleteNodeWithRightChild(rightNode(tmp->left));
            }

            /**
             * This function will redirect to the most appropriate function to delete a node.
             * 
             * @tmp : the node to delete.
             * @node : the parent of tmp.
             */
			void    eraseElement (btree<Key, T> *tmp)
            {
                if (tmp->l_flag == true && tmp->r_flag == true) //tmp has two children.
                    deleteNodeWithTwoChildren(tmp);
                else if (tmp->l_flag == true)                   //tmp has only a left child.
                    deleteNodeWithLeftChild(tmp);
                else if (tmp->r_flag == true)                   //tmp has only a left child.
                    deleteNodeWithRightChild(tmp);
                else                                            //tmp has no child.
                    deleteNodeWithNoChild(tmp);

                //the size of the tree is decreased by one.
                --this->_c_size;
            }

			/**
			 * Insert a node at the root of the tree.
			 *
			 * @param node : the new node.
			 * @param val : the value inserted.
			 * @return : a pair, with its member pair::first set to an iterator pointing to either the
			 * newly inserted element or to the element with an equivalent key in the map.
			 */
            ft::pair<iterator, bool>	insertRoot (btree<Key, T> *node, const value_type &val)
			{
				this->_c_value_allocator.construct(&node->element, val);
				node->right = this->_c_root->right;
				node->l_flag = this->_c_root->l_flag;
				node->r_flag = false;
				node->left = this->_c_root->left;

				//add the element at the right of the dummy_node
				node->previous = this->_c_root;
				this->_c_root->right = node;
				this->_c_size++;
				return (ft::pair<iterator, bool>(iterator(node), true));
			}

			/**
			 * Insert a node at the right of its parent.
			 *
			 * @param node : the parent node.
			 * @param val : the value inserted.
			 * @return : a pair, with its member pair::first set to an iterator pointing to either the
			 * newly inserted element or to the element with an equivalent key in the map.
			 */
			ft::pair<iterator, bool>	insertRightNode (btree<Key, T> *node, const value_type &val)
			{
				btree<Key, T>   *new_node = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&new_node->element, val);
				new_node->right = node->right;
				new_node->r_flag = node->r_flag;
				new_node->l_flag = false;
				new_node->left = node;

				//inserting node in the right
				node->r_flag = true;
				node->right = new_node;
				new_node->previous = node;
				this->_c_size++;
				return (ft::pair<iterator, bool>(iterator(new_node), true));
			}

			/**
			 * Insert a node at the left of its parent.
			 *
			 * @param node : the parent node.
			 * @param val : the value inserted.
			 * @return : a pair, with its member pair::first set to an iterator pointing to either the
			 * newly inserted element or to the element with an equivalent key in the map.
			 */
			ft::pair<iterator, bool>	insertLeftNode (btree<Key, T> *node, const value_type &val)
			{
				btree<Key, T>   *new_node = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&new_node->element, val);
				new_node->left = node->left;
				new_node->l_flag = node->l_flag;
				new_node->r_flag = false;
				new_node->right = node;

				//inserting node in the left
				node->l_flag = true;
				node->left = new_node;
				new_node->previous = node;
				this->_c_size++;
				return (ft::pair<iterator, bool>(iterator(new_node), true));
			}

            btree<Key, T>      *find_key (const key_type &k)
            {
                btree<Key, T>   *node = this->_c_root->right;

                if (node == NULL)
                    return (NULL);
                while (true)
                {
                    if (_cmp(k, node->element.first))
                    {
                        if (node->r_flag == false)		//INSERT NODE AT THE RIGHT OF ITS PARENT
                        	return (node);
                        else
                            node = node->right;
                    }
                    else if (_cmp(node->element.first, k))
                    {
                        if (node->l_flag == false)		//INSERT NODE AT THE LEFT OF ITS PARENT
							return (node);
                        else
                            node = node->left;
                    }
                    else
                        return (node);
                }
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
            map (const map& x): _c_value_allocator(x._c_value_allocator), _cmp(x._cmp)
            {
				this->_c_root = this->_c_node_allocator.allocate(1);
				this->_c_value_allocator.construct(&this->_c_root->element, value_type());
				this->_c_root->r_flag = true;
				this->_c_root->l_flag = false;
				this->_c_root->right = this->_c_root;
				this->_c_root->left = this->_c_root;
				this->_c_size = 0;
				if (x._c_root->right != NULL)
				{
                    insert(x.begin(), x.end());
				}
                else
                    this->_c_root = NULL;
            }

            /**
             * Destructor.
             */
            ~map (void)
            {
                clear();
            }

        //ITERATORS

            /**
             * Return iterator to beginning.
             * 
             * Returns an iterator referring to the first element in the map container.
             * 
             * @return : An iterator to the first element in the container.
             */
            iterator    begin (void)
            {
                btree<Key, T>       *node = this->_c_root->right;

                if (this->_c_size == 0)
					return (iterator(this->_c_root));
                while (node->r_flag == true)
                    node = node->right;
                return (iterator(node));
            }

            /**
             * Return const_iterator to beginning.
             * 
             * Returns a const_iterator referring to the first element in the map container.
             * 
             * @return : A const_iterator to the first element in the container.
             */
            const_iterator    begin (void) const
            {
                btree<Key, T>       *node = this->_c_root->right;

				if (this->_c_size == 0)
					return (const_iterator(this->_c_root));
                while (node->r_flag == true)
                    node = node->right;
                return (const_iterator(node));
            }

            /**
             * Return iterator to end.
             * 
             * Returns an iterator referring to the last element in the map container.
             * 
             * @return : An iterator to the last element in the container.
             */
            iterator    end (void)
            {
                return (iterator(this->_c_root));
            }

            /**
             * Return const_iterator to end.
             * 
             * Returns a const_iterator referring to the last element in the map container.
             * 
             * @return : A const_iterator to the last element in the container.
             */
            const_iterator    end (void) const
            {
                return (const_iterator(this->_c_root));
            }

            /**
             * Return reverse iterator to reverse begin.
             *
             * Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
             *
             * @return : an iterator to the reverse beginning of the sequence container.
             */
			reverse_iterator rbegin (void)
			{
				return (reverse_iterator(end()));
			}

			/**
			 * Return const reverse iterator to reverse begin.
			 *
			 * Returns a const reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
			 *
			 * @return : a const iterator to the reverse beginning of the sequence container.
			 */
			const_reverse_iterator rbegin (void) const
			{
				return (const_reverse_iterator(end()));
			}

			/**
			 * Return reverse iterator to reverse end.
			 *
			 * Returns a reverse iterator pointing to the first element in the container (i.e., its reverse end).
			 *
			 * @return : an iterator to the reverse end of the sequence container.
			 */
			reverse_iterator rend (void)
			{
				return (reverse_iterator(begin()));
			}

			/**
			 * Return const reverse iterator to reverse end.
			 *
			 * Returns a const reverse iterator pointing to the first element in the container (i.e., its reverse end).
			 *
			 * @return : a const iterator to the reverse end of the sequence container.
			 */
			const_reverse_iterator rend (void) const
			{
				return (reverse_iterator(begin()));
			}

        //CAPACITY

            /**
             * Test wether the container is empty.
             * 
             * Returns whether the map container is empty (i.e. whether its size is 0).
             * 
             * @return : true if the container size is 0, false otherwise.
             */
            bool empty (void) const
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
            size_type size (void) const
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
            size_type max_size (void) const
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
                node->l_flag = false;
                node->r_flag = false;
                node->right = NULL;
                node->left = NULL;
                node->previous = NULL;

                //INSERT ROOT
                if (this->_c_root->left == this->_c_root && this->_c_root->right == this->_c_root)
                	return (insertRoot(node, val));

                node = this->_c_root->right;
                while (true)
                {
                    if (_cmp(val.first, node->element.first))
                    {
                        if (node->r_flag == false)		//INSERT NODE AT THE RIGHT OF ITS PARENT
                        	return (insertRightNode(node, val));
                        else
                            node = node->right;
                    }
                    else if (_cmp(node->element.first, val.first))
                    {
                        if (node->l_flag == false)		//INSERT NODE AT THE LEFT OF ITS PARENT
							return (insertLeftNode(node, val));
                        else
                            node = node->left;
                    }
                    else
                        return (ft::pair<iterator, bool>(iterator(node), false));
                }
                return (ft::pair<iterator, bool>(iterator(node), false));
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
				btree<Key, T>		*tmp = this->_c_root->right;

				while (tmp)
				{
					if (_cmp(tmp->element.first, k))
					{
						if (tmp->l_flag == false)
                            return (0);
                        tmp = tmp->left;
					}
					else if (_cmp(k, tmp->element.first))
                    {
						if (tmp->r_flag == false)
                            return (0);
                        tmp = tmp->right;
					}
                    else
                    {
                        eraseElement(tmp);
                        return (1);
                    }
				}
                return (0);
			}

            /**
			 * Removes elements.
			 *
			 * Removes from the map container either a single element or a range of elements ([first,last)).
			 *
			 * @first / @last : Iterators specifying a range within the map container to be removed:
             * [first,last). i.e., the range includes all the elements between first and last, including
             * the element pointed by first but not the one pointed by last. Member types iterator and
             * const_iterator are bidirectional iterator types that point to elements.
			 * @return : The number of elements erased.
			 */
            void erase (iterator first, iterator last)
            {
                while (first != last)
                    erase(first++);
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
                btree<Key, T> 	*tmp = x._c_root;
                size_type		tmp_size = x.size();

                x._c_size = this->_c_size;
                this->_c_size = tmp_size;

                x._c_root = this->_c_root;
                this->_c_root = tmp;
            }

            /**
             * Clear content.
             * 
             * Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
             */
            void clear (void)
            {
            	if (this->_c_size > 0)
                	erase(begin(), end());
            }

        //OBSERVERS

        	/**
        	 * Value comparison object.
        	 */
			class value_compare
			{
				protected : //variable
					Compare cmp;

				protected : //func
					value_compare (Compare c) : cmp(c) {}

				public:
					value_compare () : cmp(Compare()) {}
					value_compare (const value_compare &c) : cmp(c.cmp) {}
					value_compare &operator=(const value_compare &c) { cmp = c.cmp; return (*this); }
					typedef bool result_type;
							typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type &x, const value_type &y)
					{
						return (cmp(x.first, y.first));
					}
			};

			/**
			 * Return key comparison object.
			 *
			 * Returns a copy of the comparison object used by the container to compare keys.
			 *
			 * @return : The comparison object.
			 */
			key_compare     key_comp (void) const
			{
				return (_cmp);
			}

			/**
			 * Return value comparison object.
			 *
			 * Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
			 *
			 * @return : The comparison object for element values.
			 */
			value_compare     value_comp (void) const
			{
				return (value_compare());
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
                iterator    it = begin();

                if (this->_c_size == 0)
                    return (end());
                while (it != this->end())
                {
                    if (k == it->first)
                        return (it);
                    it++;
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
                iterator    it = begin();
                
                if (this->_c_size == 0)
                    return (end());
                while (it != this->end())
                {
                    if (k == it->first)
                        return (it);
                    it++;
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

            /**
             * Return iterator to lower bound.
             *
             * Returns an iterator pointing to the first element in the container whose key is
             * not considered to go before k (i.e., either it is equivalent or goes after).
             *
             * @k : Key to search for.
             * @return : An iterator to the the first element in the container whose key is
             * not considered to go before k, or map::end if all keys are considered to go before k.
             */
			iterator lower_bound (const key_type& k)
			{
            	for (iterator it = begin(); it != end(); it++)
				{
            		if (!_cmp(it->first, k))
            			return (it);
				}
            	return (end());
			}

			/**
			 * Return const_iterator to lower bound.
			 *
			 * Returns an iterator pointing to the first element in the container whose key is
			 * not considered to go before k (i.e., either it is equivalent or goes after).
			 *
			 * @k : Key to search for.
			 * @return : A const_iterator to the the first element in the container whose key is
			 * not considered to go before k, or map::end if all keys are considered to go before k.
			 */
			const_iterator lower_bound (const key_type& k) const
			{
				for (const_iterator it = begin(); it != end(); it++)
				{
					if (!_cmp(it->first, k))
						return (it);
				}
				return (end());
			}

			/**
			 * Return iterator to upper bound.
			 *
			 * Returns an iterator pointing to the first element in the container whose key is considered to go after k.
			 *
			 * @param k : Key to search for.
			 * @return : An iterator to the the first element in the container whose key is considered to go after k,
			 * or map::end if no keys are considered to go after k.
			 */
			iterator upper_bound (const key_type& k)
			{
				for (iterator it = begin(); it != end(); it++)
				{
					if (_cmp(k, it->first))
						return (it);
				}
				return (end());
			}

			/**
			 * Return const_iterator to upper bound.
			 *
			 * Returns a const_iterator pointing to the first element in the container whose key is considered to go after k.
			 *
			 * @param k : Key to search for.
			 * @return : A const_iterator to the the first element in the container whose key is considered to go after k,
			 * or map::end if no keys are considered to go after k.
			 */
			const_iterator upper_bound (const key_type& k) const
			{
				for (const_iterator it = begin(); it != end(); it++)
				{
					if (_cmp(k, it->first))
						return (it);
				}
				return (end());
			}

			/**
			 * Get range of equal elements.
			 *
			 * Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
			 *
			 * @param k : Key to search for.
			 * @return : The function returns a pair, whose member pair::first is the lower bound of the range
			 * (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).
			 */
			ft::pair<iterator, iterator>             equal_range (const key_type& k)
			{
				return (ft::pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
			}

			/**
			 * Get range of equal elements.
			 *
			 * Returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.
			 *
			 * @param k : Key to search for.
			 * @return : The function returns a pair, whose member pair::first is the lower bound of the range
			 * (the same as lower_bound), and pair::second is the upper bound (the same as upper_bound).
			 */
			ft::pair<const_iterator, const_iterator>             equal_range (const key_type& k) const
			{
				return (ft::pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
			}

        //OPERATORS

            bool operator== (const map &x) const
            {
                iterator         itx(x.begin());

                if (x.size() != this->_c_size)
                    return (false);
                for (iterator it = begin(); it != end(); it++)
                {
                    if ((it->first != itx->first || it->second != itx->second))
                        return (false);
                    ++itx;
                }
                return (true);
            }
            bool operator!= (const map &x) const
            {
                return (!(*this == x));
                /*iterator         itx(x.begin());

                if (x.size() == this->_c_size)
                    return (false);
                for (iterator it = begin(); it != end(); it++)
                {
                    if ((it->first != itx->first || it->second != itx->second))
                        return (true);
                    ++itx;
                }
                return (false);*/
            }

            bool operator< (const map &x) const
            {
                const_iterator    xit(x.begin());
                const_iterator    xlast(x.end());
                const_iterator    tit(this->begin());
                const_iterator    tlast(this->end());
                
                while (tit != tlast)
                {
                    if (xit == xlast || *xit < *tit)
                        return 0;
                    if (*tit < *xit)
                        return 1;
                    ++tit;
                    ++xit;
                }
                return (xit != xlast);
            }
            bool operator> (const map &x) const
            {
                return (x < *this);
            }
            bool operator>= (const map &x) const
            {
                return (!(*this < x));
            }
            bool operator<= (const map &x) const
            {
                return (!(x < *this));
            }

            /**
             * Swap content map.
             * 
             * Swap the content of x and y.
             * 
             * @x / @y : map containers.
             */
            void    swap(map<Key, T, Compare, Alloc> &x, map<Key, T, Compare, Alloc> &y)
            {
                x.swap(y);
            }
    };
}

#endif
