/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:08:36 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 11:40:24 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding(t_data *data)
{
	int		sub;

	sub = data->f_width - data->len;
	data->pad = ft_strnew(0);
	if (data->f_width > data->len)
	{
		ft_strdel(&data->pad);
		data->pad = ft_strnew(sub);
		if (data->accu != -1)
			data->flags->zero = 0;
		ft_memset(data->pad, (data->flags->zero == 1 ? 48 : 32), sub);
	}
}

void	ft_space(t_data *data, long long t)
{
	if (data->f_width > data->len)
	{
		if (t >= 0)
			data->pad[0] = ' ';
	}
	else
		data->pad = ft_strjoind(" ", data->pad);
}

void	ft_sign(t_data *data, long long t)
{
	int	sign;

	sign = (t < 0 ? '-' : '+');
	if (data->f_width > data->len)
	{
		if (data->flags->zero == 1)
			data->pad[0] = sign;
		else
			data->pad[ft_strlen(data->pad) - 1] = sign;
	}
	else
	{
		if (data->flags->space == 1)
		{
			*ft_strchr(data->pad, ' ') = sign;
		}
		else
			data->pad = ft_strjoind((t < 0 ? "-" : "+"), data->pad);
	}
}
