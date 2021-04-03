#ifndef STRUCTURE_H
# define STRUCTURE_H

template <typename T>
struct	node
{
	T					content;
	struct	node		*previous;
	struct	node		*next;
};

#endif
