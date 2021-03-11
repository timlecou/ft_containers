#ifndef BTREE_H
# define BTREE_H
# include "pair.hpp"

template < class Key, class T>
struct btree
{
    typedef Key                                         key_type;
    typedef T                                           mapped_type;
    typedef ft::pair<const key_type,mapped_type>        value_type;

    value_type      element;
    btree           *rigth;
    btree           *left;
};


#endif