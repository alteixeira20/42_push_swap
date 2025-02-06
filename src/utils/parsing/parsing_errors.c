/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:14:36 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/06 19:52:01 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static int	is_overflow(const char *arg)
{
	long	num;

	num = ft_atol_ps(arg);
	if (num < INT_MIN || num > INT_MAX)
		return (1);
	return (0);
}

static int	is_duplicate(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	check_errors(const char *arg, t_stack *stack)
{
	int	i;

	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	if (!arg[i])
		return (1);
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i] <= '9'))
			return (1);
		i++;
	}
	if (is_overflow(arg))
		return (1);
	if (is_duplicate(stack, ft_atol_ps(arg)))
		return (1);
	return (0);
}
