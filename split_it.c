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

t_splt	splitit(char *str)
{
	t_splt	splt;
	char	**av;
	int	i;

	splt = ft_split(str, ' ');
	av = (char **)malloc((splt.count + 1) * sizeof(char *));
	av[0] = ft_strdup("0");
	i = 1;
	while (i < splt.count + 1)
	{
		av[i] = splt.arr[i - 1];
		i++;
	}
	//free(splt.arr);
	splt.arr = av;
	//splt.count -= 1;
	return (splt);
}
