#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_stack
{
	int		data;
	int		index;
	struct s_stack	*next;
} t_stack;

typedef	struct	s_lis
{
	int	*arr;
	int	*sublen;
	int	*subsq;
	int	len;
}	t_lis;

char	**ft_split(char const *s, char sep);
void    ft_sort(t_stack **a, t_stack **b);
int		ft_atoi(char *str);
size_t	ft_strlen(char const *s);
char	*ft_strdup(const char *s);
void    ra_rb(t_stack **a, int c);
void    sa_sb(t_stack **a, int c);
void    rra_rrb(t_stack **a, int c);
void    rr(t_stack **a, t_stack **b);
void    ss(t_stack **a, t_stack **b);
void    rrr(t_stack **a, t_stack **b);
void    pa_pb(t_stack **a, t_stack **b, int c);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstdelone(t_stack *lst);
void	ft_lstclear(t_stack **lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_lstnew(int content, int index);
t_stack	*ft_lstlast(t_stack *lst);


#endif
