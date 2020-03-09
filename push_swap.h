/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:13:45 by armajchr          #+#    #+#             */
/*   Updated: 2019/11/01 10:47:56 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf/ft_printf.h"
# include "Libft/get_next_line.h"
# include <mlx.h>

# define F_RA	(1 << 0)
# define F_RR	(1 << 1)
# define F_RRR	(1 << 2)
# define F_TV	(1 << 3)

typedef struct		s_stack
{
	int				len;
	struct s_elem	*first;
	int				max;
	int				max2;
	int				max3;
	int				min;
	int				diff;
	int				pos;
}					t_stack;

typedef struct		s_elem
{
	int				nb;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_ope
{
	int	index;
	int	value;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
	int	rr;
	int	rrr;
	int	nb_ope;
	int	check;
	int	f;
	int	i;
	int	j;
	int	k;
	int	l;
}					t_ope;

int					ft_printf(const char *restrict format, ...);
char				*ft_itoa(long long nbr);
long long			ft_atoi(const char *str);
void				launch(t_stack *a, t_stack *b, t_elem *elem, t_ope *ok);
int					check(int ac, char **av, t_ope *ok);
int					check2(int ac, char **av, int i, int tmp);
int					check_digit(int i, int k, char **av);
t_stack				initstack(t_stack *a, t_elem *elem);
void				fill_stack(t_stack *a, int ac, char **av, t_ope *ok);
void				ft_print_stack(t_stack *a);
t_elem				*ft_create_elem(int nb, t_elem *elem);
void				ft_print_full(t_stack *a, t_stack *b);
void				ftab_init(t_stack *a, t_stack *b, char c);
char				find_func(char *line);
int					check_list(t_stack *a, t_stack *b);
int					check_list2(t_stack *a, t_stack *b);
int					almost_sort(t_stack *a, t_stack *b);
void				almost_sort2(t_stack *a, t_stack *b);
void				init_ope(t_ope *ok);
void				sort_tab(int i, int j, int *tab, t_stack *a);
void				max_4(t_stack *a, t_elem *tmp, int *tab);
void				clear1(t_ope *x, int result);
void				clear2(t_ope *x, int result);
void				clear3(t_ope *x, int result);
int					first_sort(t_stack *a, t_stack *b);
void				last_rev_b(t_stack *a, t_stack *b, t_ope *ok);
void				final_set(t_stack *a, t_stack *b, t_ope *ok);
void				launch(t_stack *a, t_stack *b, t_elem *elem, t_ope *ok);
void				launch2(t_stack *a, t_stack *b);
void				sort_main(t_stack *a, t_stack *b, t_ope *ok, t_ope *tc);
int					fill_ftab(t_stack *a, t_stack *b);
void				free_stack(t_stack *a);
void				free_stacks(t_stack *a, t_stack *b);
void				option(char **av, t_ope *ok);
int					small_sort(t_stack *a, t_stack *b, t_ope *ok);
void				last_sort(t_stack *a, t_stack *b, t_ope *ok);
int					exec_func(char *line, t_stack *a, t_stack *b);
int					exec_func2(char *line, t_stack *a, t_stack *b);

/*
**------------------Rules-----------------------------------------
*/

void				swap_a(t_stack *a, t_stack *b);
void				swap_b(t_stack *a, t_stack *b);
void				swap_ss(t_stack *a, t_stack *b);
void				push_a(t_stack *a, t_stack *b);
void				push_b(t_stack *a, t_stack *b);
void				rotate_a(t_stack *a, t_stack *b);
void				rotate_b(t_stack *a, t_stack *b);
void				rotate_rr(t_stack *a, t_stack *b);
void				rev_rotate_a(t_stack *a, t_stack *b);
void				rev_rotate_a2(t_stack *a, t_elem *tmp, t_elem *tmp2
						, t_elem *tmp3);
void				rev_rotate_b(t_stack *a, t_stack *b);
void				rev_rotate_r(t_stack *a, t_stack *b);

/*
**---------------------------Ope---------------------------------
*/

void				find_max_b(t_stack *b);
void				find_max(t_stack *a);
void				find_max2(t_stack *b, t_ope *ok);
void				find_max3(t_stack *a);
void				find_max4(t_stack *a);
void				rotate_max_a(t_stack *a, t_ope *ok);
void				push(t_stack *a, t_stack *b, t_ope *ok);
void				push2(t_stack *a, t_stack *b, t_ope *ok);
void				push3(t_stack *a, t_stack *b, t_ope *ok);
void				fill_ok_tc(t_stack *a, t_stack *b, t_ope *ok, t_ope *tc);
void				fill_ok_tc2(t_stack *a, t_stack *b, t_ope *ok, t_ope *tc);
void				fill_tc(t_stack *a, t_stack *b, t_ope *ok, t_ope *tc);
void				fill_ok(t_stack *b, t_ope *x);
void				fill_ok1(t_stack *b, t_ope *x);
int					fill_ok2(t_stack *b, t_ope *x);
void				fill_ok3(t_stack *b, t_ope *x);
int					check_max_a(t_ope *ok, t_stack *a);
void				swap_struct(t_ope *ok, t_ope *tc);
void				swap_struct2(t_ope *ok, t_ope *tc);
void				nb_ope(t_ope *ok);
void				nb_ope1(t_ope *ok);
void				nb_ope3(t_ope *x);
void				len_2(t_stack *a, t_stack *b);
void				len_3(t_stack *a, t_stack *b);
void				len_4(t_stack *a, t_stack *b);
int					len_5(t_stack *a, t_stack *b, t_ope *ok);
void				max_3(t_stack *a);

/*
**---------------------------Visu-------------------------------
*/

void				visu(t_ope *ok, t_stack *a, t_stack *b);
#endif
