/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_ope4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:08:57 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/23 12:21:24 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max3(t_stack *a)
{
	t_elem *tmp;

	tmp = a->first;
	while (tmp)
	{
		if (tmp->nb > a->max2 && tmp->nb < a->max)
			a->max2 = tmp->nb;
		tmp = tmp->next;
	}
}

void	find_max4(t_stack *a)
{
	t_elem	*tmp;

	tmp = a->first;
	while (tmp)
	{
		if (tmp->nb > a->max3 && tmp->nb < a->max2 && tmp->nb < a->max)
			a->max3 = tmp->nb;
		tmp = tmp->next;
	}
}

void	find_max(t_stack *a)
{
	t_elem	*tmp;
	t_elem	*tmp2;

	tmp = a->first;
	a->max = tmp->nb;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (a->max < tmp->nb)
			a->max = tmp->nb;
	}
	tmp = a->first;
	tmp2 = tmp;
	tmp2 = tmp2->next;
	a->max2 = (a->first->nb == a->max) ? a->first->next->nb : a->first->nb;
	find_max3(a);
	tmp = a->first;
	a->max3 = ((tmp->nb == a->max && tmp->next->nb == a->max2)
			|| (tmp->nb == a->max2 && tmp->next->nb == a->max))
		? tmp2->next->nb : tmp->nb;
	a->max3 = ((tmp->nb == a->max && tmp->next->nb != a->max2)
			|| (tmp->nb == a->max2 && tmp->next->nb != a->max))
		? tmp->next->nb : a->max3;
	find_max4(a);
}

void	push3(t_stack *a, t_stack *b, t_ope *ok)
{
	if (ok->f & (F_RR))
	{
		ok->rrr = 0;
		ok->rrb = 0;
		ok->rra = 0;
		while (ok->rr > 0)
		{
			rotate_rr(a, b);
			ft_printf("rr\n");
			ok->rr--;
		}
	}
	else if (ok->f & (F_RRR))
	{
		ok->rr = 0;
		ok->ra = 0;
		ok->rb = 0;
		while (ok->rrr > 0)
		{
			rev_rotate_r(a, b);
			ft_printf("rrr\n");
			ok->rrr--;
		}
	}
}
