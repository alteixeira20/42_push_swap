/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:09:57 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/13 21:24:07 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	sort_2(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
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

static void	rotate_to_top(t_stack **stack, t_stack *target)
{
	int		size;
	int		pos;
	t_stack	*temp;

	size = ft_lst_size_ps(*stack);
	pos = 0;
	temp = *stack;
	while (temp && temp != target)
	{
		pos++;
		temp = temp->next;
	}
	if (pos <= size / 2)
		while (*stack != target)
			ra(stack);
	else
		while (*stack != target)
			rra(stack);
}

static void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*min_node;

	while (ft_lst_size_ps(*a) > 3)
	{
		ft_lst_assignindex_ps(*a);
		min_node = ft_lst_min_ps(*a);
		rotate_to_top(a, min_node);
		pb(b, a);
	}
	sort_3(a);
	if ((*b)->value < (*b)->next->value)
		sb(b);
	pa(a, b);
	pa(a, b);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lst_size_ps(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
	{
		ft_lst_assignindex_ps(*a);
		rotate_to_top(a, ft_lst_min_ps(*a));
		pb(b, a);
		sort_3(a);
		pa(a, b);
	}
	else if (size == 5)
		sort_5(a, b);
}
