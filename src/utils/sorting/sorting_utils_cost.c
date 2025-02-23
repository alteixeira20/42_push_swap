/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_cost.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:10:40 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/23 19:48:42 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	calculate_cost(t_stack *node, int lst_len)
{
	if (node->above_median)
		return (node->current_pos);
	return (lst_len - node->current_pos);
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
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = ft_lst_size_ps(a);
	len_b = ft_lst_size_ps(b);
	while (b)
	{
		cost_b = calculate_cost(b, len_b);
		cost_a = calculate_cost(b->target_node, len_a);
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

void	push_cheapest_to_a(t_stack **a, t_stack **b, t_ops *moves)
{
	t_stack		*cheapest_node;
	t_stack		*temp;
	t_general	data;

	data.a = a;
	data.b = b;
	data.moves = moves;
	cheapest_node = NULL;
	temp = *b;
	while (temp)
	{
		if (temp->cheapest)
		{
			cheapest_node = temp;
			break ;
		}
		temp = temp->next;
	}
	if (!cheapest_node)
		return ;
	mv_totop(&data, cheapest_node->target_node, cheapest_node);
	pa(a, b, moves);
}
