/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex_ps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:08:25 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/05 21:31:37 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	cpy_node_to_array(t_stack *node, int *values)
{
	int	i;

	i = 0;
	while (node)
	{
		values[i++] = node->value;
		node = node->next;
	}
}

static void	sort_array(int *values, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (values[i] > values[j])
			{
				temp = values[i];
				values[i] = values[j];
				values[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_indices(t_stack *node, int *values, int size)
{
	int	i;

	while (node)
	{
		i = 0;
		while (i < size)
		{
			if (node->value == values[i])
			{
				node->index = i;
				break ;
			}
			i++;
		}
		node = node->next;
	}
}

void	ft_lstindex_ps(t_stack *node)
{
	int	*values;
	int	size;

	if (!node)
		return ;
	size = ft_lstsize_ps(node);
	values = (int *) malloc(size * sizeof(int));
	if (!values)
		return ;
	cpy_node_to_array(node, values);
	sort_array(values, size);
	assign_indices(node, values, size);
	free(values);
}
