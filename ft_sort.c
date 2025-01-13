/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:36:39 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/09 18:14:02 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **a, t_stack **b)
{
	while ( *a != NULL)
	{
		if (!(*b) || (*a)->data >= (*b)->data)
			pa_pb(b, a, 'b');
		else
		{
			pa_pb(a, b, 'a');
			ra_rb(a, 'a');
		}
	}
	while (*b != NULL)
		pa_pb(a, b, 'a');
}
