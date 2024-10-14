/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:07:52 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 12:58:11 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

int	ft_strncmp( const char *first, const char *second, size_t length )
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while ((i < length - 1) && (first[i] == second[i]) && first[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
/*
int main() 
{

    printf("%d", ft_strncmp("salut", "saltt", 4));
    return 0;
}
*/