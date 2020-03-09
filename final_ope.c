/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_ope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 12:11:24 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/24 13:12:02 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_tab(int i, int j, int *tab, t_stack *a)
{
	int k;

	while (i < 2)
	{
		while (j < 3)
		{
			if (tab[i] < tab[j])
			{
				k = tab[i];
				tab[i] = tab[j];
				tab[j] = k;
			}
			j++;
		}
		j = 1;
		i++;
	}
	a->max = tab[0];
	a->max2 = tab[1];
	a->max3 = tab[2];
}

void	max_4(t_stack *a, t_elem *tmp, int *tab)
{
	int	i;
	int	j;

	if (a->len == 3)
	{
		tmp = tmp->next;
		a->max2 = tmp->nb;
		tmp = tmp->next;
		a->max3 = tmp->nb;
		i = 0;
		j = 1;
		tab[0] = a->max;
		tab[1] = a->max2;
		tab[2] = a->max3;
		sort_tab(i, j, tab, a);
	}
}

void	max_3(t_stack *a)
{
	t_elem	*tmp;
	int		i;
	int		tab[3];

	tmp = a->first;
	a->max = tmp->nb;
	max_4(a, tmp, tab);
	if (a->len == 2)
	{
		tmp = a->first;
		a->max = tmp->nb;
		tmp = tmp->next;
		a->max2 = tmp->nb;
		if (a->max < a->max2)
		{
			i = a->max;
			a->max = a->max2;
			a->max2 = i;
		}
	}
}

void	len_4(t_stack *a, t_stack *b)
{
	if (a->first->nb == a->max && a->first->next->nb == a->max3)
	{
		rotate_a(a, b);
		ft_printf("ra\n");
	}
	else if (a->first->nb == a->max2 && a->first->next->nb == a->max)
	{
		rev_rotate_a(a, b);
		ft_printf("rra\n");
	}
}

void	len_3(t_stack *a, t_stack *b)
{
	if (a->first->nb == a->max2 && a->first->next->nb == a->max3)
	{
		swap_a(a, b);
		ft_printf("sa\n");
	}
	else if (a->first->nb == a->max3 && a->first->next->nb == a->max)
	{
		rev_rotate_a(a, b);
		swap_a(a, b);
		ft_printf("rra\nsa\n");
	}
	else if (a->first->nb == a->max && a->first->next->nb == a->max2)
	{
		rotate_a(a, b);
		swap_a(a, b);
		ft_printf("ra\nsa\n");
	}
	else
		len_4(a, b);
}
