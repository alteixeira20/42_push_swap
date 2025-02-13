/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size_ps.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:58:02 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/13 16:41:26 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	ft_lst_size_ps(t_stack *node)
{
	int	count;

	count = 0;
	while (node)
	{
		count++;
		node = node->next;
	}
	return (count);
}
