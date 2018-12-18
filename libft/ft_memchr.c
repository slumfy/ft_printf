/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:36:01 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 14:11:51 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;

	cc = (unsigned char)c;
	str = (unsigned char *)s;
	while (n)
	{
		if (*str == cc)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}
