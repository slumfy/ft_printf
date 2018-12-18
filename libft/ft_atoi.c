/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 23:34:21 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 14:06:12 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			neg;
	long long	nbr;

	neg = 1;
	nbr = 0;
	while (*str == '\b' || *str == '\f' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\r' || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			neg = -1;
	while (*str > 47 && *str < 58)
		nbr = nbr * 10 + *str++ - 48;
	return (neg * nbr);
}
