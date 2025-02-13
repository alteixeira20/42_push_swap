/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_clear_ps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:04:11 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/13 16:40:53 by paalexan         ###   ########.fr       */
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
