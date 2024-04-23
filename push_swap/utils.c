#include "push_swap.h"

static void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *temp_lst;

    if (*lst != NULL)
    {
        temp_lst = *lst;
        while (temp_lst->next != NULL)
        {
            temp_lst = temp_lst->next;
        }
        temp_lst->next = new;
        new->previous = temp_lst; // Set the previous pointer of the new node
    }
    else
    {
        *lst = new;
        new->previous = NULL; // For the first node, previous pointer should be NULL
    }
}

static t_list	*ft_lstnew(int content)
{
	t_list	*newlst;

	newlst = malloc (sizeof(t_list));
	if (newlst == NULL)
		return (NULL);
	newlst->content = content;
	newlst->next = NULL;
	newlst->previous = NULL;
	return (newlst);
}


static void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

static void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*templst;
	t_list	*next;

	if (*lst == NULL || del == NULL)
		return ;
	templst = *lst;
	next = NULL;
	while (templst != NULL)
	{
		next = templst->next;
		free(templst);
		templst = next;
	}
	*lst = NULL;
}

/* void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*templst;

	if (!f || !del)
		return (NULL);
	newlst = NULL;
	templst = NULL;
	while (lst != NULL)
	{
		templst = ft_lstnew(f(lst->content));
		if (templst == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, templst);
		lst = lst->next;
	}
	return (newlst);
}

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
} */

static int	ft_atoi(const char *nptr)
{
	int	i;
	int	j;
	int	minus;
	int final;

	i = 0;
	j = 0;
	minus = 1;
	if (nptr == NULL)
    {
        printf("Error: nptr is NULL\n");
        return 0; // or handle the error as appropriate
    }
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		j = (j * 10) + (nptr[i] - '0');
		i++;
	}
	final = j * minus;
	//printf ("Atoi results: %d\n", final);
	return (final);
}






