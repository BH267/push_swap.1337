/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 16:11:38 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/24 16:12:04 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isnbr(char *nbr)
{

}

int kayn_space(char *str)
{
    int i;

    i = 0;
    while (str[i])
        if (str[i++] == ' ')
            return (1);
    return (0);
}

void    ft_isvalid(t_splt nbrs, t_stack **a)
{
    t_splt splt;
    int i;

    i = 0;
    while (i++ < nbrs.count)
    {
        if (!nbrs.arr[i])
            return;
        if (kayn_space(nbrs.arr[i]))
        {
            splt = ft_split(nbrs.arr[i], ' ');
            // int j = 0;
            //  while (splt.arr[j])
            //  {
            //      printf("==%s\n", splt.arr[j++]);
            //  }
            ft_isvalid(splt, a);
        }
        else
        {
            printf("==%s\n", nbrs.arr[i]);
            ft_lstadd_back(a, ft_lstnew(ft_atoi2(nbrs.arr[i ]), i));
        }
    }

}

void	print_stack(t_stack *a)
{
	// int 	i;
	// i = 1;
	while (a)
	{
		printf("%d\n", a->data);
		// if (a->next && i && a->data > a->next->data)
		// {
		// 	printf("hnaa :\(\n");
		// 	i = 0;
		// }
		a = a->next;
	}
}

int main(int ac, char **av)
{
	t_stack	*a;
	t_splt	nbrs;
	int	i;

	a = NULL;
	nbrs.arr = av;
	nbrs.count = ac - 1;
    ft_isvalid(nbrs, &a);
    print_stack(a);
}