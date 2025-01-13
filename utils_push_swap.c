/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 09:56:10 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/09 12:40:22 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int n)
{
	return ('0' <= n && n <= '9');
}

int	ft_atoi(char *nbr)
{
	int	n;
	int	s;

	s = 1;
	n = 0;
	while (!ft_isdigit(*nbr) && *nbr != '-' && *nbr != '+')
	{
		if ((9 <= *nbr && *nbr <= 13) || *nbr == 32)
			nbr++;
		else
			return (0);
	}
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			s = -1;
		nbr++;
	}
	while (ft_isdigit(*nbr))
	{
		n = n * 10 + (*nbr - '0');
		nbr++;
	}
	return (n * s);
}

t_stack	*ft_lstnew(int content, int index)
{
	t_stack	*n;

	n = malloc(sizeof(t_stack));
	if (!n)
		return (NULL);
	n->data = content;
	n->index = index;
	n->next = NULL;
	return (n);
}

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	ptr = malloc(ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
