/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:57:22 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/09 11:11:11 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;
	int	i;

	i = ac - 1;
	a = ft_lstnew(ft_atoi(av[ac - 1]), ac - 1);
	tmp = a;
	while (i-- > 1)
	{
		tmp = ft_lstnew(ft_atoi(av[i]), i);
		tmp = tmp->next;
	}
	ft_sort(&a, &b);
	while (a != NULL)
	{
		printf("%d\n", a->data);
		a = a->next;
	}
}
