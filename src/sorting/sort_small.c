/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:09:57 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/08 12:46:21 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_2(t_stack **a)
{
	int	first;
	int	second;

	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		sa(a);
}

static void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	int		min;
	t_stack	*node;

	min = (*a)->value;
	node = *a;
	while (node)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	while ((*a)->value != min)
	{
		ra(a);
	}
	pb (b, a);
}

static void	sort_4_5(t_stack **a, t_stack **b, int size)
{
	while (size > 3)
	{
		push_min_to_b(a, b);
		size--;
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize_ps(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size >= 4 && size <= 5)
		sort_4_5(a, b, size);
}
