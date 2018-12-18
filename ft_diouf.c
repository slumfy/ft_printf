/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dioufper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:47:47 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 15:24:59 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_float(t_data *data)
{
	long double	t;

	ft_cast_l(data, &t);
	ft_strdel(&(data->prs->tmp));
	if (data->accu == -1)
		data->accu = 6;
	data->prs->tmp = ft_dtoa((t < 0 ? -t : t), data->accu);
	data->len = ft_strlen(data->prs->tmp);
	ft_padding(data);
	if (data->flags->space == 1)
		ft_space(data, t);
	if (data->flags->plus == 1 || t < 0)
		ft_sign(data, t);
	ft_apply_width(data);
	if (t < 0 && data->flags->minus == 1)
		data->len--;
	return (data->prs->tmp);
}

char	*ft_int(t_data *data)
{
	long long	t;
	char		*tmp;

	ft_cast(data, &t);
	ft_strdel(&(data->prs->tmp));
	if (data->accu != 0 || t != 0)
		data->prs->tmp = ft_itoa_base(t, 10, data->accu);
	else
		data->prs->tmp = ft_strdup("");
	if (t < 0)
	{
		tmp = ft_strsub(data->prs->tmp, 1, ft_strlen(data->prs->tmp));
		ft_strdel(&data->prs->tmp);
		data->prs->tmp = tmp;
	}
	data->len = ft_strlen(data->prs->tmp);
	ft_padding(data);
	if (data->flags->space == 1)
		ft_space(data, t);
	if (data->flags->plus == 1 || t < 0)
		ft_sign(data, t);
	ft_apply_width(data);
	if (data->flags->minus == 1 && (t < 0 || data->flags->plus == 1))
		(data->len)--;
	return (data->prs->tmp);
}

char	*ft_usgd(t_data *data)
{
	t_ull	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	if (data->accu != 0 || t != 0)
		data->prs->tmp = ft_utoa_base(t, 10, data->accu);
	else if (t == 0)
		data->prs->tmp = ft_strdup("");
	data->len = ft_strlen(data->prs->tmp);
	ft_padding(data);
	if (data->flags->minus == 1)
		data->prs->tmp = ft_strdjoind(data->prs->tmp, data->pad);
	else
		data->prs->tmp = ft_strdjoind(data->pad, data->prs->tmp);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_oct(t_data *data)
{
	unsigned long long	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	if (data->accu != 0 || t != 0)
		data->prs->tmp = ft_utoa_base(t, 8, data->accu);
	else if (t == 0)
		ft_apply_width_octal(data, 1);
	data->len = ft_strlen(data->prs->tmp);
	if (data->flags->hash == 1 && data->flags->zero == 1 && t != 0)
	{
		ft_padding(data);
		data->prs->tmp = ft_strjoind("0", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
	}
	else if (data->flags->hash == 1 && t != 0)
	{
		data->prs->tmp = ft_strjoind("0", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp);
		ft_padding(data);
	}
	else
		ft_padding(data);
	ft_apply_width_octal(data, 0);
	return (data->prs->tmp);
}
