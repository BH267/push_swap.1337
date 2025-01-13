/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:31:54 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/12 18:43:47 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	binary_search(t_lis *data, int k)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = data->len;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (data->arr[data->sublen[mid]] >= k)
			right = mid;
		else
			left = mid + 1;
	}
	return (left);
}

int	*fill_lis(t_lis *data)
{
	int	*lis;
	int	i;
	int	j;

	lis = (int *)malloc(data->len * sizeof(int));
	if (!lis)
		return (NULL);
	j = data->sublen[data->len - 1];
	i = data->len - 1;
	while (i >= 0)
	{
		lis[i] = data->arr[i];
		j = data->subsq[j];
		i--;
	}
	free(data->sublen);
	free(data->subsq);
	return (lis);
}

void	help_lis(t_lis *data, int n)
{
	int	i;
	int	pos;

	i = -1;
	while (++i < n)
	{
		pos = binary_search(data, data->arr[i]);
		data->sublen[pos] = i;
		if (pos > 0)
			data->subsq[i] = data->sublen[pos - 1];
		else
			data->subsq[i] = -1;
		if (data->len == pos)
			data->len++;
	}
}

int	*ft_lis(int *arr, int n, int *lislen)
{
	t_lis	data;

	if (n <= 0)
		return (NULL);
	data.arr = arr;
	data.sublen = (int *)malloc(n * sizeof(int));
	data.subsq = (int *)malloc(n * sizeof(int));
	if (!data.sublen || !data.subsq)
		return (NULL);
	data.len = 0;
	help_lis(&data, n);
	*lislen = data.len;
	return (fill_lis(&data));
}

/*\****************************************************************************\*/

void	print_lis(int *lis, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (i > 0)
			write(1, " ", 1);
		if (lis[i] >= 10)
			write(1, &(char){(lis[i] / 10) + '0'}, 1);
		write(1, &(char){(lis[i] % 10) + '0'}, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	int	arr[] = {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15};
	int	n = sizeof(arr) / sizeof(arr[0]);
	int	lis_len;
	int	*lis;

	lis = ft_lis(arr, n, &lis_len);
	if (lis)
	{
		print_lis(lis, lis_len);
		free(lis);
	}
	return (0);
}
