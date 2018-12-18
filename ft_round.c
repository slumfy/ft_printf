/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:36:28 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/12 15:27:22 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_round(char **str)
{
	int len;

	len = ft_strlen(*str) - 1;
	while ((*str)[len] == '9' && len > 0)
	{
		(*str)[len] = '0';
		len--;
		if ((*str)[len] == '.')
			len--;
	}
	if (len == 0)
	{
		(*str)[len] = '0';
		*str = ft_strjoind("1", *str);
	}
	else
		(*str)[len]++;
}
