/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 11:11:15 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/30 14:11:21 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_digit(int i, int k, char **av)
{
	while (av[i][k])
	{
		if (ft_isdigit(av[i][k]) == 0)
		{
			write(2, "Error3\n", 6);
			return (0);
		}
		k++;
	}
	return (1);
}

t_stack	initstack(t_stack *a, t_elem *elem)
{
	elem->nb = 0;
	elem->next = NULL;
	a->first = NULL;
	a->len = 0;
	return (*a);
}

void	init_ope(t_ope *ok)
{
	ok->ra = 0;
	ok->rb = 0;
	ok->rra = 0;
	ok->rrb = 0;
	ok->rr = 0;
	ok->rrr = 0;
	ok->nb_ope = 0;
}

void	ft_print_full(t_stack *a, t_stack *b)
{
	ft_printf(YELLOW"----------stack a----------\n"EOC);
	ft_print_stack(a);
	ft_printf(CYAN"----------stack b----------\n"EOC);
	ft_print_stack(b);
}

void	launch(t_stack *a, t_stack *b, t_elem *elem, t_ope *ok)
{
	*a = initstack(a, elem);
	*b = initstack(b, elem);
	init_ope(ok);
}
