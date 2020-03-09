/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_ope3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:09:10 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/24 13:09:09 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear1(t_ope *x, int result)
{
	x->f &= ~(F_RA);
	x->f &= ~(F_RRR);
	x->f |= (F_RR);
	x->nb_ope = result;
	x->ra = x->i;
	x->rb = x->j;
}

void	clear2(t_ope *x, int result)
{
	x->f &= ~(F_RA);
	x->f &= ~(F_RR);
	x->f |= (F_RRR);
	x->nb_ope = result;
	x->rra = x->k;
	x->rrb = x->l;
}

void	clear3(t_ope *x, int result)
{
	if (x->i + x->j < x->k + x->l)
	{
		result = x->rr + x->i + x->j;
		if (result < x->nb_ope)
			clear1(x, result);
	}
	else if (x->i + x->j > x->k + x->l)
	{
		result = x->rrr + x->k + x->l;
		if (result < x->nb_ope)
			clear2(x, result);
	}
}

void	nb_ope3(t_ope *x)
{
	x->i = x->ra;
	x->j = x->rb;
	if (x->i > 0 && x->j > 0)
	{
		while (x->i > 0 && x->j > 0)
		{
			x->rr++;
			x->i--;
			x->j--;
		}
	}
	x->k = x->rra;
	x->l = x->rrb;
	if (x->k > 0 && x->l > 0)
	{
		while (x->k > 0 && x->l > 0)
		{
			x->rrr++;
			x->k--;
			x->l--;
		}
	}
}

void	nb_ope1(t_ope *x)
{
	int result;

	nb_ope(x);
	nb_ope3(x);
	result = 0;
	if (x->rr + x->i + x->j < x->rrr + x->k + x->l)
	{
		result = x->rr + x->i + x->j;
		if (result < x->nb_ope)
			clear1(x, result);
	}
	else if (x->rr + x->i + x->j > x->rrr + x->k + x->l)
	{
		result = x->rrr + x->k + x->l;
		if (result < x->nb_ope)
			clear2(x, result);
	}
	else if (x->rr == x->rrr && x->rr != 0)
		clear3(x, result);
}
