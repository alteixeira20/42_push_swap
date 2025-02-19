/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_findindex_ps.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:22:40 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/19 19:15:28 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*ft_lst_findindex_ps(t_stack *stack, int value)
{
	t_stack	*target;
	int		min_val;

	target = NULL;
	min_val = INT_MAX;
	while (stack)
	{
		if (stack->value > value && stack->value < min_val)
		{
			min_val = stack->value;
			target = stack;
		}
		stack = stack->next;
	}
	if (!target)
		return (ft_lst_min_ps(stack));
	return (target);
}
