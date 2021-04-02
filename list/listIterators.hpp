#ifndef LISTITERATORS_HPP
# define LISTITERATORS_HPP
# include <iostream>
# include "../reverse_iterator.hpp"
# include "../utils.hpp"
# include "structure.h"

namespace	ft
{
	template <typename T>
	class	listConstIterator;

	template <typename T>
	class	listIterator
	{
		public:
			typedef	T					value_type;
			typedef	T					&reference;
			typedef	T	const			&const_reference;
			typedef	T					*pointer;
			typedef	T	const			*const_pointer;
			typedef	std::ptrdiff_t		difference_type;

		private:
			node<T>	*_i_container;

		public:

			/**
			 * Default constuctor.
			 */
			listIterator<T> (void)
			{
				this->_i_container = NULL;
			}

			/**
			 * Assignation constructor.
			 *
			 * @container : the container to assign.
			 */
			listIterator<T> (node<T> *container)
			{
				this->_i_container = container;
			}

			/**
			 * Copy constructor.
			 *
			 * @it : the iterator to copy.
			 */
			listIterator<T> (const listIterator<T> &it)
			{
				this->_i_container = it._i_container;
			}

			//OPERATORS

			/**
			 * Assignation operator.
			 *
			 * Copies all the elements from x into the container.
			 * @x : the iterator to assign.
			 * @return : *this.
			 */
			listIterator<T>	&operator= (const listIterator<T> &it)
			{
				this->_i_container = it._i_container;
				return (*this);
			}

			/**
			 * Assignation operator.
			 *
			 * Copies all the elements from x into the container.
			 * @x : the iterator to assign.
			 * @return : *this.
			 */
			listIterator<T>	&operator= (const listConstIterator<T> &it)
			{
				this->_i_container = &*it;
				return (*this);
			}

			operator	listConstIterator<T> (void)
			{
				return (listConstIterator<T>(this->_i_container));
			}

			/**
			 * Equality operator.
			 *
			 * @return : true if the 2 containers are equals, otherwise it returns false.
			 */
			bool	operator== (const listIterator<T> &it) const { return (it._i_container == _i_container); }

			/**
			 * Disequality operator.
			 *
			 * @return : true if the 2 containers are not equals, otherwise it returns false.
			 */
			bool	operator!= (const listIterator<T> &it) const { return (it._i_container != _i_container); }

			/**
			 * Dereference operator.
			 *
			 * @return : the value of the dereferenced container.
			 */
			reference	operator* (void) const { return (_i_container->content); }

			/**
			 * Dereference operator.
			 *
			 * @return : the value of the dereferenced container.
			 */
			pointer		operator-> (void) const { return (&_i_container->content); }

			/**
			 * Incrementation operator.
			 */
			listIterator<T>	operator++ (int n) { (void)n; _i_container = _i_container->next; return (listIterator<T>(_i_container->previous)); }

			/**
			 * Decrementation operator.
			 */
			listIterator<T>	operator-- (int n) { (void)n; _i_container = _i_container->previous; return (listIterator<T>(_i_container->next)); }

			/**
			 * Value incrementation operator.
			 */
			listIterator<T>	&operator++ (void) { _i_container = _i_container->next; return (*this); }

			/**
			 * Value decrementation operator.
			 */
			listIterator<T>	&operator-- (void) { _i_container = _i_container->previous; return (*this); }
	};

	template <typename T>
	class	listConstIterator
	{
		public:
			typedef	T					value_type;
			typedef	T					&reference;
			typedef	T	const			&const_reference;
			typedef	T					*pointer;
			typedef	T	const			*const_pointer;
			typedef	std::ptrdiff_t		difference_type;

		private:
			node<T>	*_i_container;

		public:

			/**
			 * Default constuctor.
			 */
			listConstIterator<T> (void)
			{
				this->_i_container = NULL;
			}

			/**
			 * Assignation constructor.
			 *
			 * @container : the container to assign.
			 */
			listConstIterator<T> (node<T> *container)
			{
				this->_i_container = container;
			}

			/**
			 * Copy constructor.
			 *
			 * @it : the iterator to copy.
			 */
			listConstIterator<T> (const listConstIterator<T> &it)
			{
				this->_i_container = it._i_container;
			}

			/**
			 * Copy constructor.
			 *
			 * @it : the iterator to copy.
			 */
			listConstIterator<T> (const listIterator<T> &it)
			{
				this->_i_container = reinterpret_cast<node<T> *>(&*it);
			}

			//OPERATORS

			/**
			 * Assignation operator.
			 *
			 * Copies all the elements from x into the container.
			 * @x : the iterator to assign.
			 * @return : *this.
			 */
			listConstIterator<T>	&operator= (const listConstIterator<T> &it)
			{
				this->_i_container = it._i_container;
				return (*this);
			}

			/**
			 * Assignation operator.
			 *
			 * Copies all the elements from x into the container.
			 * @x : the iterator to assign.
			 * @return : *this.
			 */
			listConstIterator<T>	&operator= (const listIterator<T> &it)
			{
				this->_i_container = reinterpret_cast<node<T> *>(&*it);
				return (*this);
			}

			operator	listIterator<T> (void)
			{
				return (listIterator<T>(this->_i_container));
			}

			/**
			 * Equality operator.
			 *
			 * @return : true if the 2 containers are equals, otherwise it returns false.
			 */
			bool	operator== (const listConstIterator<T> &it) const { return (it._i_container == _i_container); }

			/**
			 * Disequality operator.
			 *
			 * @return : true if the 2 containers are not equals, otherwise it returns false.
			 */
			bool	operator!= (const listConstIterator<T> &it) const { return (it._i_container != _i_container); }

			/**
			 * Dereference operator.
			 *
			 * @return : the value of the dereferenced container.
			 */
			const_reference	operator* (void) const { return (_i_container->content); }

			/**
			 * Dereference operator.
			 *
			 * @return : the value of the dereferenced container.
			 */
			pointer		operator-> (void) const { return (&_i_container->content); }

			/**
			 * Incrementation operator.
			 */
			listConstIterator<T>	operator++ (int n) { (void)n; _i_container = _i_container->next; return (*this); }

			/**
			 * Decrementation operator.
			 */
			listConstIterator<T>	operator-- (int n) { (void)n; _i_container = _i_container->previous; return (*this); }

			/**
			 * Value incrementation operator.
			 */
			listConstIterator<T>	&operator++ (void) { _i_container = _i_container->next; return (*this); }

			/**
			 * Value decrementation operator.
			 */
			listConstIterator<T>	&operator-- (void) { _i_container = _i_container->previous; return (*this); }
	};
}

#endif
