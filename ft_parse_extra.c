/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:11:10 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/17 18:57:41 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_isconv(char c)
{
	if (c == 'd' || c == 'i' || c == 'o' || c == 'x' || c == 'X' || c == 'c'
			|| c == 's' || c == 'p' || c == 'f' || c == 'u' || c == 'b'
			|| c == '%')
		return (1);
	return (0);
}

int		ft_is_univ_flag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ' || c == '.')
		return (1);
	return (0);
}

int		ft_is_betw(char c)
{
	if (ft_is_univ_flag(c) || (c > 48 && c < 58) || c == 'l' || c == 'h'
		|| c == 'L')
		return (1);
	return (0);
}

int		ft_is_zero(char *str, int i)
{
	while (str[i] != '%')
	{
		if (!(str[i] == '0' || str[i] == '#' || str[i] == ' '
			|| str[i] == '-' || str[i] == '+'))
			return (0);
		i--;
	}
	return (1);
}

t_ull	ft_abs(long long nb)
{
	t_ull	n;

	if (nb < 0)
		n = (t_ull)(-1 * nb);
	else
		n = (t_ull)nb;
	return (n);
}
