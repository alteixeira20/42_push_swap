/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:06:02 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/11 22:41:46 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	parse_args(t_stack **a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**split_args;

	if (argc < 2)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			split_args = ft_split(argv[i], ' ');
			if (!split_args)
				return (0);
			j = 0;
			while (split_args[j])
			{
				if (check_errors(split_args[j], *a))
				{
					ft_free_array(split_args);
					return (0);
				}
				convert_and_add(a, split_args[j]);
				j++;
			}
			ft_free_array(split_args);
		}
		else
		{
			if (check_errors(argv[i], *a))
				return (0);
			convert_and_add(a, argv[i]);
		}
		i++;
	}
	return (1);
}
