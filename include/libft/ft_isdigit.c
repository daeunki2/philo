/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:39:04 by theveste          #+#    #+#             */
/*   Updated: 2023/11/14 13:53:13 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (2);
	return (0);
}

/*
int main()
{
	printf("%d\n", ft_isdigit('Z'));
	printf("%d\n", ft_isdigit('\\'));
	printf("%d\n", ft_isdigit('8'));
}
*/
