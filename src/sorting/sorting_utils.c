/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:03:36 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/11 16:55:09 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	assign_index(t_stack *stack)
{
	t_stack	*current;
	t_stack	*compare;
	int		index;

	if (!stack)
		return ;
	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

int find_min_index(t_stack *stack)
{
	t_stack	*tmp;
	int		min_index;
	int		min_value;

	tmp = stack;
	min_index = tmp->index;
	min_value = tmp->value;
	while (tmp)
	{
		if (tmp->value < min_value)
		{
			min_value = tmp->value;
			min_index = tmp->index;
		}
		tmp = tmp->next;
	}
	return (min_index);
}

int	find_max_index(t_stack *stack)
{
	int		max;
	int		max_index;
	t_stack	*node;

	if (!stack)
		return (-1);
	max = stack->value;
	node = stack;
	max_index = 0;
	while (node)
	{
		if (node->value > max)
		{
			max = node->value;
			max_index++;
		}
		node = node->next;
	}
	return (max_index);
}
