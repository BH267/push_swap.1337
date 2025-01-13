/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 21:41:50 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/09 21:50:13 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_rrb(t_stack **a, int c)
{
	t_stack	*tmp;
	t_stack	*fin;

	if (!(*a))
		return;
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

void	rrr(t_stack **a, t_stack **b)
{
	rra_rrb(a, 's');
	rra_rrb(b, 's');
	write(1, "rrr\n", 4);
}
