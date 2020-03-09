/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <armajchr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:52:10 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/30 15:55:13 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check2(int ac, char **av, int i, int tmp)
{
	int j;

	j = 2;
	if (i != 1)
	{
		while (j < ac && j != i)
		{
			if (ft_atoi(av[j]) == tmp)
			{
				write(2, "Error1\n", 6);
				return (0);
			}
			j++;
		}
		j = 1;
	}
	return (j);
}

int		check3(int tmp, int ac, char **av, int i)
{
	int	j;

	if (tmp > 2147483647 || tmp < -2147483648)
	{
		write(2, "Error2\n", 6);
		return (0);
	}
	else
	{
		j = check2(ac, av, i, tmp);
		if (j == 0)
			return (0);
	}
	return (1);
}

int		check(int ac, char **av, t_ope *ok)
{
	int i;
	int k;
	int tmp;

	i = 1;
	k = 0;
	if (ac < 2)
		return (0);
	else
	{
		if (ok->f & (F_TV))
			i = 2;
		while (i < ac)
		{
			if (check_digit(i, k, av) == 0)
				return (0);
			tmp = ft_atoi(av[i]);
			if (check3(tmp, ac, av, i) == 0)
				return (0);
			i++;
			k = 0;
		}
	}
	return (1);
}

void	fill_stack(t_stack *a, int ac, char **av, t_ope *ok)
{
	int		i;
	t_elem	*tmp;

	i = ac - 1;
	while (i > 1)
	{
		tmp = ft_create_elem(ft_atoi(av[i]), tmp);
		tmp->next = a->first;
		a->first = tmp;
		tmp = NULL;
		i--;
		a->len++;
	}
	if (ok->f & (F_TV))
		free(tmp);
	else
	{
		tmp = ft_create_elem(ft_atoi(av[1]), tmp);
		tmp->next = a->first;
		a->first = tmp;
		tmp = NULL;
		a->len++;
	}
	free(tmp);
}

void	ft_print_stack(t_stack *a)
{
	t_elem *tmp;

	tmp = a->first;
	if (tmp == NULL)
	{
		ft_printf(PURPLE"La liste est vide\n"EOC);
		return ;
	}
	while (tmp != NULL)
	{
		ft_printf(PURPLE"%d\n"EOC, tmp->nb);
		tmp = tmp->next;
	}
}
