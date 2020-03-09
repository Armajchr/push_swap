/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ope.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:02:57 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/24 13:14:48 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nb_ope(t_ope *ok)
{
	if (ok->ra <= ok->rra && ok->rb <= ok->rrb)
		ok->nb_ope = ok->ra + ok->rb;
	else if (ok->ra >= ok->rra && ok->rb <= ok->rrb)
		ok->nb_ope = ok->rra + ok->rb;
	else if (ok->ra >= ok->rra && ok->rb >= ok->rrb)
		ok->nb_ope = ok->rra + ok->rrb;
	else if (ok->ra <= ok->rra && ok->rrb <= ok->rb)
		ok->nb_ope = ok->ra + ok->rrb;
	ok->f |= (F_RA);
}

void	swap_struct(t_ope *ok, t_ope *tc)
{
	if (ok->nb_ope > tc->nb_ope || (ok->nb_ope == tc->nb_ope
				&& ok->value > tc->value))
	{
		ok->ra = tc->ra;
		ok->rra = tc->rra;
		ok->rb = tc->rb;
		ok->rrb = tc->rrb;
		ok->value = tc->value;
		ok->rr = tc->rr;
		ok->rrr = tc->rrr;
		ok->nb_ope = tc->nb_ope;
		ok->i = tc->i;
		ok->j = tc->j;
		ok->k = tc->k;
		ok->l = tc->l;
		swap_struct2(ok, tc);
	}
}

void	fill_ok(t_stack *b, t_ope *x)
{
	int			i;
	t_elem		*tmp2;
	t_elem		*tmp3;

	i = 0;
	fill_ok1(b, x);
	if (fill_ok2(b, x) == 1)
		return ;
	tmp2 = b->first;
	tmp3 = b->first;
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
		i++;
		if (x->value > tmp2->nb && x->value < tmp3->nb)
		{
			x->rb += i;
			x->rrb = b->len - x->rb;
			break ;
		}
		tmp3 = tmp3->next;
	}
}

void	fill_tc(t_stack *a, t_stack *b, t_ope *ok, t_ope *tc)
{
	tc->rra = a->len - tc->ra;
	fill_ok(b, tc);
	nb_ope1(tc);
	swap_struct(ok, tc);
	tc->rb = 0;
	tc->rrb = 0;
	tc->rr = 0;
	tc->rrr = 0;
	tc->nb_ope = 0;
}

void	fill_ok_tc(t_stack *a, t_stack *b, t_ope *ok, t_ope *tc)
{
	t_elem	*tmp;

	tmp = a->first;
	ok->value = tmp->nb;
	if (check_max_a(ok, a) == 1)
		return ;
	fill_ok(b, ok);
	nb_ope1(ok);
	fill_ok_tc2(a, b, ok, tc);
}
