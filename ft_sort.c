/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:28:14 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/13 19:00:24 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_sort2(t_stack **a, t_stack **b, int size);

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	int (*arr), (end), (start);
	end = size / 11;
	start = 0;
	arr = sorted_arr(*a, size);
	while (*a)
	{
		if (end + start > size)
			end = size - start - 1;
		if ((*a)->data < arr[start])
		{
			(pa_pb(b, a, 'b'), ra_rb(b, 'b'));
			start++;
		}
		else if ((*a)->data >= arr[start] && (*a)->data <= arr[end + start])
		{
			pa_pb(b, a, 'b');
			if ((*b)->next && (*b)->data < (*b)->next->data)
				sa_sb(b, 'b');
			start++;
		}
		else if ((*a)->data > arr[end])
			ra_rb(a, 'a');
	}
	ft_sort2(a, b, size);
}

void	ft_sort3(t_stack **a, t_stack **b, int *size, t_stack c)
{
	while (1)
	{
		if (c.data == (*b)->data)
		{
			pa_pb(a, b, 'a');
			*size -= 1;
			break ;
		}
		else if (c.index <= (*size) / 2)
		{
			ra_rb(b, 'b');
			c.index--;
		}
		else if (c.index > (*size) / 2)
		{
			rra_rrb(b, 'b');
			c.index++;
			if (c.index == *size)
				c.index = 0;
		}
	}
}

void	ft_sort2(t_stack **a, t_stack **b, int size)
{
	t_stack		bign;
	t_stack		*tmp;
	int		i;

	while (*b)
	{
		tmp = *b;
		bign.data = tmp->data;
		i = 0;
		while (tmp)
		{
			if (tmp->data > bign.data)
			{
				bign.data = tmp->data;
				bign.index = i;
			}
			i++;
			tmp = tmp->next;
		}
		ft_sort3(a, b, &size, bign);
	}
}
