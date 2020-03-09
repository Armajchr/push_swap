/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:48:49 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/30 16:02:56 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *a)
{
	t_elem	*tmp;
	t_elem	*before;

	tmp = a->first;
	while (tmp)
	{
		before = tmp;
		tmp = tmp->next;
		free(before);
		before = NULL;
	}
	free(tmp);
	tmp = NULL;
	a->first = NULL;
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

void	visu(t_ope *ok, t_stack *a, t_stack *b)
{
	if (ok->f & (F_TV))
		ft_print_full(a, b);
}
