/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:39:18 by theveste          #+#    #+#             */
/*   Updated: 2024/06/18 15:40:24 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*create_array(int len, t_flags *flags)
{
	char	*ret;
	int		untouched_len;
	int		precisize;

	precisize = flags->precision;
	untouched_len = len;
	if (precisize > 0 && len < precisize)
		len += (precisize - len);
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	if (precisize > 0 && untouched_len < precisize)
		add_zero(ret, precisize, untouched_len);
	ret[0] = '0';
	return (ret);
}
