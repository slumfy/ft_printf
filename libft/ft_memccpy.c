/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:47:11 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 14:11:41 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srce;
	unsigned char	cc;

	cc = (unsigned char)c;
	dest = (unsigned char *)dst;
	srce = (unsigned char *)src;
	while (n > 0)
	{
		if (*srce == cc)
		{
			*dest = cc;
			return (++dest);
		}
		*dest++ = *srce++;
		n--;
	}
	return (NULL);
}
