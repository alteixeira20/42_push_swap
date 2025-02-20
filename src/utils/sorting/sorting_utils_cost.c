/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:10:40 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/20 01:15:55 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	calculate_cost_a(t_stack *a, t_stack *target_node)
{
	int	len_a;

	len_a = ft_lst_size_ps(a);
	if (target_node->above_median)
		return (target_node->current_pos);
	return (len_a - target_node->current_pos);
}

static int	calculate_cost_b(t_stack *b, int len_b)
{
	if (b->above_median)
		return (b->current_pos);
	return (len_b - b->current_pos);
}

static int	calculate_total_cost(t_stack *b, int cost_a, int cost_b)
{
	if ((b->above_median && b->target_node->above_median)
		|| (!b->above_median && !b->target_node->above_median))
	{
		if (cost_a > cost_b)
			return (cost_a);
		return (cost_b);
	}
	return (cost_a + cost_b);
}

void	set_cost(t_stack *a, t_stack *b)
{
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_b = ft_lst_size_ps(b);
	while (b)
	{
		cost_b = calculate_cost_b(b, len_b);
		cost_a = calculate_cost_a(a, b->target_node);
		b->push_cost = calculate_total_cost(b, cost_a, cost_b);
		b = b->next;
	}
}

void	set_cheapest(t_stack *b)
{
	long	best_cost;
	t_stack	*best_node;

	best_cost = LONG_MAX;
	best_node = NULL;
	while (b)
	{
		if (b->push_cost < best_cost)
		{
			best_cost = b->push_cost;
			best_node = b;
		}
		b = b->next;
	}
	if (best_node)
		best_node->cheapest = true;
}
