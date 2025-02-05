/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:05:44 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/05 21:19:10 by paalexan         ###   ########.fr       */
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
	printf("%s:  Logic: [%s]\n", func, status);
}

void    test_sa(void)
{
	t_stack *a = ft_lstnew_ps(1);
	ft_lstadd_back_ps(&a, ft_lstnew_ps(2));

	sa(&a);

	const char *logic = (a->value == 2 && a->next->value == 1) ? "OK" : "KO";
	print_test_result("sa", logic);

	ft_lstclear_ps(&a);
}

void    test_sb(void)
{
	t_stack *b = ft_lstnew_ps(3);
	ft_lstadd_back_ps(&b, ft_lstnew_ps(4));

	sb(&b);

	const char *logic = (b->value == 4 && b->next->value == 3) ? "OK" : "KO";
	print_test_result("sb", logic);

	ft_lstclear_ps(&b);
}

void    test_ss(void)
{
	t_stack *a = ft_lstnew_ps(5);
	ft_lstadd_back_ps(&a, ft_lstnew_ps(6));

	t_stack *b = ft_lstnew_ps(7);
	ft_lstadd_back_ps(&b, ft_lstnew_ps(8));

	ss(&a, &b);

	const char *logic = (a->value == 6 && a->next->value == 5 &&
	                     b->value == 8 && b->next->value == 7) ? "OK" : "KO";
	print_test_result("ss", logic);

	ft_lstclear_ps(&a);
	ft_lstclear_ps(&b);
}

void    test_pb(void)
{
	t_stack *a = ft_lstnew_ps(10);
	ft_lstadd_back_ps(&a, ft_lstnew_ps(20));

	t_stack *b = NULL;

	pb(&b, &a);

	const char *logic = (b && b->value == 10 && a->value == 20) ? "OK" : "KO";
	print_test_result("pb", logic);

	ft_lstclear_ps(&a);
	ft_lstclear_ps(&b);
}

void    test_pa(void)
{
	t_stack *a = NULL;
	t_stack *b = ft_lstnew_ps(30);
	ft_lstadd_back_ps(&b, ft_lstnew_ps(40));

	pa(&a, &b);

	const char *logic = (a && a->value == 30 && b->value == 40) ? "OK" : "KO";
	print_test_result("pa", logic);

	ft_lstclear_ps(&a);
	ft_lstclear_ps(&b);
}

int main(void)
{
	test_sa();
	test_sb();
	test_ss();
	test_pb();
	test_pa();
	return (0);
}
