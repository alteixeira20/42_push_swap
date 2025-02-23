/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:34:35 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/23 20:03:34 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	set_current_position(t_stack *stack)
{
	int	i;
	int	centerline;

	i = 0;
	centerline = ft_lst_size_ps(stack) / 2;
	while (stack)
	{
		stack->current_pos = i;
		stack->above_median = (i <= centerline);
		stack = stack->next;
		i++;
	}
}

void	sort_large(t_stack **a, t_stack **b, t_ops *moves)
{
	t_stack	*min_node;

	while (*b)
	{
		init_nodes(*a, *b);
		push_cheapest_to_a(a, b, moves);
	}
	min_node = ft_lst_min_ps(*a);
	while (*a != min_node)
	{
		if (min_node->above_median)
			ra(a, moves);
		else
			rra(a, moves);
	}
}
