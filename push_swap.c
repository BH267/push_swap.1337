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

/*void	handlit45(int arg, t_stack **a)
{
	 5 1 4 99
}*/

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	b = NULL;
	a = NULL;
	i = 0;
	if (ac == 1)
		return (0);
	if (ac == 2 && ft_atoi(&av[1][0]))
		return (0);
	while (i++ < ac - 1)
		ft_lstadd_back(&a,ft_lstnew(ft_atoi(&av[i][0]), i));
	sort_tf(&a, &b, ac - 1);
	//if (!isorted(a))
	//	ft_sort(&a, &b, ac - 1 );
	 print_stack(a);
	if (isorted(a))
		printf("OK!!!\n");
	else
		printf("No :\'\( \n");
}
