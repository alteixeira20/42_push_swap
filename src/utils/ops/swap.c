/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:48:12 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/19 19:14:16 by paalexan         ###   ########.fr       */
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

void	sa(t_stack **a, bool print_flag)
{
	swap(a);
	if (print_flag)
		ft_printf("sa\n");
}

void	sb(t_stack **b, bool print_flag)
{
	swap(b);
	if (print_flag)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, bool print_flag)
{
	swap(a);
	swap(b);
	if (print_flag)
		ft_printf("ss\n");
}
