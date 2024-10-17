/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justify_integer2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:21:40 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:21:41 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_integer_flag(char sign)
{
	if (sign == ' ')
		return (ft_printchar(' '));
	else if (sign == '+')
		return (ft_printchar('+'));
	else if (sign == '-')
		return (ft_printchar('-'));
	return (0);
}

void	print_width_flags(char *str, t_flags *flags, int n, int len)
{
	if (n < 0)
		ft_integer_flag('-');
	if (n >= 0 && flags->plus == 1)
		ft_integer_flag('+');
	else if (n >= 0 && flags->plus == 0 && flags->space == 1)
		ft_integer_flag(' ');
	write(1, str, len);
}

int	set_v(int n, t_flags *flags)
{
	int	ret;

	ret = 0;
	if (n < 0)
		ret += 1;
	if (n >= 0 && flags->plus == 1)
		ret += 1;
	else if (n >= 0 && flags->plus == 0 && flags->space == 1)
		ret += 1;
	return (ret);
}
