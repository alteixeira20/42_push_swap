/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:24:42 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/20 18:11:24 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*before_last;

	if (ft_lst_size_ps(*stack) < 2)
		return ;
	last = ft_lst_last_ps(*stack);
	before_last = *stack;
	while (before_last->next && before_last->next->next)
		before_last = before_last->next;
	before_last->next = NULL;
	ft_lst_addtop_ps(stack, last);
}

void	rra(t_stack **a, t_ops *moves)
{
	reverse_rotate(a);
	add_move(moves, "rra");
}

void	rrb(t_stack **b, t_ops *moves)
{
	reverse_rotate(b);
	add_move(moves, "rrb");
}

void	rrr(t_stack **a, t_stack **b, t_ops *moves)
{
	reverse_rotate(a);
	reverse_rotate(b);
	add_move(moves, "rrr");
}
