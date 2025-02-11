/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:42:42 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/11 16:43:31 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	find_median(t_stack *stack)
{
	int		count;
	t_stack	*tmp;

	count = 0;
	tmp = stack;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count / 2);
}

static void	push_lower_half(t_stack **a, t_stack **b)
{
	int	median;
	int	size;
	int	pushed;

	median = find_median(*a);
	size = ft_lstsize_ps(*a);
	pushed = 0;
	while (pushed < size / 2)
	{
		if ((*a)->index < median)
		{
			pb(b, a);
			pushed++;
		}
		else
			ra(a);
	}
}

static void	move_smallest_to_top(t_stack **a)
{
	int		min_index;
	int		size;
	int		pos;
	t_stack	*tmp;

	min_index = find_min_index(*a);
	size = ft_lstsize_ps(*a);
	pos = 0;
	tmp = *a;
	while (tmp)
	{
		if (tmp->index == min_index)
			break ;
		pos++;
		tmp = tmp->next;
	}
	if (pos == 0)
		return ;
	if (pos <= size / 2)
		while ((*a)->index != min_index)
			ra(a);
	else
		while ((*a)->index != min_index)
			rra(a);
}

static void	push_back_sorted(t_stack **a, t_stack **b)
{
	while (*b)
	{
		pa(a, b);
		if (!is_sorted(*a))
			move_smallest_to_top(a);
	}
}

void	sort_large(t_stack **a, t_stack **b)
{
	if (is_sorted(*a))
		return ;
	assign_index(*a);
	push_lower_half(a, b);
	sort_small(a, b);
	push_back_sorted(a, b);
}
