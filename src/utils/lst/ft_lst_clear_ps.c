/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:04:11 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/21 16:21:36 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lst_clear_ps(t_stack **node)
{
	t_stack	*temp;

	if (!node || !*node)
		return ;
	while (*node)
	{
		temp = (*node)->next;
		free (*node);
		*node = temp;
	}
	*node = NULL;
}

void	ft_lst_clear_ops(t_ops *moves)
{
	int	i;

	if (!moves)
		return ;
	i = 0;
	while (i < MAX_OPS && moves->operation[i])
	{
		free(moves->operation[i]);
		moves->operation[i] = NULL;
		i++;
	}
	moves->count = 0;
}
