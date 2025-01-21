/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handletfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 09:37:56 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/18 10:27:10 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	get_min(t_stack *a)
{
	t_stack	min;
	int		i;

	min.data = a->data;
	i = 1;
	while (a)
	{
		if (min.data > a->data)
		{
			min.data = a->data;
			min.index = i;
		}
		i++;
		a = a->next;
	}
	return (min);
}

void	sort_f4(t_stack **a, t_stack **b)
{
	t_stack	min;

	min = get_min(*a);
	if (min.index == 2)
	{
		sa_sb(a, 'a');
		pa_pb(b, a, 'b');
	}
	else if (min.index > 2)
	{
		while (min.data != (*a)->data)
			rra_rrb(a, 'a');
		pa_pb(b, a, 'b');
	}
	else
		pa_pb(b, a, 'b');
	sort_t(3, a);
	pa_pb(a, b, 'a');
}

void	sort_f5(t_stack **a, t_stack **b)
{
	t_stack	min;

	min = get_min(*a);
	if (min.index == 2)
	{
		sa_sb(a, 'a');
		pa_pb(b, a, 'b');
	}
	else if (min.index > 2)
	{
		while (min.data != (*a)->data)
			rra_rrb(a, 'a');
		pa_pb(b, a, 'b');
	}
	else
		pa_pb(b, a, 'b');
	sort_f4(a, b);
	pa_pb(a, b, 'a');
}

void	sort_tf(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		sort_t(2, a);
	if (size == 3)
		sort_t(3, a);
	if (size == 4)
		sort_f4(a, b);
	if (size == 5)
		sort_f5(a, b);
//	free(*a);
//	free(*b);
}
