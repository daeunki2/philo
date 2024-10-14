/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 05:57:30 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 10:48:28 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_length;
	char	*ret;
	int		i;

	i = 0;
	total_length = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * total_length + 1);
	if (!(ret))
		return (NULL);
	while (*s1 != '\0')
	{
		ret[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		ret[i] = *s2;
		i++;
		s2++;
	}
	ret[i] = '\0';
	return (ret);
}

/*
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Veuillez rentrer deux chaine de character pls !");
		return (0);
	}
	char *new_chaine;
	new_chaine = ft_strjoin(argv[1], argv[2]);
	printf("La nouvelle chaine est desormais ' %s '", new_chaine);
}
*/