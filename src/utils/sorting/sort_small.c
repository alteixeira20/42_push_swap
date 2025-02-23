/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:09:57 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/20 19:51:54 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	rotate_to_top(t_stack **stack, t_stack *target, t_ops *moves)
{
	int		size;
	int		pos;
	t_stack	*temp;

	size = ft_lst_size_ps(*stack);
	pos = 0;
	temp = *stack;
	while (temp && temp != target)
	{
		pos++;
		temp = temp->next;
	}
	if (pos <= size / 2)
		while (*stack != target)
			ra(stack, moves);
	else
		while (*stack != target)
			rra(stack, moves);
}

static void	sort_3(t_stack **a, t_ops *moves)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, moves);
	else if (first > second && second > third)
	{
		sa(a, moves);
		rra(a, moves);
	}
	else if (first > second && second < third && first > third)
		ra(a, moves);
	else if (first < second && second > third && first < third)
	{
		sa(a, moves);
		ra(a, moves);
	}
	else if (first < second && second > third && first > third)
		rra(a, moves);
}

static void	sort_4(t_stack **a, t_stack **b, t_ops *moves)
{
	t_stack	*min_node;

	ft_lst_assignindex_ps(*a);
	min_node = ft_lst_min_ps(*a);
	rotate_to_top(a, min_node, moves);
	pb(b, a, moves);
	sort_3(a, moves);
	pa(a, b, moves);
}

static void	sort_5(t_stack **a, t_stack **b, t_ops *moves)
{
	t_stack	*min_node;

	while (ft_lst_size_ps(*a) > 3)
	{
		ft_lst_assignindex_ps(*a);
		min_node = ft_lst_min_ps(*a);
		rotate_to_top(a, min_node, moves);
		pb(b, a, moves);
	}
	sort_3(a, moves);
	if ((*b)->value < (*b)->next->value)
		sb(b, moves);
	pa(a, b, moves);
	pa(a, b, moves);
}

void	sort_small(t_stack **a, t_stack **b, t_ops *moves)
{
	int	size;

	size = ft_lst_size_ps(*a);
	if (size == 2)
	{
		if ((*a)->value > (*a)->next->value)
			sa(a, moves);
	}
	else if (size == 3)
		sort_3(a, moves);
	else if (size == 4)
		sort_4(a, b, moves);
	else if (size == 5)
		sort_5(a, b, moves);
}
