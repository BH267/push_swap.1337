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

int sqr(double n) {
    double guess = n / 2;
    double epsi = 0.000001;
    while ((guess * guess - n > epsi) || (n - guess * guess > epsi)) {
        guess = (guess + n / guess) / 2;
    }
    return ((int)guess);
}

int	*sorted_arr(t_stack *a, int size)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		arr[i] = a->data;
		a = a->next;
		i++;
	}
	bubble_sort(arr, size);
	return (arr);
}

void	rankit(t_stack *a, int size)
{
	int	*arr;
	int	i;

	arr = sorted_arr(a, size);
	while (a)
	{
		i = 0;
		while (i < size)
			if (a->data == arr[i++])
				a->index = i;
		a = a->next;
	}
	free(arr);
}

void	ft_backtoa(t_stack **a, t_stack **b, int size, t_stack max)
{
	while (1)
	{
		if (max.data == (*b)->data)
		{
			pa_pb(a, b, 'a');
			size -= 1;
			break ;
		}
		else if (max.index <= size / 2)
		{
			ra_rb(b, 'b');

		}
		else if (max.index > size / 2)
		{
			rra_rrb(b, 'b');
			max.index++;
			if (max.index == size)
				max.index = 0;
		}
	}
}

void	ft_get_max(t_stack **a, t_stack **b, int size)
{
	t_stack	*tmp;
	t_stack	max;
	int	i;

	while (*b)
	{
		tmp  = *b;
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
		ft_backtoa(a, b, size, max);
	}
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	int	end;
	int	start;

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
			ra_rb(a, 'a');
	}
	ft_get_max(a, b, size);
}
