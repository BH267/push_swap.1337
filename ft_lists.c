/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:43:54 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/26 18:48:51 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*n;

	if (!lst || !*lst)
		return ;
	while ((*lst) != NULL)
	{
		n = (*lst)->next;
		free(*lst);
		*lst = n;
	}
	lst = NULL;
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new || !lst)
		return ;
	new->next = *(lst);
	*lst = new;
}

t_stack	*ft_lstnew(int	content)
{
	t_stack	*n;

	n = malloc(sizeof(t_stack));
	if (!n)
		return (NULL);
	n->data = content;
	n->next = NULL;
	return (n);
}

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
