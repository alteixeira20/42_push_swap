#include "../push_swap.h"

void	sa(t_list **a)
{
	ft_lstswap(*a);
}

void	sb(t_list **b)
{
	ft_lstswap(*b);
}

void	ss(t_list **a, t_list **b)
{
	sa(*a);
	sb(*b);
}
