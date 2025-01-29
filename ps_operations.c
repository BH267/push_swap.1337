/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:12:43 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/09 12:41:04 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_stack **a, int c)
{
	t_stack	*first;
	t_stack	*second;

	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	first->index += 1;
	second->index -= 1;
	if (c == 'a')
		write(1, "sa\n", 3);
	if (c == 'b')
		write(1, "sb\n", 3);
}

void	pa_pb(t_stack **a, t_stack **b, int c)
{
	t_stack	*tmp;

	if (*b == NULL)
		return ;
	tmp = *b;
	*b = tmp->next;
	tmp->next = *a;
	*a = tmp;
	if (c == 'a')
		write(1, "pa\n", 3);
	if (c == 'b')
		write(1, "pb\n", 3);
}

void	ra_rb(t_stack **a, int c)
{
	t_stack	*tmp;

	tmp = *a;
	*a = tmp->next;
	ft_lstadd_back(a, tmp);
	tmp->next = NULL;
	if (c == 'a')
		write(1, "ra\n", 3);
	if (c == 'b')
		write(1, "rb\n", 3);
}

void	rra_rrb(t_stack **a, int c)
{
	t_stack	*tmp;
	t_stack	*fin;

	if (!(*a))
		return ;
	tmp = ft_lstlast(*a);
	fin = *a;
	while (fin->next->next != NULL)
		fin = fin->next;
	tmp->next = *a;
	*a = tmp;
	fin->next = NULL;
	if (c == 'a')
		write(1, "rra\n", 4);
	if (c == 'b')
		write(1, "rrb\n", 4);
}
