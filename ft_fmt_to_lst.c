/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_to_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:20:57 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/17 21:31:31 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lst_parse_flags(t_data *data, t_list **begin_list)
{
	int		len;

	data->prs->j = -1;
	len = ft_strlen(data->fmt);
	while (++(data->prs->j) < len)
	{
		data->prs->s = data->prs->j;
		while (data->prs->j < len && data->fmt[data->prs->j] != '%')
			(data->prs->j)++;
		ft_lst_push_txt(data, begin_list);
		data->prs->s = data->prs->j;
		(data->prs->j)++;
		if (data->prs->j >= len)
			break ;
		while (data->prs->j < len && ft_is_betw(data->fmt[data->prs->j])
				&& !ft_isconv(data->fmt[data->prs->j]))
			(data->prs->j)++;
		if (ft_isconv(data->fmt[data->prs->j]))
			ft_lst_push_flag(data, begin_list);
		else
			ft_lst_push_flag_txt(data, begin_list);
	}
	return (*begin_list);
}

void	ft_lst_push_txt(t_data *data, t_list **begin_list)
{
	int		sub;

	sub = data->prs->j - data->prs->s;
	if (sub > 0)
	{
		if (!(data->prs->tmp = ft_strsub(data->fmt, data->prs->s, sub)))
			return ;
		ft_list_pushback(begin_list, ft_strdup(data->prs->tmp),
				ft_strlen(data->prs->tmp));
		ft_strdel(&(data->prs->tmp));
	}
}

void	ft_lst_push_flag(t_data *data, t_list **begin_list)
{
	int		sub;

	sub = data->prs->j - data->prs->s;
	if (sub + 1 > 0)
	{
		if (!(data->prs->tmp = ft_strsub(data->fmt, data->prs->s, sub + 1)))
			return ;
		if (!ft_strchr(data->prs->tmp, '.'))
			data->accu = -1;
		else
			data->accu = 0;
		data->f_width = -1;
		ft_parse_width_accu(data->prs->tmp, data);
		data->flags = ft_parse_flag(data->prs->tmp, data);
		ft_parse_llhh(data->prs->tmp, &data);
		ft_dispatch(data);
		ft_list_pushback(begin_list, ft_strdup(data->prs->tmp), data->len);
		ft_strdel(&(data->prs->tmp));
		free(data->flags);
	}
}

void	ft_lst_push_flag_txt(t_data *data, t_list **begin_list)
{
	int		sub;

	sub = data->prs->j - data->prs->s;
	if (sub + 1 > 0)
	{
		if (!(data->prs->tmp = ft_strsub(data->fmt, data->prs->s, sub + 1)))
			return ;
		if (!ft_strchr(data->prs->tmp, '.'))
			data->accu = -1;
		else
			data->accu = 0;
		data->f_width = -1;
		ft_parse_width_accu(data->prs->tmp, data);
		data->flags = ft_parse_flag(data->prs->tmp, data);
		ft_str_clear(data);
		data->len = ft_strlen(data->prs->tmp);
		ft_accuracy(data);
		ft_f_width(data, data->len);
		data->len = ft_strlen(data->prs->tmp);
		ft_list_pushback(begin_list, ft_strdup(data->prs->tmp), data->len);
		ft_strdel(&(data->prs->tmp));
		free(data->flags);
	}
}
