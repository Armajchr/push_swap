/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_rev_rotates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 15:00:42 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/23 15:33:30 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate_a2(t_stack *a, t_elem *tmp, t_elem *tmp2, t_elem *tmp3)
{
	int i;
	int j;
	int len;

	len = 0;
	while (len < a->len - 1)
	{
		i = tmp2->nb;
		while (tmp3)
		{
			if (tmp3->next == NULL)
			{
				j = tmp3->nb;
				break ;
			}
			else
				tmp3 = tmp3->next;
		}
		tmp2->nb = j;
		tmp3->nb = i;
		tmp2 = tmp2->next;
		tmp3 = tmp2;
		len++;
	}
	a->first = tmp;
}

void	rev_rotate_a(t_stack *a, t_stack *b)
{
	t_elem	*tmp;
	t_elem	*tmp2;
	t_elem	*tmp3;

	while (b)
		break ;
	if (a->len < 2 || a == NULL)
		return ;
	tmp = a->first;
	tmp2 = tmp;
	tmp3 = tmp2;
	rev_rotate_a2(a, tmp, tmp2, tmp3);
}

void	rev_rotate_b(t_stack *a, t_stack *b)
{
	rev_rotate_a(b, a);
}

void	rev_rotate_r(t_stack *a, t_stack *b)
{
	rev_rotate_a(a, b);
	rev_rotate_a(b, a);
}
