/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_moves.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 00:07:34 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/23 19:50:06 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	mv_both(t_general *data, t_stack *target, t_stack *node)
{
	if (target->above_median && node->above_median)
		rr(data->a, data->b, data->moves);
	else if (!target->above_median && !node->above_median)
		rrr(data->a, data->b, data->moves);
	else
	{
		if (target->above_median)
			ra(data->a, data->moves);
		else
			rra(data->a, data->moves);
		if (node->above_median)
			rb(data->b, data->moves);
		else
			rrb(data->b, data->moves);
	}
}

void	mv_single(t_general *data, t_stack *target, t_stack *node)
{
	if (*(data->a) != target)
	{
		if (target->above_median)
			ra(data->a, data->moves);
		else
			rra(data->a, data->moves);
	}
	if (*(data->b) != node)
	{
		if (node->above_median)
			rb(data->b, data->moves);
		else
			rrb(data->b, data->moves);
	}
}

void	mv_totop(t_general *data, t_stack *target, t_stack *node)
{
	while (*(data->a) != target || *(data->b) != node)
	{
		set_current_position(*(data->a));
		set_current_position(*(data->b));
		if (*(data->a) != target && *(data->b) != node)
			mv_both(data, target, node);
		else
			mv_single(data, target, node);
	}
}

void	remove_move(t_ops *moves, int index)
{
	if (index < 0 || index >= moves->count || moves->operation[index] == NULL)
		return ;
	free(moves->operation[index]);
	moves->operation[index] = NULL;
	while (index < moves->count - 1)
	{
		moves->operation[index] = moves->operation[index + 1];
		index++;
	}
	moves->operation[moves->count - 1] = NULL;
	moves->count--;
}

void	add_move(t_ops *moves, const char *op)
{
	if (!moves)
		return ;
	if (moves->count < MAX_OPS)
	{
		moves->operation[moves->count] = ft_strdup(op);
		if (!moves->operation[moves->count])
			return ;
		moves->count++;
	}
}
