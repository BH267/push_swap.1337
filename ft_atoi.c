/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:03:06 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/16 16:10:23 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void isimposter(char c)
{
	if (c)
	{
		write(1, "Error\n", 6);
		exit(0);
	}
}

int	ft_atoi(char *nbr)
{
	int	n;
	int	s;

	s = 1;
	n = 0;
	while((9 <= *nbr && *nbr <= 13) || *nbr == 32)
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		if (*(nbr++) == '-')
			s = -1;
	if (!ft_isdigit(*nbr))
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	while (ft_isdigit(*nbr))
	{
		n = n * 10 + (*nbr - '0');
		nbr++;
	}
	isimposter(*nbr);
	return (n * s);
}



