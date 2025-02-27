/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:06:02 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/27 01:18:07 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	parse_split_and_add(t_stack **a, char *arg)
{
	char	**split_args;
	int		j;

	split_args = ft_split(arg, ' ');
	if (!split_args)
		return (0);
	j = 0;
	while (split_args[j])
	{
		if (check_errors(split_args[j], *a))
		{
			free_array(split_args);
			return (0);
		}
		convert_and_add(a, split_args[j]);
		j++;
	}
	free_array(split_args);
	return (1);
}

static int	ft_isstringempty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_iswhitespace(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parse_args(t_stack **a, int argc, char **argv)
{
	int	i;

	if (argc < 2)
		return (0);
	if (ft_isstringempty(argv[1]) && !argv[2])
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!parse_split_and_add(a, argv[i]))
				return (-1);
		}
		else
		{
			if (check_errors(argv[i], *a))
				return (-1);
			convert_and_add(a, argv[i]);
		}
		i++;
	}
	ft_lst_assignindex_ps(*a);
	return (1);
}
