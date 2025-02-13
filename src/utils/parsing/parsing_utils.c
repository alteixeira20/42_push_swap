/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:20:11 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/13 19:33:41 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

long	ft_atol_ps(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			print_error();
		result = result * 10 + (str[i] - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && sign * result < INT_MIN))
			print_error();
		i++;
	}
	return (result * sign);
}

void	convert_and_add(t_stack **stack, const char *arg)
{
	int		num;
	t_stack	*new_node;

	num = ft_atol_ps(arg);
	new_node = ft_lst_new_ps(num);
	ft_lst_addbottom_ps(stack, new_node);
}
