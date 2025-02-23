/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:48:12 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/20 18:15:41 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (ft_lst_size_ps(*stack) < 2)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a, t_ops *moves)
{
	swap(a);
	add_move(moves, "sa");
}

void	sb(t_stack **b, t_ops *moves)
{
	swap(b);
	add_move(moves, "sb");
}

void	ss(t_stack **a, t_stack **b, t_ops *moves)
{
	swap(a);
	swap(b);
	add_move(moves, "ss");
}
