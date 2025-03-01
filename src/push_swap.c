/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:58:49 by paalexan          #+#    #+#             */
/*   Updated: 2025/03/01 17:03:11 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_lists(t_stack **a, t_stack **b, t_ops *moves)
{
	ft_lst_clear_ps(a);
	ft_lst_clear_ps(b);
	ft_lst_clear_ops(moves);
}

static void	push_swap(t_stack **a, t_stack **b, t_ops *moves)
{
	int	size;

	size = ft_lst_size_ps(*a);
	if (size <= 5)
		sort_small(a, b, moves);
	else if (size <= 100)
	{
		while (ft_lst_size_ps(*a) > 5)
			pb(b, a, moves);
		sort_small(a, b, moves);
		sort_large(a, b, moves);
	}
	else
	{
		push_chunks_to_b(a, b, moves);
		sort_small(a, b, moves);
		sort_large(a, b, moves);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	moves;

	moves.count = 0;
	a = NULL;
	b = NULL;
	ft_memset(moves.operation, 0, sizeof(moves.operation));
	if (parse_args(&a, argc, argv) == -1)
	{
		free_lists(&a, &b, &moves);
		return (0);
	}
	if (is_sorted(a))
	{
		free_lists(&a, &b, &moves);
		return (1);
	}
	push_swap(&a, &b, &moves);
	optimize_moves(&moves);
	print_final_moves(&moves);
	free_lists(&a, &b, &moves);
	return (1);
}
