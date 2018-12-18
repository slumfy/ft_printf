/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabouce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 21:30:31 by mabouce           #+#    #+#             */
/*   Updated: 2018/12/18 14:06:39 by mabouce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_create_elem(char *data, int len)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		exit(0);
	new->data = data;
	new->len = len;
	new->next = NULL;
	return (new);
}
