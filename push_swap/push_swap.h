#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct s_list
{
	int			content;
	struct s_list	*next;
	struct s_list	*previous;
	int				index;
}	t_list;

#endif