/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:47:10 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/17 22:29:07 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_lltoa_base_hexa(long long value, int p)
{
	char	*s;
	long	n;
	int		sign;
	int		i;
	int		base;

	base = 16;
	n = (value < 0) ? -(long)value : value;
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = 1;
	i = (sign == -1) ? i + 1 : i;
	while ((n /= base) >= 1)
		i++;
	i = (p < i ? i : i + (p - i));
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}

char			*ft_putaddr_to_str(long long value, int p)
{
	char *dest;

	dest = ft_strjoind("0x", ft_lltoa_base_hexa(value, p));
	return (dest);
}
