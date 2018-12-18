/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 18:49:44 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 13:10:02 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa_base(t_ull value, int base, int p)
{
	char	*s;
	t_ull	n;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	n = value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	i = (p < i ? i : i + (p - i));
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		exit(0);
	s[i] = '\0';
	n = value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	return (s);
}

char	*ft_utoa_bl(t_ull value, int base, int p)
{
	char	*s;
	t_ull	n;
	int		i;

	if (base < 2 || base > 16)
		return (NULL);
	n = value;
	i = 1;
	while ((n /= base) >= 1)
		i++;
	i = (p < i ? i : i + (p - i));
	if (!(s = (char*)malloc(sizeof(char) * (i + 1))))
		exit(0);
	s[i] = '\0';
	n = value;
	while (i--)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'a' - 10;
		n /= base;
	}
	return (s);
}
