#include "push_swap.h"
#include "utils.c"
#include "operations.c"

static void update_index_with_array(t_list **head, int arr[], int n) {
    t_list *current = *head;
    while (current != NULL) {
        // Find the index of current node's content in the array
        for (int i = 0; i < n; i++) {
            if (arr[i] == current->content) {
                current->index = i; // Update index with the array index
                break;
            }
        }
        current = current->next;
    }
}

static void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Unsorted array index %d: %d\n", i, arr[i]);
    }
    printf("\n");
}

static void print_array2(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Sorted array index %d: %d\n", i, arr[i]);
    }
    printf("\n");
}

static void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

static void index_stack(t_list **stack, int argc, char **argv)
{
	int	index_array[argc - 1];
	int i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		index_array[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	//print_array(index_array, j);
	bubble_sort(index_array, j);
	//print_array2(index_array, j);
	update_index_with_array(stack, index_array, j);

}
	

static void	initStack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	int		i;

	i = 1;
	while (argv[i])
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack, argc, argv);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (-1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	initStack(stack_a, argc, argv);
	*stack_b = *stack_a;
	while (*stack_b != NULL)
    {
        printf("Content value of index main %d: %d\n", (*stack_b)->index, (*stack_b)->content); // Assuming content is an integer pointer
        *stack_b = (*stack_b)->next;
    } 
	//printf("%d\n", (*stack_a)->previous->content);
	printf("head node pre swap:            %d\n", (*stack_a)->content);
	printf("second node pre swap:          %d\n", (*stack_a)->next->content);
	printf("third node previous pre swap:  %d\n", (*stack_a)->next->next->previous->content);
	sa(stack_a);
	printf("head node post swap:           %d\n", (*stack_a)->content);
	printf("second node post swap:         %d\n", (*stack_a)->next->content);
	printf("third node previous post swap: %d\n", (*stack_a)->next->next->previous->content);
	free(stack_a);
	free(stack_b);
	return (0);
}