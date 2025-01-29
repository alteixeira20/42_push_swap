/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paalexan <paalexan@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:48:38 by paalexan          #+#    #+#             */
/*   Updated: 2025/01/29 22:55:19 by paalexan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

// Functions for Type Casting (Make Code Cleaner)
static inline void	*int_to_ptr(int value)
{
	return ((void *)(long)value);
}

static inline int	ptr_to_int(void *ptr)
{
	return ((int)(long)ptr);
}

// Stack Operations
// Swap
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
// Push
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
// Rotate
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

#endif
