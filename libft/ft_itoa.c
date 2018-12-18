/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:41:18 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 14:10:22 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_nlen(int nb)
{
	size_t	i;

	i = 0;
	if (nb <= 0)
		i++;
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long long	nbr;
	size_t		tmp;

	nbr = (long long)n;
	i = ft_nlen(n);
	tmp = i;
	if (!(str = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	if (nbr == 0)
		str[0] = 48;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (nbr)
	{
		str[i - 1] = (nbr % 10) + 48;
		nbr /= 10;
		i--;
	}
	str[tmp] = '\0';
	return (str);
}
