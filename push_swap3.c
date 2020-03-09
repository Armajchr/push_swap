/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:05:19 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/30 16:26:41 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	option(char **av, t_ope *ok)
{
	if (ft_strncmp(av[1], "-v", 2) == 0)
		ok->f |= (F_TV);
	else
		ok->f &= ~(F_TV);
}

int		small_sort(t_stack *a, t_stack *b, t_ope *ok)
{
	if (first_sort(a, b) == 0)
	{
		visu(ok, a, b);
		free_stacks(a, b);
		return (0);
	}
	if (len_5(a, b, ok) == 0)
	{
		visu(ok, a, b);
		free_stacks(a, b);
		return (0);
	}
	return (1);
}

void	last_sort(t_stack *a, t_stack *b, t_ope *ok)
{
	len_3(a, b);
	final_set(a, b, ok);
	visu(ok, a, b);
	free_stacks(a, b);
}
