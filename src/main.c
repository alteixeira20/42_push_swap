/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:58:49 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/06 20:00:59 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack **a, t_stack **b)
{
	if (ft_lstsize_ps(*a) <= 5)
		sort_small(a);
	else if (ft_lstsize_ps(*a) <= 100)
		sort_medium(a, b);
	else
		sort_large(a, b);
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
		ft_lstclear_ps(&a);
		return (0);
	}
	push_swap(&a, &b);
	ft_lstclear_ps(&a);
	ft_lstclear_ps(&b);
	return (0);
}
