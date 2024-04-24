#include "push_swap.h"

static void	sa(t_list **stack)
{
	    // Check if the list has at least two nodes
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_list *first = *stack;
    t_list *second = first->next;
    t_list *third = second->next;

    // Adjust next pointers
    first->next = third;
    if (third != NULL)
        third->previous = first;

    second->next = first;
    first->previous = second;
    second->previous = NULL;

    // Update head pointer if necessary
    *stack = second;
}

static void	sb(t_list **stack)
{
	    // Check if the list has at least two nodes
    if (*stack == NULL || (*stack)->next == NULL)
        return;

    t_list *first = *stack;
    t_list *second = first->next;
    t_list *third = second->next;

    // Adjust next pointers
    first->next = third;
    if (third != NULL)
        third->previous = first;

    second->next = first;
    first->previous = second;
    second->previous = NULL;

    // Update head pointer if necessary
    *stack = second;
}

t_list	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

static void	pa(t_list **stack_a, t_list **stack_b)
{
    if (*stack_b == NULL)
        return; // Stack A is empty, nothing to push
    t_list *top_b = *stack_b; // Get the top element of stack A
    *stack_b = (*stack_b)->next;
    top_b->next = *stack_a;
    if (*stack_a != NULL)
        (*stack_a)->previous = top_b;
    top_b->previous = NULL;
    *stack_a = top_b;
}

t_list	pb(t_list **stack_a, t_list **stack_b)
{
    if (*stack_a == NULL)
        return; // Stack A is empty, nothing to push
    
    t_list *top_a = *stack_a; // Get the top element of stack A
    *stack_a = (*stack_a)->next; // Move stack A pointer to the next element

    // Update pointers to push the top element of A onto B
    top_a->next = *stack_b;
    if (*stack_b != NULL)
        (*stack_b)->previous = top_a;
    top_a->previous = NULL; // Ensure previous of the pushed element points to NULL
    *stack_b = top_a;
}

t_list	ra()
{

}

t_list	rb()
{

}

t_list	rr()
{

}

t_list	rra()
{

}

t_list	rrb()
{

}

t_list	rrr()
{

}