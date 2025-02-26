/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:48:38 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/26 16:39:18 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf_bonus.h"
# include "../libft/gnl/get_next_line_bonus.h"
# include <stdbool.h>

# define MAX_OPS 10000

// Linked List for Operations
typedef struct s_ops
{
	char			*operation[MAX_OPS];
	int				count;
}	t_ops;

// Linked List for Stack
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

typedef struct s_general_data
{
	t_stack	**a;
	t_stack	**b;
	t_ops	*moves;
}	t_general;

typedef struct s_chunk
{
	int	min_idx;
	int	max_idx;
	int	mid_idx;
}	t_chunk;

// List Operations
t_stack	*ft_lst_new_ps(int value);
void	ft_lst_addtop_ps(t_stack **stack, t_stack *new);
void	ft_lst_addbottom_ps(t_stack **stack, t_stack *new);
int		ft_lst_size_ps(t_stack *stack);
t_stack	*ft_lst_last_ps(t_stack *stack);
void	ft_lst_clear_ps(t_stack **stack);
void	ft_lst_clear_ops(t_ops *moves);
t_stack	*ft_lst_min_ps(t_stack *stack);
t_stack	*ft_lst_max_ps(t_stack *stack);
void	ft_lst_assignindex_ps(t_stack *stack);
t_stack	*ft_lst_findindex_ps(t_stack *stack, int index);

// Stack Operations
void	sa(t_stack **a, t_ops *moves);
void	sb(t_stack **b, t_ops *moves);
void	ss(t_stack **a, t_stack **b, t_ops *moves);
void	pa(t_stack **a, t_stack **b, t_ops *moves);
void	pb(t_stack **b, t_stack **a, t_ops *moves);
void	ra(t_stack **a, t_ops *moves);
void	rb(t_stack **b, t_ops *moves);
void	rr(t_stack **a, t_stack **b, t_ops *moves);
void	rra(t_stack **a, t_ops *moves);
void	rrb(t_stack **b, t_ops *moves);
void	rrr(t_stack **a, t_stack **b, t_ops *moves);

// Parsing
long	ft_atol_ps(const char *str);
void	convert_and_add(t_stack **stack, const char *arg);
int		parse_args(t_stack **stack, int argc, char **argv);
int		check_errors(const char *arg, t_stack *stack);
int		print_error(void);

// Moves
void	mv_single(t_general *data, t_stack *target, t_stack *node);
void	mv_both(t_general *data, t_stack *target, t_stack *node);
void	mv_totop(t_general *data, t_stack *target, t_stack *node);
void	remove_move(t_ops *moves, int index);
void	add_move(t_ops *moves, const char *op);
void	print_final_moves(t_ops *moves);

// Sorting
int		is_sorted(t_stack *stack);
void	set_cost(t_stack *a, t_stack *b);
void	set_cheapest(t_stack *b);
void	init_nodes(t_stack *a, t_stack *b);
void	set_current_position(t_stack *stack);
void	push_cheapest_to_a(t_stack **a, t_stack **b, t_ops *moves);
void	push_chunks_to_b(t_stack **a, t_stack **b, t_ops *moves);
void	sort_small(t_stack **a, t_stack **b, t_ops *moves);
void	sort_large(t_stack **a, t_stack **b, t_ops *moves);

// Optimization and Cleaning
int		clean_swap(t_ops *moves, int i);
int		clean_push(t_ops *moves, int i);
int		clean_rotate(t_ops *moves, int i);
int		clean_reverse(t_ops *moves, int i);
int		is_op(t_ops *moves, int i, char *op);
void	optimize_moves(t_ops *moves);

#endif
