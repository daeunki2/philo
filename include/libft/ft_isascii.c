/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:44:23 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 16:36:09 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (2);
	return (0);
}

/*
int main()
{
	printf("%d\n", ft_isascii('Z'));
	printf("%d\n", ft_isascii('\\'));
	printf("%d\n", ft_isascii('8'));
}
*/
