/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:09:57 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/08 15:26:13 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_min_to_b(t_stack **a, t_stack **b)
{
	int	min_index;
	int	size;

	if (!a || !*a)
		return ;
	assign_index(*a);
	min_index = find_min_index(*a);
	size = ft_lstsize_ps(*a);
	while ((*a)->index != min_index)
	{
		if (min_index <= size / 2)
			ra(a);
		else
			rra(a);
	}
	pb(b, a);
}

static void	sort_2(t_stack **a)
{
	int	first;
	int	second;

	first = (*a)->value;
	second = (*a)->next->value;
	if (first > second)
		sa(a);
}

static void	sort_3(t_stack **a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*a))
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

static void	sort_5(t_stack **a, t_stack **b)
{
	while (ft_lstsize_ps(*a) > 3)
		push_min_to_b(a, b);
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize_ps(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
	{
		push_min_to_b(a, b);
		sort_3(a);
		pa(a, b);
	}
	else if (size == 5)
		sort_5(a, b);
}
