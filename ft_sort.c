/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:34:06 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/27 14:35:29 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(t_stack **a, char **spl)
{
	ft_lstclear(a);
	ft_free(spl, 0);
	write(2, "Error\n", 6);
	exit(1);
}

void	ft_backtoa(t_stack **a, t_stack **b, int *size, t_stack max)
{
	while (1)
	{
		if (max.data == (*b)->data)
		{
			pa_pb(a, b, 'a');
			*size -= 1;
			break ;
		}
		else if (max.index <= *size / 2)
		{
			ra_rb(b, 'b');
			max.index--;
		}
		else if (max.index > *size / 2)
		{
			rra_rrb(b, 'b');
			max.index++;
			if (max.index == *size)
				max.index = 0;
		}
	}
}

void	ft_get_max(t_stack **a, t_stack **b, int size)
{
	t_stack	*tmp;
	t_stack	max;
	int		i;

	while (*b)
	{
		tmp = *b;
		max.data = tmp->data;
		i = 0;
		while (tmp)
		{
			if (tmp->data > max.data)
			{
				max.data = tmp->data;
				max.index = i;
			}
			i++;
			tmp = tmp->next;
		}
		ft_backtoa(a, b, &size, max);
	}
}

void	find_pos(t_stack **a, int len, int min, int max)
{
	t_stack	*tmp;
	int		pos;

	tmp = *a;
	pos = 0;
	while (tmp)
	{
		if (tmp->index >= min && tmp->index <= max)
			break ;
		tmp = tmp->next;
		pos++;
	}
	if (pos > len / 2)
	{
		while (pos++ < len)
			rra_rrb(a, 'a');
	}
	else
		ra_rb(a, 'a');
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	int (end), (start);
	start = 0;
	end = sqr(size) + (size / 500) + 6;
	rankit(*a, size);
	while (*a)
	{
		if ((*a)->index < start)
		{
			pa_pb(b, a, 'b');
			ra_rb(b, 'b');
			start++;
			end++;
		}
		else if ((*a)->index >= start && (*a)->index <= end)
		{
			pa_pb(b, a, 'b');
			if ((*b)->next && (*b)->data < (*b)->next->data)
				sa_sb(b, 'b');
			start++;
			end++;
		}
		else if ((*a)->index > end)
			find_pos(a, size, start, end);
	}
	ft_get_max(a, b, size);
}
