#ifndef MAP_HPP
# define MAP_HPP
# include "btree.h"
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
    template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<pair<const Key,T> > >
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
            typedef ptrdiff_t                                   difference_type;
            typedef size_t                                      size_type;

        private:
            btree<Key, T>                       *_c_node;
            size_type                           _c_size;
            allocator_type				        _c_value_allocator;
			std::allocator<btree<Key, T> >	    _c_node_allocator;

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
                this->_c_node = this->_c_node_allocator.allocate(1);
                this->_c_value_allocator.construct(&this->_c_node->element, value_type());
                this->_c_node->rigth = NULL;
                this->_c_node->left = NULL;
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
                this->_c_node = x._c_node;
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

            
    };
}

#endif