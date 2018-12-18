/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mod.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:34:53 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 11:39:11 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_mod(t_data *data)
{
	char	t;
	char	*tmp;

	tmp = ft_strnew(1);
	t = '%';
	if (!t)
	{
		ft_strdel(&data->prs->tmp);
		t = 0;
	}
	ft_memset((void*)tmp, t, 1);
	ft_strdel(&(data->prs->tmp));
	data->prs->tmp = ft_strdup(tmp);
	ft_strdel(&tmp);
	data->len = ft_strlen(data->prs->tmp);
	ft_f_width(data, data->len);
	data->len = ft_strlen(data->prs->tmp);
	return (data->prs->tmp);
}
