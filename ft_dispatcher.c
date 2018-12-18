/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:01:07 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/16 18:47:08 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*(*g_tab[12])(t_data *data) = {ft_char, ft_string, ft_minhex, ft_maxhex,
	ft_float, ft_ptr, ft_int, ft_int, ft_usgd, ft_oct, ft_bin, ft_mod};

void	ft_str_clear(t_data *data)
{
	int		i;
	char	*t;

	t = data->prs->tmp;
	i = 0;
	while (t[i])
	{
		if (t[i] != '%' && !ft_is_betw(t[i]))
			break ;
		i++;
	}
	data->prs->tmp = ft_strsub(t, i, ft_strlen(data->prs->tmp));
	ft_strdel(&t);
}

void	ft_dispatch(t_data *data)
{
	char	*db;
	int		i;
	int		len;

	len = ft_strlen(data->prs->tmp) - 1;
	i = 0;
	db = "csxXfpiduob%";
	while (db[i])
	{
		if ((data->prs->tmp)[len] == db[i])
			break ;
		i++;
	}
	data->prs->tmp = (g_tab[i])(data);
}
