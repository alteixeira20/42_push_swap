/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:38:46 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/20 18:10:20 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_stack **a, t_stack **b, t_ops *moves)
{
	t_stack	*temp;

	if (!b || !(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lst_addtop_ps(a, temp);
	add_move(moves, "pa");
}

void	pb(t_stack **b, t_stack **a, t_ops *moves)
{
	t_stack	*temp;

	if (!a || !(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lst_addtop_ps(b, temp);
	add_move(moves, "pb");
}
