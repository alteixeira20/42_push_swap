/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:02:28 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/23 20:12:07 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	push_element(t_stack **a, t_stack **b, t_ops *moves, int mid_idx)
{
	pb(b, a, moves);
	if ((*b)->index < mid_idx)
		rb(b, moves);
}

static void	chunk_to_b(t_stack **a, t_stack **b, t_ops *moves, t_chunk *chunk)
{
	int	count;

	count = 0;
	while (ft_lst_size_ps(*a) > 3
		&& count < (chunk->max_idx - chunk->min_idx + 1))
	{
		if ((*a)->index >= chunk->min_idx && (*a)->index <= chunk->max_idx)
		{
			push_element(a, b, moves, chunk->mid_idx);
			count++;
		}
		else
			ra(a, moves);
	}
}

void	push_chunks_to_b(t_stack **a, t_stack **b, t_ops *moves)
{
	t_chunk	chunk;
	int		size;
	int		chunk_count;
	int		chunk_size;
	int		i;

	ft_lst_assignindex_ps(*a);
	size = ft_lst_size_ps(*a);
	chunk_count = 10;
	chunk_size = size / chunk_count;
	i = 0;
	while (i < chunk_count)
	{
		chunk.min_idx = i * chunk_size;
		chunk.max_idx = (i + 1) * chunk_size - 1;
		if (i == chunk_count - 1)
			chunk.max_idx = ft_lst_max_ps(*a)->index - 4;
		chunk.mid_idx = (chunk.min_idx + chunk.max_idx) / 2;
		chunk_to_b(a, b, moves, &chunk);
		i++;
	}
}
