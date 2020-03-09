/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ope3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:50:21 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/24 13:07:45 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_struct2(t_ope *ok, t_ope *tc)
{
	if (tc->f & (F_RA))
	{
		ok->f |= (F_RA);
		ok->f &= ~(F_RRR);
		ok->f &= ~(F_RR);
	}
	else if (tc->f & (F_RR))
	{
		ok->f |= (F_RR);
		ok->f &= ~(F_RA);
		ok->f &= ~(F_RRR);
	}
	else if (tc->f & (F_RRR))
	{
		ok->f |= (F_RRR);
		ok->f &= ~(F_RA);
		ok->f &= ~(F_RR);
	}
}

int		check_max_a(t_ope *ok, t_stack *a)
{
	if (ok->value == a->max || ok->value == a->max2 || ok->value == a->max3)
	{
		ok->ra++;
		ok->check = 1;
		return (1);
	}
	return (0);
}

void	fill_ok_tc2(t_stack *a, t_stack *b, t_ope *ok, t_ope *tc)
{
	t_elem	*tmp;
	int		i;

	tmp = a->first;
	i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		tc->value = tmp->nb;
		i++;
		tc->ra = i;
		while (tc->value == a->max || tc->value == a->max2
				|| tc->value == a->max3)
		{
			tmp = tmp->next;
			i++;
			if (tmp == NULL)
				return ;
			tc->value = tmp->nb;
			tc->ra = i;
		}
		fill_tc(a, b, ok, tc);
	}
}

void	fill_ok3(t_stack *b, t_ope *x)
{
	while (x->index < b->len + 1)
	{
		x->rrb++;
		x->index++;
	}
	x->rb = b->len - x->rrb;
}
