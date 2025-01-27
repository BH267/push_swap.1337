/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bubble_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 15:06:11 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/27 15:06:20 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	swp;

	while (size--)
	{
		i = 0;
		while (i < size)
		{
			if (arr[i] > arr[i + 1])
			{
				swp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swp;
			}
			i++;
		}
	}
}

/*int	main()
{
	int	arr[] = {1, 4, 5, 10, -1, 50, 51, 9};
	int	i;

	bubble_sort(arr, sizeof(arr)/sizeof(arr[0]));
	i = 0;
	while (i < sizeof(arr)/sizeof(arr[0]))
		printf("%d\n", arr[i++]);
}*/
