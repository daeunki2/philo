/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:39:37 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 12:57:37 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}

/*
int main(int argc, char **argv)
{
	char *valeur;

	if (argc != 3)
	{
		printf("Veuillez rentrer une chaine de charactere, et un character a 
			rechercher");
		return (0);
	}
	valeur = ft_strchr(argv[1], argv[2][0]);
	if (valeur == 0)
	{
		printf("Aucune occurence n'a ete trouvee");
		return (0);
	}
	else
	{
		printf("le charactere ' %c ' a ete trouver dans la chaine ' %s ' 
			a l'adresse %p", *valeur, argv[1], valeur);
		return (0);
	}
}
*/