/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 14:44:19 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 15:21:44 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cast(t_data *data, long long *t)
{
	if (data->flags->convh == 1)
		*t = (long long)((short int)va_arg(data->ap, long long));
	else if (data->flags->convh == 2)
		*t = (long long)((signed char)va_arg(data->ap, long long));
	else if (data->flags->convl == 1)
		*t = (long long)((long)va_arg(data->ap, long long));
	else if (data->flags->convl == 2)
		*t = va_arg(data->ap, long long);
	else
		*t = (long long)(va_arg(data->ap, int));
}

void	ft_ucast(t_data *data, unsigned long long *t)
{
	if (data->flags->convh == 1)
		*t = (t_ull)((unsigned short int)va_arg(data->ap, t_ull));
	else if (data->flags->convh == 2)
		*t = (t_ull)((unsigned char)va_arg(data->ap, t_ull));
	else if (data->flags->convl == 1)
		*t = (t_ull)((unsigned long)va_arg(data->ap, t_ull));
	else if (data->flags->convl == 2)
		*t = (t_ull)((unsigned long long)va_arg(data->ap, t_ull));
	else
		*t = (t_ull)va_arg(data->ap, unsigned int);
}

void	ft_cast_l(t_data *data, long double *t)
{
	if (data->flags->convbl == 1)
		*t = va_arg(data->ap, long double);
	else
		*t = (long double)va_arg(data->ap, double);
}
