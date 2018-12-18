/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:24:29 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/16 16:21:52 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_list(t_list **begin_list)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *begin_list;
	if (tmp)
	{
		while (tmp)
		{
			write(1, tmp->data, tmp->len);
			i += tmp->len;
			tmp = tmp->next;
		}
	}
	return (i);
}
