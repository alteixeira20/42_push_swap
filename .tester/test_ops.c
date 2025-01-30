#include "../src/push_swap.h"
#include <stdlib.h>

// Print a stack (for debugging)
void	print_stack(t_list *stack, char *name)
{
	ft_printf("%s: ", name);
	while (stack)
	{
		ft_printf("%d -> ", ptr_to_int(stack->content));
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

void	del_noop(void *content)
{
	(void)content; // ✅ Does nothing (prevents segmentation fault)
}

// Test Swap Function (sa)
void	test_swap()
{
	ft_printf("\n=== Testing Swap (sa) ===\n");

	// Create Stack A: [3, 5, 7]
	t_list *a = ft_lstnew(int_to_ptr(3));
	ft_lstadd_back(&a, ft_lstnew(int_to_ptr(5)));
	ft_lstadd_back(&a, ft_lstnew(int_to_ptr(7)));

	ft_printf("\nBefore sa():\n");
	print_stack(a, "Stack A");

	// Perform swap
	sa(&a);

	ft_printf("\nAfter sa():\n");
	print_stack(a, "Stack A");

	// Free stack
	ft_lstclear(&a, del_noop);
}

// Test Push Functions (pa and pb)
void	test_push()
{
	ft_printf("\n=== Testing Push (pa and pb) ===\n");

	// Create Stack A: [3, 5, 7]
	t_list *a = ft_lstnew(int_to_ptr(3));
	ft_lstadd_back(&a, ft_lstnew(int_to_ptr(5)));
	ft_lstadd_back(&a, ft_lstnew(int_to_ptr(7)));

	// Create Stack B: [9, 10]
	t_list *b = ft_lstnew(int_to_ptr(9));
	ft_lstadd_back(&b, ft_lstnew(int_to_ptr(10)));

	ft_printf("\nBefore pb():\n");
	print_stack(a, "Stack A");
	print_stack(b, "Stack B");

	// Push from A to B
	pb(&b, &a);

	ft_printf("\nAfter pb():\n");
	print_stack(a, "Stack A");
	print_stack(b, "Stack B");

	// Push from B to A
	pa(&a, &b);

	ft_printf("\nAfter pa():\n");
	print_stack(a, "Stack A");
	print_stack(b, "Stack B");

	// Free stacks
	ft_lstclear(&a, del_noop);
	ft_lstclear(&b, del_noop);
}

// Main Test Runner
int	main()
{
	test_swap();
	test_push();
	return 0;
}

