/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:46:15 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/10 16:21:04 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	insertion_sort(t_stack **a, t_stack **b)
{
	int	min_pos;
	int	max_pos;

	assign_index(*a);
	while (ft_lstsize_ps(*a) > 5)
	{
		min_pos = find_min_index(*a);
		if (min_pos < ft_lstsize_ps(*a) / 2)
			while (find_min_index(*a) != 0)
				ra(a);
		else
			while (find_min_index(*a) != 0)
				rra(a);
		pb(b, a);
	}
	sort_small(a, b);
	while (*b)
	{
		max_pos = find_max_index(*b);
		if (max_pos < ft_lstsize_ps(*b) / 2)
			while (find_max_index(*b) != 0)
				rb(b);
		else
			while (find_max_index(*b) != 0)
				rrb(b);
		pa(a, b);
	}
}

void	sort_medium(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize_ps(*a);
	if (is_sorted(*a))
		return ;
	if (size <= 25)
		insertion_sort(a, b);
}
