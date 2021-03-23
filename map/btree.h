#ifndef BTREE_H
# define BTREE_H
# include "pair.hpp"

template < class Key, class T>
struct btree
{
	ft::pair<Key, T>			element;
    btree						*parent;
    btree           			*right;
    btree           			*left;
    int 						color;
};

#endif