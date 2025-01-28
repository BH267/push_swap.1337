/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:53:29 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/26 18:37:04 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_puredigit(char *s)
{
	int	i;

	i = 0;
	while ((9 <= s[i] && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '\0')
		return (0);
	while (ft_isdigit(s[i]))
		i++;
	if (!s[i])
		return (1);
	return (0);
}

int	ft_psatoi(char *str, t_stack **a, char **spl)
{
	int		i;
	int		sign;
	size_t	n;

	i = 0;
	sign = 1;
	n = 0;
	if (!ft_strncmp(str, "2147483648", 10))
		return (ft_lstclear(a), write(2, "Error\n", 6), exit(1), 0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] <= '9' && str[i] >= '0')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
		if (n > 2147483648)
			return (ft_exit(a, &spl), 0);
	}
	return (n * sign);
}

int	ft_isspace(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_countwd(char **spl)
{
	int	i;

	i = 0;
	while (spl[i] != NULL)
		i++;
	return (i);
}

int	ft_parsing(char *s, t_stack **a)
{
	char	**spl;
	int		i;

	if (ft_puredigit(s))
		ft_lstadd_front(a, ft_lstnew(ft_psatoi(s, a, NULL)));
	else if (ft_isspace(s))
	{
		spl = ft_split(s, ' ');
		if (!spl || !*spl)
			return (ft_exit(a, &spl), 0);
		i = ft_countwd(spl) - 1;
		while (i >= 0)
		{
			if (ft_puredigit(spl[i]))
				ft_lstadd_front(a, ft_lstnew(ft_psatoi(spl[i], a, spl)));
			else
				return (ft_exit(a, &spl), 0);
			i--;
		}
		ft_free(spl, 0);
	}
	else
		return (ft_lstclear(a), write(2, "Error\n", 6), exit(1), 0);
	return (1);
}
