/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:16:44 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/24 15:12:09 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack *a, t_stack *b)
{
	t_elem *tmp;
	t_elem *tmp2;

	if (b == NULL || b->len < 1)
		return ;
	tmp = b->first;
	tmp2 = NULL;
	tmp2 = ft_create_elem(tmp->nb, tmp2);
	tmp2->next = a->first;
	a->first = tmp2;
	tmp2 = NULL;
	b->first = tmp->next;
	free(tmp);
	b->len--;
	a->len++;
}

void	push_b(t_stack *a, t_stack *b)
{
	t_elem	*tmp;
	t_elem	*tmp2;

	if (a == NULL || a->len < 1)
		return ;
	tmp = a->first;
	tmp2 = NULL;
	tmp2 = ft_create_elem(tmp->nb, tmp2);
	tmp2->next = b->first;
	b->first = tmp2;
	tmp2 = NULL;
	a->first = tmp->next;
	free(tmp);
	b->len++;
	a->len--;
}
