/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:05:44 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/06 15:35:50 by paalexan         ###   ########.fr       */
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

void    test_ra(void)
{
	t_stack *a = ft_lstnew_ps(1);
	ft_lstadd_back_ps(&a, ft_lstnew_ps(2));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(3));

	ra(&a);

	const char *logic = (a->value == 2 && a->next->value == 3 && a->next->next->value == 1) ? "OK" : "KO";
	print_test_result("ra", logic);

	ft_lstclear_ps(&a);
}

void    test_rb(void)
{
	t_stack *b = ft_lstnew_ps(4);
	ft_lstadd_back_ps(&b, ft_lstnew_ps(5));
	ft_lstadd_back_ps(&b, ft_lstnew_ps(6));

	rb(&b);

	const char *logic = (b->value == 5 && b->next->value == 6 && b->next->next->value == 4) ? "OK" : "KO";
	print_test_result("rb", logic);

	ft_lstclear_ps(&b);
}

void    test_rr(void)
{
	t_stack *a = ft_lstnew_ps(7);
	ft_lstadd_back_ps(&a, ft_lstnew_ps(8));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(9));

	t_stack *b = ft_lstnew_ps(10);
	ft_lstadd_back_ps(&b, ft_lstnew_ps(11));
	ft_lstadd_back_ps(&b, ft_lstnew_ps(12));

	rr(&a, &b);

	const char *logic = (a->value == 8 && a->next->value == 9 && a->next->next->value == 7 &&
	                     b->value == 11 && b->next->value == 12 && b->next->next->value == 10) ? "OK" : "KO";
	print_test_result("rr", logic);

	ft_lstclear_ps(&a);
	ft_lstclear_ps(&b);
}

void    test_rra(void)
{
	t_stack *a = ft_lstnew_ps(13);
	ft_lstadd_back_ps(&a, ft_lstnew_ps(14));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(15));

	rra(&a);

	const char *logic = (a->value == 15 && a->next->value == 13 && a->next->next->value == 14) ? "OK" : "KO";
	print_test_result("rra", logic);

	ft_lstclear_ps(&a);
}

void    test_rrb(void)
{
	t_stack *b = ft_lstnew_ps(16);
	ft_lstadd_back_ps(&b, ft_lstnew_ps(17));
	ft_lstadd_back_ps(&b, ft_lstnew_ps(18));

	rrb(&b);

	const char *logic = (b->value == 18 && b->next->value == 16 && b->next->next->value == 17) ? "OK" : "KO";
	print_test_result("rrb", logic);

	ft_lstclear_ps(&b);
}

void    test_rrr(void)
{
	t_stack *a = ft_lstnew_ps(19);
	ft_lstadd_back_ps(&a, ft_lstnew_ps(20));
	ft_lstadd_back_ps(&a, ft_lstnew_ps(21));

	t_stack *b = ft_lstnew_ps(22);
	ft_lstadd_back_ps(&b, ft_lstnew_ps(23));
	ft_lstadd_back_ps(&b, ft_lstnew_ps(24));

	rrr(&a, &b);

	const char *logic = (a->value == 21 && a->next->value == 19 && a->next->next->value == 20 &&
	                     b->value == 24 && b->next->value == 22 && b->next->next->value == 23) ? "OK" : "KO";
	print_test_result("rrr", logic);

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
	test_ra();
	test_rb();
	test_rr();
	test_rra();
	test_rrb();
	test_rrr();
	return (0);
}
