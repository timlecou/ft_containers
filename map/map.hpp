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
            typedef ptrdiff_t                                   difference_type;
            typedef size_t                                      size_type;

        private:
			btree<Key, T>                       *_c_root;
            size_type                           _c_size;
            allocator_type				        _c_value_allocator;
			std::allocator<btree<Key, T> >	    _c_node_allocator;
			key_compare 						_cmp;
		
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
                this->_c_root = this->_c_node_allocator.allocate(1);
                this->_c_value_allocator.construct(&this->_c_root->element, value_type());
                this->_c_root->r_flag = true;
                this->_c_root->l_flag = false;
                this->_c_root->right = this->_c_root;
                this->_c_root->left = this->_c_root;
                this->_c_root->parent = NULL;
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
      //      template <class InputIterator>
    //        map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
  //          {
//
        //    }

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

        //MODIFIERS

			void	display (void)
			{
				inOrderHelper(this->_c_root);
			}

            void    insert (value_type new_element)
            {
                btree<Key, T>   *node = this->_c_node_allocator.allocate(1);

                //if there is no value in the tree
                if (this->_c_root->left == this->_c_root && this->_c_root->right == this->_c_root)
                {
                    this->_c_value_allocator.construct(&node->element, new_element);
                    node->left = this->_c_root->left;
                    node->l_flag = this->_c_root->l_flag;
                    node->r_flag = false;
                    node->right = this->_c_root->right;

                    //add the element at the left of the dummy_node
                    this->_c_root->left = node;
                    this->_c_root->l_flag = true;
                    this->_c_size++;
                    return ;
                }

                node = this->_c_root->left;
                while (true)
                {
                    if (_cmp(node->element.first, new_element.first))
                    {
                        btree<Key, T>   *new_node = this->_c_node_allocator.allocate(1);
                        this->_c_value_allocator.construct(&new_node->element, new_element);
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
                            return ;
                        }
                        else
                            node = node->right;
                    }
                    
                    else if (_cmp(new_element.first, node->element.first))
                    {
                        btree<Key, T>   *new_node = this->_c_node_allocator.allocate(1);
                        this->_c_value_allocator.construct(&new_node->element, new_element);
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
                            return ;
                        }
                        else
                            node = node->left;
                    }
                    else
                        break ;
                }
            }

		//	mapped_type& operator[] (const key_type& k)
        //  {
        //        
        //  }

            iterator    begin (void)
            {
                btree<Key, T>       *node = this->_c_root->left;

                while (node->l_flag == true)
                    node = node->left;
                return (iterator(node));
            }

            iterator    end (void)
            {
                return (iterator(this->_c_root));
            }
    };
}

#endif