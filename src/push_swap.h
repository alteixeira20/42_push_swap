/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:48:38 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/20 00:42:05 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf_bonus.h"
# include "../libft/gnl/get_next_line_bonus.h"
# include <stdbool.h>

// Linked List
typedef struct s_stack
{
	int				value;
	int				current_pos;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
}	t_stack;

// List Operations
t_stack	*ft_lst_new_ps(int value);
void	ft_lst_addtop_ps(t_stack **stack, t_stack *new);
void	ft_lst_addbottom_ps(t_stack **stack, t_stack *new);
int		ft_lst_size_ps(t_stack *stack);
t_stack	*ft_lst_last_ps(t_stack *stack);
void	ft_lst_clear_ps(t_stack **stack);
t_stack	*ft_lst_min_ps(t_stack *stack);
t_stack	*ft_lst_max_ps(t_stack *stack);
void	ft_lst_assignindex_ps(t_stack *stack);
t_stack	*ft_lst_findindex_ps(t_stack *stack, int index);

// Stack Operations
void	sa(t_stack **a, bool print_flag);
void	sb(t_stack **b, bool print_flag);
void	ss(t_stack **a, t_stack **b, bool print_flag);
void	pa(t_stack **a, t_stack **b, bool print_flag);
void	pb(t_stack **b, t_stack **a, bool print_flag);
void	ra(t_stack **a, bool print_flag);
void	rb(t_stack **b, bool print_flag);
void	rr(t_stack **a, t_stack **b, bool print_flag);
void	rra(t_stack **a, bool print_flag);
void	rrb(t_stack **b, bool print_flag);
void	rrr(t_stack **a, t_stack **b, bool print_flag);

// Parsing
long	ft_atol_ps(const char *str);
void	convert_and_add(t_stack **stack, const char *arg);
int		parse_args(t_stack **stack, int argc, char **argv);
int		check_errors(const char *arg, t_stack *stack);
void	print_error(void);

// Sorting
int		is_sorted(t_stack *stack);
int		calculate_cost_a(t_stack *a, t_stack *target_node);
void	set_cost(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);
void	set_current_position(t_stack *stack);
void	push_cheapest_to_a(t_stack **a, t_stack **b);
void	sort_small(t_stack **a, t_stack **b);
void	sort_large(t_stack **a, t_stack **b);

#endif
