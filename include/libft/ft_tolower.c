/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:35:49 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 12:58:46 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int character)
{
	if (character >= 'A' && character <= 'Z')
		return (character + 32);
	return (character);
}

/*
int main(void)
{
	printf("%c", ft_tolower('A'));
}
*/