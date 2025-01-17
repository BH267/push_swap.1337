/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flists.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 12:29:57 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/09 12:39:13 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return ;
	new->next = *(lst);
	*lst = new;
}

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*n;

	if (!lst)
		return ;
	while ((*lst) != NULL)
	{
		n = (*lst)->next;
		free(*lst);
		*lst = n;
	}
	lst = NULL;
}
