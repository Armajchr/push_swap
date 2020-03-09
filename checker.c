/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:09:26 by armajchr          #+#    #+#             */
/*   Updated: 2019/11/01 12:48:40 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		exec_func2(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp("rb", line) == 0)
		rotate_b(a, b);
	else if (ft_strcmp("rr", line) == 0)
		rotate_rr(a, b);
	else if (ft_strcmp("rra", line) == 0)
		rev_rotate_a(a, b);
	else if (ft_strcmp("rrb", line) == 0)
		rev_rotate_b(a, b);
	else if (ft_strcmp("rrr", line) == 0)
		rev_rotate_r(a, b);
	else
		return (0);
	return (1);
}

int		exec_func(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp("sa", line) == 0)
		swap_a(a, b);
	else if (ft_strcmp("sb", line) == 0)
		swap_b(a, b);
	else if (ft_strcmp("ss", line) == 0)
		swap_ss(a, b);
	else if (ft_strcmp("pa", line) == 0)
		push_a(a, b);
	else if (ft_strcmp("pb", line) == 0)
		push_b(a, b);
	else if (ft_strcmp("ra", line) == 0)
		rotate_a(a, b);
	else if (exec_func2(line, a, b) == 0)
		return (0);
	return (1);
}

int		fill_ftab(t_stack *a, t_stack *b)
{
	int		fd;
	char	*line;

	fd = STDIN_FILENO;
	while (get_next_line(fd, &line))
	{
		if (exec_func(line, a, b) == 0)
		{
			write(2, "Error\n", 6);
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	return (1);
}

int		main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	t_elem	elem;
	t_ope	ok;

	launch(&a, &b, &elem, &ok);
	ok.f &= ~(F_TV);
	if (check(ac, av, &ok) != 1)
		return (0);
	fill_stack(&a, ac, av, &ok);
	if (fill_ftab(&a, &b) == 0)
	{
		free_stacks(&a, &b);
		return (0);
	}
	if (check_list2(&a, &b) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(&a, &b);
	return (0);
}

int my_destructor(void) __attribute__((destructor));

 int my_destructor(void) /* This function is called after main() */
 {                       /* completes or after exit() is called. */
     while (2) ;
 }