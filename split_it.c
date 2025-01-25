/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 09:36:20 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/20 09:39:44 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_endit(t_splt a)
{
	ft_atoi(a.arr[0], NULL, a);
	ft_free(a.arr, 2);
	exit(0);
}

t_splt	splitit(char *str)
{
	t_splt	splt;
	char	**av;
	int	i;

	if (!str[0])
		exit(1);
	splt = ft_split(str, ' ');
	if (splt.count == 1)
		ft_endit(splt);
	av = (char **)malloc((splt.count + 1) * sizeof(char *));
	av[0] = ft_strdup("0");
	i = 1;
	while (i < splt.count + 1)
	{
		av[i] = splt.arr[i - 1];
		i++;
	}

	free(splt.arr);
	splt.arr = av;
	return (splt);
}
