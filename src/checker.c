/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:00:00 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/19 18:00:06 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	apply_move(char *move, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(move, "sa\n", 3))
		sa(a, false);
	else if (!ft_strncmp(move, "sb\n", 3))
		sb(b, false);
	else if (!ft_strncmp(move, "ss\n", 3))
		ss(a, b, false);
	else if (!ft_strncmp(move, "pa\n", 3))
		pa(a, b, false);
	else if (!ft_strncmp(move, "pb\n", 3))
		pb(b, a, false);
	else if (!ft_strncmp(move, "ra\n", 3))
		ra(a, false);
	else if (!ft_strncmp(move, "rb\n", 3))
		rb(b, false);
	else if (!ft_strncmp(move, "rr\n", 3))
		rr(a, b, false);
	else if (!ft_strncmp(move, "rra\n", 4))
		rra(a, false);
	else if (!ft_strncmp(move, "rrb\n", 4))
		rrb(b, false);
	else if (!ft_strncmp(move, "rrr\n", 4))
		rrr(a, b, false);
	else
		return (0);
	return (1);
}

static int	read_and_apply_moves(t_stack **a, t_stack **b)
{
	char	*move;

	move = get_next_line(0);
	while (move)
	{
		if (!apply_move(move, a, b))
		{
			free(move);
			ft_lst_clear_ps(a);
			ft_lst_clear_ps(b);
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		move = get_next_line(0);
	}
	free(move);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_args(&a, argc, argv))
		return (1);
	if (!read_and_apply_moves(&a, &b))
		return (1);
	if (is_sorted(a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lst_clear_ps(&a);
	ft_lst_clear_ps(&b);
	return (0);
}
