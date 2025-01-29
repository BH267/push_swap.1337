/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: habenydi <habenydi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:58:09 by habenydi          #+#    #+#             */
/*   Updated: 2025/01/26 19:04:49 by habenydi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				data;
	int				index;
	struct s_stack	*next;
}	t_stack;

// sorting
int		isorted(t_stack *a);
void	sort_tf(t_stack **a, t_stack **b, int size);
void	ft_sort(t_stack **a, t_stack **b, int size);

// parcing
int		ft_isdup(t_stack **lst);
int		ft_parsing(char *s, t_stack **a);
void	ft_exit(t_stack **a, char **spl);

// oparators
void	sa_sb(t_stack **a, int c);
void	ra_rb(t_stack **a, int c);
void	rra_rrb(t_stack **a, int c);
void	pa_pb(t_stack **a, t_stack **b, int c);

// helper functions
int		sqr(double n);
int		ft_isdigit(int n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
int		ft_free(char **s, size_t i);
void	rankit(t_stack *a, int size);
void	bubble_sort(int *arr, int size);
int		*sorted_arr(t_stack *a, int size);
char	**ft_split(char const *s, char c);
int		ft_strncmp(char *s, char *p, size_t n);

// lists fonctions
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstclear(t_stack **lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

#endif
