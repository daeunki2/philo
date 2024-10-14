/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:26:44 by theveste          #+#    #+#             */
/*   Updated: 2023/11/14 13:50:13 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if ((character >= 'a' && character <= 'z')
		|| (character >= 'A' && character <= 'Z'))
		return (2);
	return (0);
}

/*
int main()
{
	printf("%d\n", ft_isalpha('Z'));
	printf("%d\n", ft_isalpha('\\'));
	printf("%d\n", ft_isalpha('8'));
}
*/