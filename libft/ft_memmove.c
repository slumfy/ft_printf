/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:33:21 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 14:12:34 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*srce;

	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	if (dest < srce)
	{
		while (len)
		{
			*dest++ = *srce++;
			len--;
		}
	}
	else
	{
		while (len)
		{
			*(dest + len - 1) = *(srce + len - 1);
			len--;
		}
	}
	return (dst);
}
