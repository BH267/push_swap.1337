/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 20:55:06 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/13 21:42:13 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_t(int arg, t_stack **a)
{
	t_stack	*tmp;

	tmp = (*a)->next->next;
	if (arg == 2 && !isorted(*a))
		sa_sb(a, 'a');
	if (arg == 3)
	{
		if ((*a)->data > (*a)->next->data)
			sa_sb(a, 'a');
		if ((*a)->next->data > tmp->data)
		{
			rra_rrb(a, 'a');
			if ((*a)->data > (*a)->next->data)
				sa_sb(a, 'a');
		}
	}
}

void	print_stack(t_stack *a)
{
	int 	i;
	i = 1;
	while (a)
	{
		printf("%d\n", a->data);
		if (a->next && i && a->data > a->next->data)
		{
			printf("hnaa :\(\n");
			i = 0;
		}
		a = a->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_splt	nbrs;
	int	i;

	b = NULL;
	a = NULL;
	nbrs.arr = av;
	nbrs.count = ac - 1;
	i = 0;
	if (ac == 1)
		return (0);
	if (ac == 2)
		nbrs = splitit(&nbrs.arr[1][0]);
	while (i++ < nbrs.count)
		ft_lstadd_back(&a, ft_lstnew(ft_atoi(&nbrs.arr[i][0], &a), i));
	ifdup(&a);
	if (!isorted(a))
	{
		if (nbrs.count <= 5)
			sort_tf(&a, &b, nbrs.count);
		else
			ft_sort(&a, &b, nbrs.count);
	}
	//print_stack(a);
	if (isorted(a))
		printf("OK!!!\n");
	else
		printf("No :\'\( \n");
	ft_lstclear(&a);
}
