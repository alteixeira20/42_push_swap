/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:24:42 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/19 16:21:50 by paalexan         ###   ########.fr       */
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

void	rra(t_stack **a, bool print_flag)
{
	reverse_rotate(a);
	if (print_flag)
		ft_printf("rra\n");
}

void	rrb(t_stack **b, bool print_flag)
{
	reverse_rotate(b);
	if (print_flag)
		ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b, bool print_flag)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print_flag)
		ft_printf("rrr\n");
}
