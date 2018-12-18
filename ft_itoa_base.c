/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multiple_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:18:19 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 13:07:37 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_base(long long value, int base, int p)
{
	char		*s;
	t_ull		n;
	int			sign;
	int			i;

	if (base < 2 || base > 16)
		return (NULL);
	n = (t_ull)((value < 0) ? -value : value);
	sign = (value < 0 && base == 10) ? -1 : 0;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	i = (p < i ? i : i + (p - i));
	i = (sign == -1) ? i + 1 : i;
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		exit(0);
	s[i] = '\0';
	n = (t_ull)((value < 0) ? -value : value);
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}
