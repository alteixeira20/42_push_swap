/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_max_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 16:17:34 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/13 21:18:35 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_stack	*ft_lst_max_ps(t_stack *stack)
{
	t_stack	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack->value > max_node->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}
