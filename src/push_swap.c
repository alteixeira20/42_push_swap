/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:58:49 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/20 01:51:31 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **a, t_stack **b)
{
	if (ft_lst_size_ps(*a) <= 5)
	{
		sort_small(a, b);
		ft_lst_clear_ps(a);
		ft_lst_clear_ps(b);
	}
	else
	{
		while (ft_lst_size_ps(*a) > 3)
			pb(b, a, true);
		sort_small(a, b);
		sort_large(a, b);
		ft_lst_clear_ps(a);
		ft_lst_clear_ps(b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (parse_args(&a, argc, argv) == -1)
	{
		print_error();
		ft_lst_clear_ps(&a);
		ft_lst_clear_ps(&b);
		return (0);
	}
	if (is_sorted(a))
	{
		ft_lst_clear_ps(&a);
		ft_lst_clear_ps(&b);
		return (1);
	}
	push_swap(&a, &b);
	return (1);
}
