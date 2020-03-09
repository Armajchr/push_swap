/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_ope2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:39:46 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/24 13:08:21 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max_b(t_stack *b)
{
	t_elem	*tmp;

	tmp = b->first;
	b->max = tmp->nb;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (b->max < tmp->nb)
			b->max = tmp->nb;
	}
}

void	find_max2(t_stack *b, t_ope *ok)
{
	t_elem	*tmp;

	find_max_b(b);
	ok->index = 1;
	tmp = b->first;
	while (b->max != tmp->nb)
	{
		ok->index++;
		tmp = tmp->next;
	}
}

void	rotate_max_a(t_stack *a, t_ope *ok)
{
	if (a->first->nb == a->max)
		ok->ra++;
}

void	push2(t_stack *a, t_stack *b, t_ope *ok)
{
	while (ok->rb > 0)
	{
		rotate_b(a, b);
		ft_printf("rb\n");
		ok->rb--;
	}
	while (ok->rrb > 0)
	{
		rev_rotate_b(a, b);
		ft_printf("rrb\n");
		ok->rrb--;
	}
	if (ok->check == 0)
	{
		push_b(a, b);
		ft_printf("pb\n");
	}
	else
		ok->check = 0;
}

void	push(t_stack *a, t_stack *b, t_ope *ok)
{
	push3(a, b, ok);
	if (ok->f & (F_RA))
	{
		if (ok->rb >= ok->rrb && ok->rrb > 0)
			ok->rb = 0;
		else if (ok->rb <= ok->rrb && ok->rb > 0)
			ok->rrb = 0;
		if (ok->ra >= ok->rra && ok->rra > 0)
			ok->ra = 0;
		else if (ok->ra <= ok->rra && ok->ra > 0)
			ok->rra = 0;
	}
	while (ok->ra > 0)
	{
		rotate_a(a, b);
		ft_printf("ra\n");
		ok->ra--;
	}
	while (ok->rra > 0)
	{
		rev_rotate_a(a, b);
		ft_printf("rra\n");
		ok->rra--;
	}
	push2(a, b, ok);
}
