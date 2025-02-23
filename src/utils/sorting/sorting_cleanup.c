/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_cleanup.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 04:24:23 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/23 20:28:37 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static char	*get_op(t_ops *moves, int i)
{
	if (i < moves->count)
		return (moves->operation[i]);
	return (NULL);
}

int	is_op(t_ops *moves, int i, char *op)
{
	char	*operation;

	operation = get_op(moves, i);
	if (!operation)
		return (0);
	if (ft_strncmp(operation, op, ft_strlen(op)) == 0)
		return (1);
	return (0);
}

static int	perform_cleanup(t_ops *moves)
{
	int	i;
	int	cleaned;

	cleaned = 0;
	i = 0;
	while (i < moves->count)
	{
		if (get_op(moves, i) == NULL)
		{
			i++;
			continue ;
		}
		cleaned += clean_swap(moves, i);
		cleaned += clean_push(moves, i);
		cleaned += clean_rotate(moves, i);
		cleaned += clean_reverse(moves, i);
		i++;
	}
	return (cleaned);
}

void	optimize_moves(t_ops *moves)
{
	int	cleaned;
	int	total_optimizations;

	total_optimizations = 0;
	while (1)
	{
		cleaned = perform_cleanup(moves);
		if (cleaned == 0)
			break ;
		total_optimizations += cleaned;
	}
}
