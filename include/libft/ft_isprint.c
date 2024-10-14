/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:47:44 by theveste          #+#    #+#             */
/*   Updated: 2023/11/14 13:54:03 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int character)
{
	if (character >= ' ' && character < 127)
		return (2);
	return (0);
}

/*
int main()
{
	printf("%d\n", ft_isprint(28));
	printf("%d\n", ft_isprint('\\'));
	printf("%d\n", ft_isprint('8'));
}
*/
