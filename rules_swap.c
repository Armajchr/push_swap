/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:16:06 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/07 16:12:10 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *a, t_stack *b)
{
	t_elem	*tmp;
	t_elem	*tmp2;
	int		i;
	int		j;

	while (b)
		break ;
	if (a->len == 1 || a->len == 0 || a == NULL)
		return ;
	tmp = a->first;
	tmp2 = tmp->next;
	i = tmp->nb;
	j = tmp2->nb;
	tmp->nb = j;
	tmp2->nb = i;
	a->first = tmp;
	tmp = a->first;
}

void	swap_b(t_stack *a, t_stack *b)
{
	t_elem	*tmp;
	t_elem	*tmp2;
	int		i;
	int		j;

	while (a)
		break ;
	if (b->len < 2 || b == NULL)
		return ;
	tmp = b->first;
	tmp2 = tmp->next;
	i = tmp->nb;
	j = tmp2->nb;
	tmp->nb = j;
	tmp2->nb = i;
	b->first = tmp;
	tmp = b->first;
}

void	swap_ss(t_stack *a, t_stack *b)
{
	swap_a(a, b);
	swap_b(a, b);
}
