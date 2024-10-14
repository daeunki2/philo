/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 01:57:58 by theveste          #+#    #+#             */
/*   Updated: 2024/06/18 15:40:26 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	add_zero(char *str, int precisize, int len)
{
	int	i;
	int	precis;

	i = 0;
	precis = precisize - len;
	while (precis > 0)
	{
		str[i] = '0';
		precis--;
		i++;
	}
}

char	*malloc_zero(int len, int precisize)
{
	char	*ret;
	int		untouched_len;

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

char	*ft_itoa_printf(int n, t_flags *flag, int len)
{
	char	*result;
	long	nbr;

	nbr = n;
	result = malloc_zero(len, flag->precisize);
	if (!result)
		return (NULL);
	if (flag->precisize > 0 && len < flag->precisize)
		len += flag->precisize - len;
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		result[len - 1] = '0';
	result[len] = '\0';
	while (nbr > 0)
	{
		result[len - 1] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		len--;
	}
	return (result);
}
