/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:55:45 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/12 15:55:55 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

typedef struct s_lis
{
	int	*arr;
	int	*sub;
	int	*subsq;
	int	len;
}	t_lis;

int	binary_search(t_lis *data, int key)
{
	int	left;
	int	right;
	int	mid;

	left = 0;
	right = data->len;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if (data->arr[data->sub[mid]] >= key)
			right = mid;
		else
			left = mid + 1;
	}
	return (left);
}

int	*reconstruct_lis(t_lis *data)
{
	int	*lis;
	int	i;
	int	j;

	lis = (int *)malloc(data->len * sizeof(int));
	if (!lis)
		return (NULL);
	j = data->sub[data->len - 1];
	i = data->len - 1;
	while (i >= 0)
	{
		lis[i] = data->arr[j];
		j = data->subsq[j];
		i--;
	}
	free(data->sub);
	free(data->subsq);
	return (lis);
}

int	*find_lis(int *arr, int n, int *lis_len)
{
	t_lis	data;
	int	pos;
	int	i;

	if (n <= 0)
		return (NULL);
	data.arr = arr;
	data.sub = (int *)malloc(n * sizeof(int));
	data.subsq = (int *)malloc(n * sizeof(int));
	if (!data.sub || !data.subsq)
		return (NULL);
	data.len = 0;
	i = -1;
	while (++i < n)
	{
		pos = binary_search(&data, arr[i]);
		data.sub[pos] = i;
		if (pos > 0)
			data.subsq[i] = data.sub[pos - 1];
		else
			data.subsq[i] = -1;
		if (pos == data.len)
			data.len++;
	}
	*lis_len = data.len;
	return (reconstruct_lis(&data));
}

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

	lis = find_lis(arr, n, &lis_len);
	if (lis)
	{
		print_lis(lis, lis_len);
		free(lis);
	}
	return (0);
}
