/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:29:33 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/31 16:24:30 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_list(t_stack *a, t_stack *b)
{
	t_elem	*tmp;
	int		i;

	i = 1;
	a->diff = 0;
	a->pos = 1;
	tmp = a->first;
	if (b->len > 0)
		return (0);
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
		{
			a->diff++;
			if (a->diff == 1)
				i = a->pos;
		}
		tmp = tmp->next;
		a->pos++;
	}
	if (a->diff == 1)
		a->pos = i;
	if (a->diff > 0)
		return (0);
	return (1);
}

int		check_list2(t_stack *a, t_stack *b)
{
	t_elem	*tmp;

	tmp = a->first;
	if (b->len > 0)
		return (0);
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	almost_sort2(t_stack *a, t_stack *b)
{
	if (a->pos < a->len / 2)
	{
		while (a->pos > 1)
		{
			rotate_a(a, b);
			ft_printf("ra\n");
			a->pos--;
		}
	}
	else
	{
		while (a->pos < a->len + 1)
		{
			rev_rotate_a(a, b);
			ft_printf("rra\n");
			a->pos++;
		}
	}
	swap_a(a, b);
	ft_printf("sa\n");
}

int		almost_sort(t_stack *a, t_stack *b)
{
	if (a->diff == 1 && a->len > 5)
	{
		almost_sort2(a, b);
		if (a->pos == 1)
		{
			while (a->min != a->first->nb)
			{
				rev_rotate_a(a, b);
				ft_printf("rra\n");
			}
		}
		else
		{
			while (a->min != a->first->nb)
			{
				rotate_a(a, b);
				ft_printf("ra\n");
			}
		}
		if (check_list(a, b) != 1)
			return (0);
		return (1);
	}
	return (0);
}

void	len_2(t_stack *a, t_stack *b)
{
	if (a->first->nb > a->first->next->nb)
	{
		swap_a(a, b);
		ft_printf("sa\n");
	}
}
