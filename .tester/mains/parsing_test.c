/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:20:00 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/06 19:26:12 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../src/push_swap.h"

void	print_test_result(const char *test, const char *status)
{
	ft_printf("%s: [%s]\n", test, status);
}

void	test_valid_parsing(void)
{
	t_stack *a = NULL;
	char *argv1[] = {"./push_swap", "1", "2", "3", "4", NULL};
	char *argv2[] = {"./push_swap", "42", NULL};

	parse_args(&a, 5, argv1);
	print_test_result("Valid Input 1 2 3 4", (ft_lstsize_ps(a) == 4) ? "OK" : "KO");
	ft_lstclear_ps(&a);

	parse_args(&a, 2, argv2);
	print_test_result("Valid Input 42", (ft_lstsize_ps(a) == 1) ? "OK" : "KO");
	ft_lstclear_ps(&a);
}

void	test_invalid_parsing(void)
{
	t_stack *a = NULL;
	char *argv1[] = {"./push_swap", "1", "a", "3", NULL};
	char *argv2[] = {"./push_swap", "1", "2", "2", "3", NULL};
	char *argv3[] = {"./push_swap", "2147483648", NULL};

	print_test_result("Invalid Input 1 a 3", parse_args(&a, 4, argv1) ? "KO" : "OK");
	print_test_result("Duplicate 1 2 2 3", parse_args(&a, 5, argv2) ? "KO" : "OK");
	print_test_result("Overflow 2147483648", parse_args(&a, 2, argv3) ? "KO" : "OK");
	ft_lstclear_ps(&a);
}

int	main(void)
{
	test_valid_parsing();
	test_invalid_parsing();
	return (0);
}
