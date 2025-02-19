/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:12:32 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/19 16:17:55 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;

	if (ft_lst_size_ps(*stack) < 2)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	ft_lst_addbottom_ps(stack, first);
}

void	ra(t_stack **a, bool print_flag)
{
	rotate(a);
	if (print_flag)
		ft_printf("ra\n");
}

void	rb(t_stack **b, bool print_flag)
{
	rotate(b);
	if (print_flag)
		ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b, bool print_flag)
{
	rotate(a);
	rotate(b);
	if (print_flag)
		ft_printf("rr\n");
}
