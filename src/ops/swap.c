/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 23:48:12 by paalexan          #+#    #+#             */
/*   Updated: 2025/01/29 23:48:15 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **a)
{
	ft_lstswap(*a);
}

void	sb(t_list **b)
{
	ft_lstswap(*b);
}

void	ss(t_list **a, t_list **b)
{
	sa(*a);
	sb(*b);
}
