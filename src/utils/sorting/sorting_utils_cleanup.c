/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils_cleanup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:19:34 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/23 20:27:17 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	clean_swap(t_ops *moves, int i)
{
	if (i + 1 < moves->count)
	{
		if ((is_op(moves, i, "sa") && is_op(moves, i + 1, "sb"))
			|| (is_op(moves, i, "sb") && is_op(moves, i + 1, "sa")))
		{
			free(moves->operation[i]);
			moves->operation[i] = ft_strdup("ss");
			remove_move(moves, i + 1);
			return (1);
		}
		if (is_op(moves, i, "sa") && is_op(moves, i + 1, "sa"))
		{
			remove_move(moves, i);
			remove_move(moves, i);
			return (1);
		}
	}
	return (0);
}

int	clean_push(t_ops *moves, int i)
{
	if (i + 1 < moves->count
		&& ((is_op(moves, i, "pa") && is_op(moves, i + 1, "pb"))
			|| (is_op(moves, i, "pb") && is_op(moves, i + 1, "pa"))))
	{
		remove_move(moves, i);
		remove_move(moves, i);
		return (1);
	}
	return (0);
}

int	clean_rotate(t_ops *moves, int i)
{
	if (i + 1 < moves->count)
	{
		if ((is_op(moves, i, "ra") && is_op(moves, i + 1, "rb"))
			|| (is_op(moves, i, "rb") && is_op(moves, i + 1, "ra")))
		{
			free(moves->operation[i]);
			moves->operation[i] = ft_strdup("rr");
			remove_move(moves, i + 1);
			return (1);
		}
		if (is_op(moves, i, "ra") && is_op(moves, i + 1, "rra"))
		{
			remove_move(moves, i);
			remove_move(moves, i);
			return (1);
		}
	}
	return (0);
}

int	clean_reverse(t_ops *moves, int i)
{
	if (i + 1 < moves->count)
	{
		if ((is_op(moves, i, "rra") && is_op(moves, i + 1, "rrb"))
			|| (is_op(moves, i, "rrb") && is_op(moves, i + 1, "rra")))
		{
			free(moves->operation[i]);
			moves->operation[i] = ft_strdup("rrr");
			remove_move(moves, i + 1);
			return (1);
		}
		if (is_op(moves, i, "rra") && is_op(moves, i + 1, "ra"))
		{
			remove_move(moves, i);
			remove_move(moves, i);
			return (1);
		}
	}
	return (0);
}
