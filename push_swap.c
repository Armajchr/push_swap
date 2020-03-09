/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:25:43 by armajchr          #+#    #+#             */
/*   Updated: 2019/11/01 12:48:39 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	launch2(t_stack *a, t_stack *b)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if ((a->first->nb == a->max || a->first->nb == a->max2)
			|| ((a->first->nb == a->max3) && (a->len > 4)))
		{
			rotate_a(a, b);
			ft_printf("ra\n");
		}
		else
		{
			push_b(a, b);
			ft_printf("pb\n");
			i++;
		}
	}
	if (b->first->nb < b->first->next->nb)
	{
		swap_b(a, b);
		ft_printf("sb\n");
	}
}

void	last_rev_b(t_stack *a, t_stack *b, t_ope *ok)
{
	find_max2(b, ok);
	if (ok->index < b->len / 2)
	{
		while (b->first->nb != b->max)
		{
			rotate_b(a, b);
			ft_printf("rb\n");
		}
	}
	else
	{
		while (b->first->nb != b->max)
		{
			rev_rotate_b(a, b);
			ft_printf("rrb\n");
		}
	}
}

void	final_set(t_stack *a, t_stack *b, t_ope *ok)
{
	last_rev_b(a, b, ok);
	while (b->len > 0)
	{
		push_a(a, b);
		ft_printf("pa\n");
		if (b->len > 0)
			last_rev_b(a, b, ok);
	}
}

int		main(int ac, char **av)
{
	t_stack a;
	t_stack b;
	t_elem	elem;
	t_ope	ok;
	t_ope	tc;

	if (ac < 2)
		return (0);
	option(av, &ok);
	if (check(ac, av, &ok) != 1)
		return (0);
	launch(&a, &b, &elem, &ok);
	init_ope(&tc);
	fill_stack(&a, ac, av, &ok);
	visu(&ok, &a, &b);
	if (small_sort(&a, &b, &ok) == 0)
		return (0);
	while (a.len > 3)
	{
		sort_main(&a, &b, &ok, &tc);
		visu(&ok, &a, &b);
	}
	last_sort(&a, &b, &ok);
	return (0);
}
