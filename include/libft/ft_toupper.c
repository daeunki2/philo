/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 02:50:03 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 11:13:34 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int character)
{
	if (character >= 'a' && character <= 'z')
		return (character - 32);
	return (character);
}

/*
int main(void)
{
	printf("%c", ft_tolower('a'));
}
*/
