/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:31:26 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/10 12:13:56 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *a, t_stack *b)
{
	t_elem	*tmp;
	t_elem	*tmp2;
	int		j;
	int		k;
	int		len;

	while (b)
		break ;
	if (a->len < 2 || a == NULL)
		return ;
	len = 0;
	tmp = a->first;
	tmp2 = tmp;
	while (len < a->len - 1)
	{
		j = tmp2->nb;
		k = tmp2->next->nb;
		tmp2->nb = k;
		tmp2->next->nb = j;
		tmp2 = tmp2->next;
		len++;
	}
	a->first = tmp;
}

void	rotate_b(t_stack *a, t_stack *b)
{
	t_elem	*tmp;
	t_elem	*tmp2;
	int		k;
	int		j;
	int		len;

	while (a)
		break ;
	if (b->len < 2 || b == NULL)
		return ;
	len = 0;
	tmp = b->first;
	tmp2 = tmp;
	while (len < b->len - 1)
	{
		j = tmp2->nb;
		k = tmp2->next->nb;
		tmp2->nb = k;
		tmp2->next->nb = j;
		tmp2 = tmp2->next;
		len++;
	}
	b->first = tmp;
}

void	rotate_rr(t_stack *a, t_stack *b)
{
	rotate_a(a, b);
	rotate_b(a, b);
}
