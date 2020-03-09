/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armajchr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:35:32 by armajchr          #+#    #+#             */
/*   Updated: 2019/10/07 16:33:43 by armajchr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*ft_create_elem(int nb, t_elem *elem)
{
	if (!(elem = malloc(sizeof(t_elem))))
		return (NULL);
	elem->nb = nb;
	elem->next = NULL;
	return (elem);
}
