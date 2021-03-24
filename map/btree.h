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
    bool						r_flag;
    bool                        l_flag;

    btree<Key, T> (void)
    {
        this->parent = NULL;
        this->right = NULL;
        this->left = NULL;
        this->r_flag = false;
        this->l_flag = false;
    }
};

#endif