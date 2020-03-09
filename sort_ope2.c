/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ope2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:34:34 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/24 13:13:48 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		fill_ok2(t_stack *b, t_ope *x)
{
	if (x->value > b->max || x->value < b->min)
	{
		if (x->index == 1 && x->value > b->max)
			return (1);
		else if (x->value < b->min && b->first->nb == b->max)
			return (1);
		else if (x->index < b->len / 2)
		{
			while (x->index > 1)
			{
				x->rb++;
				x->index--;
			}
			x->rrb = b->len - x->rb;
			return (1);
		}
		else
		{
			fill_ok3(b, x);
			return (1);
		}
	}
	return (0);
}

void	fill_ok1(t_stack *b, t_ope *x)
{
	t_elem	*tmp2;

	tmp2 = b->first;
	b->min = tmp2->nb;
	find_max2(b, x);
	while (tmp2->next)
	{
		tmp2 = tmp2->next;
		if (tmp2->nb < b->min)
			b->min = tmp2->nb;
	}
}
