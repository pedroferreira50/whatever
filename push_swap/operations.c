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
    t_list *first_a;
    t_list *second_a;
    t_list *first_b;
    t_list *second_b;

	if (*stack_a == NULL || (*stack_a)->next == NULL || *stack_b == NULL || (*stack_b)->next == NULL)
        return;
    first_a = *stack_a;
    second_a = first_a->next;
    first_b = *stack_b;
    second_b = first_b->next;
    first_a->next = second_b;
    first_b->next = second_a;
    if (second_a != NULL)
        second_a->previous = first_b;
    if (second_b != NULL)
        second_b->previous = first_a;
    if (second_a != NULL)
        *stack_a = second_a;
    if (second_b != NULL)
        *stack_b = second_b;
}

t_list	pb()
{

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