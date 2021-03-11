#ifndef QUEUE_HPP
# define QUEUE_HPP
# include "../list/list.hpp"

namespace   ft
{
    /**
     * queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out),
     * where elements are inserted into one end of the container and extracted from the other.
     * 
     * queues are implemented as containers adaptors, which are classes that use an encapsulated object of a specific container class as its
     * underlying container, providing a specific set of member functions to access its elements. Elements are pushed into the "back" of
     * the specific container and popped from its "front".
     */
    template <class T, class Container = ft::list<T> >
    class queue
    {
        public:
            typedef	T			value_type;
			typedef	Container	container_type;
			typedef	size_t		size_type;

        private:
            container_type  _container;

        public:

            /**
             * Default constructor.
             * 
             * A container adaptor keeps internally a container object as data. This container object is a copy of the ctnr argument passed to the constructor, if any, otherwise it is an empty container.
             * 
             * @ctnr : Container object.
             */
            explicit queue (const container_type& ctnr = container_type())
            {
                this->_container = ctnr;
            }

            /**
             * Destructor.
             */
            ~queue (void) {}

            /**
             * Test wether container is empty.
             * 
             * Returns whether the queue is empty: i.e. whether its size is zero.
             * 
             * @return : true if the underlying container's size is 0, false otherwise.
             */
            bool empty() const
            {
                return (this->_container.empty());
            }

            /**
             * Return size.
             * 
             * Returns the number of elements in the queue.
             * 
             * @return : The number of elements in the underlying container.
             */
            size_type size() const
            {
                return (this->_container.size());
            }

            /**
             * Access next element.
             * 
             * Returns a reference to the next element in the queue.
             * @return : A reference to the next element in the queue.
             */
            value_type& front()
            {
                return (this->_container.front());
            }

            /**
             * Access next element.
             * 
             * Returns a reference to the next element in the queue.
             * @return : A reference to the next element in the queue.
             */
            const value_type& front() const
            {
                return (this->_container.front());
            }

            /**
             * Access last element.
             * 
             * Returns a reference to the last element in the queue. This is the "newest" element in the queue.
             * 
             * @return : A reference to the last element in the queue.
             */
            value_type& back()
            {
                return (this->_container.back());
            }

            /**
             * Access last element.
             * 
             * Returns a reference to the last element in the queue. This is the "newest" element in the queue.
             * 
             * @return : A reference to the last element in the queue.
             */
            const value_type& back() const
            {
                return (this->_container.back());
            }

            /**
             * Insert element.
             * 
             * Inserts a new element at the end of the queue, after its current last element.
             * 
             * @val : Value to which the inserted element is initialized.
             */
            void push (const value_type& val)
            {
                this->_container.push_back(val);
            }

            /**
             * Remove next element.
             * 
             * Removes the next element in the queue, effectively reducing its size by one.
             */
            void pop (void)
            {
                this->_container.pop_front();
            }

            bool operator== (const queue<T,Container>& rhs)
            {
                return (this->_container == rhs._container);
            }

            bool operator!= (const queue<T,Container>& rhs)
            {
                return (this->_container != rhs._container);
            }

            bool operator< (const queue<T,Container>& rhs)
            {
                return (!(this->_container >= rhs._container));
            }

            bool operator> (const queue<T,Container>& rhs)
            {
                return (!(this->_container <= rhs._container));
            }

            bool operator<= (const queue<T,Container>& rhs)
            {
                return (this->_container <= rhs._container);
            }

            bool operator>= (const queue<T,Container>& rhs)
            {
                return (this->_container >= rhs._container);
            }
    };
}

#endif