/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:00:00 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/17 23:04:05 by rvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_apply_width(t_data *data)
{
	char	*tmp1;
	char	*tmp2;
	int		i;

	tmp1 = NULL;
	tmp2 = NULL;
	if (data->flags->minus == 1)
	{
		data->prs->tmp = ft_strdjoind(data->prs->tmp, data->pad);
		i = data->len;
		while (data->prs->tmp[i])
		{
			if (data->prs->tmp[i] != ' ')
				break ;
			i++;
		}
		tmp1 = ft_strsub(data->prs->tmp, i, ft_strlen(data->prs->tmp) - i);
		tmp2 = ft_strsub(data->prs->tmp, 0, ft_strlen(data->prs->tmp));
		ft_strdel(&data->prs->tmp);
		data->prs->tmp = ft_strdjoind(tmp1, tmp2);
	}
	else
		data->prs->tmp = ft_strdjoind(data->pad, data->prs->tmp);
	data->len = ft_strlen(data->prs->tmp);
}

void	ft_apply_width_octal(t_data *data, int p)
{
	if (p == 1)
	{
		ft_strdel(&data->prs->tmp);
		if (data->flags->hash == 1)
			data->prs->tmp = ft_strdup("0");
		else
			data->prs->tmp = ft_strdup("");
	}
	else
	{
		if (data->flags->minus == 1)
			data->prs->tmp = ft_strdjoind(data->prs->tmp, data->pad);
		else
			data->prs->tmp = ft_strdjoind(data->pad, data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
	}
}

void	ft_apply_width_hex(t_data *data, t_ull t, int p)
{
	if (p == 1)
	{
		if (data->flags->hash == 1 && t != 0)
			data->prs->tmp = ft_strjoind("0x", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
	}
	else if (p == 2)
	{
		if (data->flags->hash == 1 && t != 0)
			data->prs->tmp = ft_strjoind("0X", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
	}
	else
	{
		if (data->flags->space == 1)
			ft_space(data, t);
		if (data->flags->minus == 1)
			data->prs->tmp = ft_strdjoind(data->prs->tmp, data->pad);
		else
			data->prs->tmp = ft_strdjoind(data->pad, data->prs->tmp);
	}
}
