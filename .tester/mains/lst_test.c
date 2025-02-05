/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:16:51 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/05 21:17:37 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/push_swap.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_test_result - Prints the logic test result only.
 * @func: Function name.
 * @status: Test status ("OK" or "KO").
 */
void    print_test_result(const char *func, const char *status)
{
	printf("ft_%s_ps:  Logic: [%s]\n", func, status);
}

void    test_lstnew(void)
{
	t_stack *node = ft_lstnew_ps(42);
	const char *logic = (node && node->value == 42 && node->next == NULL) ? "OK" : "KO";
	print_test_result("lstnew", logic);
	free(node);
}

void    test_lstadd_front(void)
{
	t_stack *stack = NULL;
	t_stack *new_node = ft_lstnew_ps(10);
	ft_lstadd_front_ps(&stack, new_node);

	const char *logic = (stack == new_node && stack->value == 10) ? "OK" : "KO";
	print_test_result("lstadd_front", logic);

	free(stack);
}

void    test_lstadd_back(void)
{
	t_stack *stack = ft_lstnew_ps(5);
	t_stack *new_node = ft_lstnew_ps(20);
	ft_lstadd_back_ps(&stack, new_node);

	const char *logic = (stack->next == new_node && new_node->value == 20) ? "OK" : "KO";
	print_test_result("lstadd_back", logic);

	free(stack);
	free(new_node);
}

void    test_lstsize(void)
{
	t_stack *stack = ft_lstnew_ps(1);
	ft_lstadd_back_ps(&stack, ft_lstnew_ps(2));
	ft_lstadd_back_ps(&stack, ft_lstnew_ps(3));

	const char *logic = (ft_lstsize_ps(stack) == 3) ? "OK" : "KO";
	print_test_result("lstsize", logic);

	ft_lstclear_ps(&stack);
}

void    test_lstlast(void)
{
	t_stack *stack = ft_lstnew_ps(1);
	t_stack *last_node = ft_lstnew_ps(99);
	ft_lstadd_back_ps(&stack, last_node);

	const char *logic = (ft_lstlast_ps(stack) == last_node) ? "OK" : "KO";
	print_test_result("lstlast", logic);

	ft_lstclear_ps(&stack);
}

void    test_lstclear(void)
{
	t_stack *stack = ft_lstnew_ps(1);
	ft_lstadd_back_ps(&stack, ft_lstnew_ps(2));
	ft_lstadd_back_ps(&stack, ft_lstnew_ps(3));
	ft_lstclear_ps(&stack);

	const char *logic = (!stack) ? "OK" : "KO";
	print_test_result("lstclear", logic);
}

void    test_lstindex(void)
{
	t_stack *stack = ft_lstnew_ps(10);
	ft_lstadd_back_ps(&stack, ft_lstnew_ps(5));
	ft_lstadd_back_ps(&stack, ft_lstnew_ps(15));
	ft_lstindex_ps(stack);

	const char *logic = (stack->index == 1 && stack->next->index == 0 && stack->next->next->index == 2) ? "OK" : "KO";
	print_test_result("lstindex", logic);

	ft_lstclear_ps(&stack);
}

int main(void)
{
	test_lstnew();
	test_lstadd_front();
	test_lstadd_back();
	test_lstsize();
	test_lstlast();
	test_lstclear();
	test_lstindex();
	return (0);
}
