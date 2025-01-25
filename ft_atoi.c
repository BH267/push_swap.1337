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

void isimposter(char c, t_stack **a, t_splt nbrs)
{
	if (c)
	{
		write(1, "Error\n", 6);
		if (nbrs.count != nbrs.ac)
			ft_free(nbrs.arr, nbrs.count + 2);
		ft_lstclear(a);
		exit(1);
	}
}

int	ft_atoi(char *nbr, t_stack **a, t_splt splt)
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
		ft_free(splt.arr, splt.count + 2);
		ft_lstclear(a);
		exit(1);
	}
	while (ft_isdigit(*nbr))
	{
		n = n * 10 + (*nbr - '0');
		nbr++;
	}
	isimposter(*nbr, a, splt);
	return (n * s);
}

void	ifdup(t_stack **a, t_splt nbrs)
{
	t_stack	*tmp;
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		tmp = *a;
		while (tmp)
		{
			if (temp->data == tmp->data && temp->index != tmp->index)
			{
				ft_lstclear(a);
				if (nbrs.count != nbrs.ac)
					ft_free(nbrs.arr, nbrs.count + 2);
				write(1, "Error\n", 6);
				exit(1);
			}
			tmp = tmp->next;
		}
		temp = temp->next;
	}
}
