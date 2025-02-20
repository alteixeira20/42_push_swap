/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:07:34 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/20 01:28:37 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	mv_both(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	if (target->above_median && node->above_median)
		rr(a, b, true);
	else if (!target->above_median && !node->above_median)
		rrr(a, b, true);
	else
	{
		if (target->above_median)
			ra(a, true);
		else
			rra(a, true);
		if (node->above_median)
			rb(b, true);
		else
			rrb(b, true);
	}
}

static void	mv_single(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	if (*a != target)
	{
		if (target->above_median)
			ra(a, true);
		else
			rra(a, true);
	}
	if (*b != node)
	{
		if (node->above_median)
			rb(b, true);
		else
			rrb(b, true);
	}
}

static void	mv_totop(t_stack **a, t_stack **b, t_stack *target, t_stack *node)
{
	while (*a != target || *b != node)
	{
		set_current_position(*a);
		set_current_position(*b);
		if (*a != target && *b != node)
			mv_both(a, b, target, node);
		else
			mv_single(a, b, target, node);
	}
}

void	push_cheapest_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;
	t_stack	*temp;

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
	mv_totop(a, b, cheapest_node->target_node, cheapest_node);
	pa(a, b, true);
}
