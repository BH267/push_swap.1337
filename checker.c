/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:52:08 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/29 13:53:06 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_bexit(t_stack **a, t_stack **b, char *s)
{
	ft_lstclear(a);
	ft_lstclear(b);
	free(s);
	get_next_line(-1);
	write(2, "\033[38;2;255;255;0mError\n\033[0m", 27);
	exit(1);
}

int	ft_checker(t_stack **a, t_stack **b, char *s)
{
	if (ft_strncmp(s, "sa\n", 3) == 0)
		return (sa_sb(a, 'o'), 1);
	else if (ft_strncmp(s, "sb\n", 3) == 0)
		return (sa_sb(b, 'o'), 1);
	else if (ft_strncmp(s, "ss\n", 3) == 0)
		return (ss(a, b), 1);
	else if (ft_strncmp(s, "pa\n", 3) == 0)
		return (pa_pb(a, b, 'o'), 1);
	else if (ft_strncmp(s, "pb\n", 3) == 0)
		return (pa_pb(b, a, 'o'), 1);
	else if (ft_strncmp(s, "ra\n", 3) == 0)
		return (ra_rb(a, 'o'), 1);
	else if (ft_strncmp(s, "rb\n", 3) == 0)
		return (ra_rb(b, 'o'), 1);
	else if (ft_strncmp(s, "rr\n", 3) == 0)
		return (rr(a, b), 1);
	else if (ft_strncmp(s, "rra\n", 4) == 0)
		return (rra_rrb(a, 'o'), 1);
	else if (ft_strncmp(s, "rrb\n", 4) == 0)
		return (rra_rrb(b, 'o'), 1);
	else if (ft_strncmp(s, "rrr\n", 4) == 0)
		return (rrr(a, b), 1);
	else
		return (ft_bexit(a, b, s), 0);
}

void	khasiat_norm(t_stack **a, t_stack **b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		ft_checker(a, b, s);
		free(s);
		s = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack	*b;

	i = ac - 1;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	while (i > 0)
		ft_parsing(av[i--], &a);
	ft_isdup(&a);
	khasiat_norm(&a, &b);
	if (!b)
	{
		if (isorted(a))
		{
			ft_lstclear(&a);
			ft_lstclear(&b);
			return (write(1, "\033[38;2;0;255;0mOK\n\033[0m", 22), 0);
		}
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
	return (write(1, "\033[38;2;255;0;0mKO\n\033[0m", 22), 1);
}
