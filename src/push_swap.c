/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:58:49 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/13 20:17:39 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **a, t_stack **b)
{
	if (ft_lst_size_ps(*a) <= 5)
		sort_small(a, b);
	//else
	//	sort_large(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	parse_args(&a, argc, argv);
	if (!a || is_sorted(a))
	{
		ft_lst_clear_ps(&a);
		return (0);
	}
	push_swap(&a, &b);
	ft_lst_clear_ps(&a);
	ft_lst_clear_ps(&b);
	return (0);
}
