/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 18:58:47 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/28 18:59:58 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sqr(double n)
{
	double	guess;
	double	epsi;

	guess = n / 2.0;
	epsi = 0.000001;
	while ((guess * guess - n > epsi) || (n - guess * guess > epsi))
	{
		guess = (guess + n / guess) / 2.0;
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

int	ft_isdup(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*checker;

	temp = *lst;
	while (temp)
	{
		checker = temp->next;
		while (checker)
		{
			if (temp->data == checker->data)
				return (ft_lstclear(lst), write(2, "Error\n", 6), exit(1), 0);
			checker = checker->next;
		}
		temp = temp->next;
	}
	return (1);
}
