/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:53:28 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/13 17:53:32 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int		data;
	int		index;
	struct s_stack	*next;
}	t_stack;

void	print_stack(t_stack *a);
int	ft_isdigit(int n);
int	ft_atoi(char *str);
int	isorted(t_stack *a);
size_t	ft_strlen(char const *s);
char	*ft_strdup(const char *s);
void	ra_rb(t_stack **a, int c);
void	sa_sb(t_stack **a, int c);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
void	rra_rrb(t_stack **a, int c);
void	sort_t(int arg, t_stack **a);
void	rr(t_stack **a, t_stack **b);
void	sort_t(int arg, t_stack **a);
void	ss(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	bubble_sort(int *arr, int size);
char	**ft_split(char const *s, char c);
t_stack	*ft_lstnew(int content, int index);
void	pa_pb(t_stack **a, t_stack **b, int c);
void	sort_tf(t_stack **a, t_stack **b, int size);
void	ft_sort(t_stack **a, t_stack **b, int size);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

#endif
