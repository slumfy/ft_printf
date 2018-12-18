/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwolff <hwolff@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:53:53 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 15:22:19 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>

typedef	unsigned long long	t_ull;

typedef	struct				s_flag
{
	int						hash;
	int						zero;
	int						minus;
	int						plus;
	int						space;
	int						convh;
	int						convl;
	int						convbl;
}							t_flag;

typedef struct				s_parser
{
	int						s;
	int						j;
	char					*tmp;
}							t_parser;

typedef struct				s_data
{
	char					*fmt;
	char					*pad;
	int						f_width;
	int						accu;
	int						len;
	t_flag					*flags;
	t_parser				*prs;
	va_list					ap;
}							t_data;
int							ft_isconv(char c);
int							ft_is_univ_flag(char c);
int							ft_is_betw(char c);
int							ft_is_zero(char *str, int i);
t_flag						*ft_parse_flag(char *str, t_data *data);
void						ft_parse_llhh(char *str, t_data **data);
t_list						*ft_lst_parse_flags(t_data *data,
							t_list **begin_list);
void						ft_parse_width_accu(char *str, t_data *data);
void						ft_lst_push_txt(t_data *data, t_list **begin_list);
void						ft_lst_push_mod(t_data *data, t_list **begin_list);
void						ft_lst_push_flag(t_data *data, t_list **begin_list);
void						ft_lst_push_flag_txt(t_data *data,
							t_list **begin_list);

int							ft_printf(const char *restrict format, ...);
int							ft_print_list(t_list **begin_list);
t_ull						ft_abs(long long nb);

void						ft_padding(t_data *data);
void						ft_space(t_data *data, long long t);
void						ft_sign(t_data *data, long long t);
void						ft_dispatch(t_data *data);
void						ft_str_clear(t_data *data);

char						*ft_char(t_data *data);
char						*ft_mod(t_data *data);
char						*ft_string(t_data *data);
char						*ft_minhex(t_data *data);
char						*ft_maxhex(t_data *data);
char						*ft_float(t_data *data);
char						*ft_ptr(t_data *data);
char						*ft_int(t_data *data);
char						*ft_usgd(t_data *data);
char						*ft_oct(t_data *data);
char						*ft_bin(t_data *data);

int							ft_strchr_space(char *s);
void						ft_f_width(t_data *data, int size);
void						ft_accuracy(t_data *data);
void						ft_accu_int(t_data *data);
void						ft_f_width_int(t_data *data, long long t);
void						ft_manage_int(t_data *data, long long t);
void						ft_place_sign(char *s, t_data *data);
void						ft_cast(t_data *data, long long *t);
void						ft_ucast(t_data *data, unsigned long long *t);
void						ft_cast_l(t_data *data, long double *t);

void						ft_parse_priority(t_data *data);
void						ft_apply_width(t_data *data);
void						ft_apply_width_octal(t_data *data, int p);
void						ft_apply_width_hex(t_data *data, t_ull t, int p);

char						*ft_utoa_bl(t_ull valoe, int base, int p);
char						*ft_itoa_base(long long value, int base, int p);
char						*ft_dtoa(long double value, int p);
char						*ft_putaddr_to_str(long long value, int p);
char						*ft_utoa_base(t_ull n, int base, int p);
char						*ft_alloc(long double value, int p);
void						ft_round(char **str);
#endif
