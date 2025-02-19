/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:38:46 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/19 16:16:17 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	pa(t_stack **a, t_stack **b, bool print_flag)
{
	t_stack	*temp;

	if (!b || !(*b))
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lst_addtop_ps(a, temp);
	if (print_flag)
		ft_printf("pa\n");
}

void	pb(t_stack **b, t_stack **a, bool print_flag)
{
	t_stack	*temp;

	if (!a || !(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lst_addtop_ps(b, temp);
	if (print_flag)
		ft_printf("pb\n");
}
