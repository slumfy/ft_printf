/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cspxx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:36:56 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 14:47:38 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

char	*ft_char(t_data *data)
{
	char	t;
	char	*tmp;

	tmp = ft_strnew(1);
	t = (char)va_arg(data->ap, int);
	ft_memset((void*)tmp, t, 1);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
	ft_accuracy(data);
	if (t == 0)
	{
		data->len = ft_strlen(data->prs->tmp) + 1;
		ft_f_width(data, data->len);
		data->len = ft_strlen(data->prs->tmp) + 1;
	}
	else
	{
		data->len = ft_strlen(data->prs->tmp);
		ft_f_width(data, data->len);
		data->len = ft_strlen(data->prs->tmp);
	}
	return (data->prs->tmp);
}

char	*ft_string(t_data *data)
{
	char	*t;

	t = va_arg(data->ap, char *);
	if (t == NULL)
	{
		ft_strdel(&data->prs->tmp);
		data->prs->tmp = ft_strdup("(null)");
	}
	else if (data->flags->convl == 0)
	{
		ft_strdel(&data->prs->tmp);
		data->prs->tmp = ft_strdup(t);
	}
	ft_accuracy(data);
	data->len = ft_strlen(data->prs->tmp);
	ft_f_width(data, data->len);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_minhex(t_data *data)
{
	t_ull	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	if (data->accu != 0 || t != 0)
		data->prs->tmp = ft_utoa_bl(t, 16, data->accu);
	else if (t == 0)
		data->prs->tmp = ft_strdup("");
	data->len = ft_strlen(data->prs->tmp);
	if (data->flags->hash == 1 && data->flags->zero == 1 && t != 0)
	{
		data->len += 2;
		ft_padding(data);
		ft_apply_width_hex(data, t, 0);
		data->prs->tmp = ft_strjoind("0x", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp) - 2;
	}
	else
	{
		ft_apply_width_hex(data, t, 1);
		ft_padding(data);
		ft_apply_width_hex(data, t, 0);
	}
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_maxhex(t_data *data)
{
	t_ull	t;

	ft_ucast(data, &t);
	ft_strdel(&(data->prs->tmp));
	if (data->accu != 0 || t != 0)
		data->prs->tmp = ft_utoa_base(t, 16, data->accu);
	else if (t == 0)
		data->prs->tmp = ft_strdup("");
	data->len = ft_strlen(data->prs->tmp);
	if (data->flags->hash == 1 && data->flags->zero == 1 && t != 0)
	{
		data->len += 2;
		ft_padding(data);
		ft_apply_width_hex(data, t, 0);
		data->prs->tmp = ft_strjoind("0X", data->prs->tmp);
		data->len = ft_strlen(data->prs->tmp) - 2;
	}
	else
	{
		ft_apply_width_hex(data, t, 2);
		ft_padding(data);
		ft_apply_width_hex(data, t, 0);
	}
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}

char	*ft_ptr(t_data *data)
{
	long long	t;

	t = va_arg(data->ap, long long);
	ft_strdel(&(data->prs->tmp));
	if (data->accu != 0)
		data->prs->tmp = ft_putaddr_to_str(t, data->accu);
	else
		data->prs->tmp = ft_strdup("0x");
	data->len = ft_strlen(data->prs->tmp);
	ft_f_width(data, data->len);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}
