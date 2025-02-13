/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:03:36 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/13 21:17:48 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	get_rotation_cost(t_stack *stack, t_stack *target)
{
	int	cost;

	cost = 0;
	while (stack && stack != target)
	{
		cost++;
		stack = stack->next;
	}
	return (cost);
}

void	assign_costs(t_stack *a, t_stack *b)
{
	int	mid_a;
	int	mid_b;

	mid_a = ft_lst_size_ps(a) / 2;
	mid_b = ft_lst_size_ps(b) / 2;
	while (b)
	{
		b->target_node = ft_lst_findindex_ps(a, b->index);
		b->cost_a = get_rotation_cost(a, b->target_node);
		b->cost_b = get_rotation_cost(b, b);
		if (b->cost_a > mid_a)
			b->cost_a = -(ft_lst_size_ps(a) - b->cost_a);
		if (b->cost_b > mid_b)
			b->cost_b = -(ft_lst_size_ps(b) - b->cost_b);
		b = b->next;
	}
}

t_stack	*find_cheapest_move(t_stack *b)
{
	t_stack	*cheapest_node;
	int		min_cost;
	int		current_cost;

	cheapest_node = b;
	min_cost = abs(b->cost_a) + abs(b->cost_b);
	while (b)
	{
		current_cost = abs(b->cost_a) + abs(b->cost_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest_node = b;
		}
		b = b->next;
	}
	return (cheapest_node);
}

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
