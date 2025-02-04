/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:46:09 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/26 17:52:52 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = ac - 1;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	while (i > 0)
		ft_parsing(av[i--], &a);
	ft_isdup(&a);
	if (!isorted(a))
	{
		if (ft_size(a) <= 5)
			sort_tf(&a, &b, ft_size(a));
		else
			ft_sort(&a, &b, ft_size(a));
	}
	ft_lstclear(&a);
}
