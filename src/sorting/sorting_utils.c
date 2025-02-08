/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:03:36 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/08 15:26:52 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->index = i;
		stack = stack->next;
		i++;
	}
}

int	find_min_index(t_stack *stack)
{
	int		min;
	int		min_index;
	t_stack	*node;

	if (!stack)
		return (-1);
	min = stack->value;
	node = stack;
	min_index = 0;
	while (node)
	{
		if (node->value < min)
		{
			min = node->value;
			min_index++;
		}
		node = node->next;
	}
	return (min_index);
}
