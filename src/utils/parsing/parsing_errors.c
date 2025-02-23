/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:14:36 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/23 19:22:51 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

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
	if (!arg[i])
		return (print_error());
	if ((arg[i] == '+' || arg[i] == '-')
		&& arg[i + 1] >= '0' && arg[i + 1] <= '9')
		i++;
	while (arg[i])
	{
		if (!(arg[i] >= '0' && arg[i++] <= '9'))
			return (print_error());
	}
	if (is_duplicate(stack, ft_atol_ps(arg)))
		return (print_error());
	if (is_overflow(arg))
		return (print_error());
	return (0);
}
