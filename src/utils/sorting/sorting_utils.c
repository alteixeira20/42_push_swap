/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:34:03 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/20 01:15:39 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
#include <limits.h>
#include <stdbool.h>

static t_stack	*get_closest_high_value(t_stack *a, int value, long *best_index)
{
	t_stack	*best_target;

	best_target = NULL;
	while (a)
	{
		if (a->value > value && a->value < *best_index)
		{
			*best_index = a->value;
			best_target = a;
		}
		a = a->next;
	}
	return (best_target);
}

static void	set_target_node(t_stack *a, t_stack *b)
{
	long	best_index;
	t_stack	*target_node;

	while (b)
	{
		best_index = LONG_MAX;
		target_node = get_closest_high_value(a, b->value, &best_index);
		if (!target_node)
			target_node = ft_lst_min_ps(a);
		if (best_index == LONG_MAX)
			b->target_node = ft_lst_min_ps(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_nodes(t_stack *a, t_stack *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}
