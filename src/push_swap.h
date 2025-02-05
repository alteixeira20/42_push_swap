/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:48:38 by paalexan          #+#    #+#             */
/*   Updated: 2025/02/05 15:52:00 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf_bonus.h"

// Linked List
typedef struct s_stack
{
	int				value;
	int				index;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// List Operations
t_stack	*ft_lstnew_ps(int value);
void	ft_lstadd_front_ps(t_stack **stack, t_stack *new);
void	ft_lstadd_back_ps(t_stack **stack, t_stack *new);
int		ft_lstsize_ps(t_stack *stack);
t_stack	*ft_lstlast_ps(t_stack *stack);
void	ft_lstclear_ps(t_stack *stack);
void	ft_lstindex_ps(t_stack *stack);

// Stack Operations
// Swap
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// Push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

// Rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
