/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:41:34 by theveste          #+#    #+#             */
/*   Updated: 2023/11/14 13:49:38 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if ((character >= 'a' && character <= 'z')
		|| (character >= 'A' && character <= 'Z')
		|| (character >= '0' && character <= '9'))
		return (2);
	else
		return (0);
}

/*
int main()
{
	printf("%d\n", ft_isalnum('Z'));
	printf("%d\n", ft_isalnum('\\'));
	printf("%d\n", ft_isalnum('8'));
}
*/