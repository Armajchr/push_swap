/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:26:06 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/31 11:29:20 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		first_sort(t_stack *a, t_stack *b)
{
	if (check_list(a, b) == 1)
		return (0);
	if (almost_sort(a, b) == 1)
		return (0);
	if (a->len < 2)
		return (0);
	if (a->len == 2)
	{
		len_2(a, b);
		return (0);
	}
	find_max(a);
	if (a->len == 3)
	{
		max_3(a);
		len_3(a, b);
		return (0);
	}
	launch2(a, b);
	return (1);
}

int		len_5(t_stack *a, t_stack *b, t_ope *ok)
{
	if (a->len == 2)
	{
		max_3(a);
		len_2(a, b);
		final_set(a, b, ok);
		return (0);
	}
	if (a->len == 3)
	{
		max_3(a);
		len_3(a, b);
		final_set(a, b, ok);
		return (0);
	}
	return (1);
}

void	reset_tc(t_ope *tc)
{
	tc->ra = 0;
	tc->rra = 0;
	tc->rb = 0;
	tc->rr = 0;
	tc->rrr = 0;
}

void	sort_main(t_stack *a, t_stack *b, t_ope *ok, t_ope *tc)
{
	fill_ok_tc(a, b, ok, tc);
	reset_tc(tc);
	push(a, b, ok);
	ok->rr = 0;
	ok->rrr = 0;
	init_ope(ok);
	ok->f &= ~(F_RR);
	ok->f &= ~(F_RRR);
}
