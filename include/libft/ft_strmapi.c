/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:53:27 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 15:37:54 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char	test(unsigned int i, char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

void	print(char *s, char (*test)(char c))
{
	int	i;

	i = 0;
	unsigned int i = 0;
	while (i < ft_strlen(s))
	{
		printf("%c", (*test)(i, s[i]));
		i++;
	}
}
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	length;
	char			*mem;
	unsigned int	i;

	length = ft_strlen(s);
	i = 0;
	mem = malloc(sizeof(char) * length + 1);
	if (mem == NULL)
		return (NULL);
	while (i < length)
	{
		mem[i] = (*f)(i, s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
