/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 04:01:31 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 12:25:39 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (ret == NULL)
		return (NULL);
	while (src[i] != '\0')
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

/*
int main(int argc, char **argv)
{
	char *new_mem;
	if (argc != 2)
	{
		printf("Rentrer une chaine de charactere a dupliquer ! ");
		return (0);
	}
	new_mem = ft_strdup(argv[1]);
	if (new_mem == NULL)
		return (0);
	printf("On verifie si la valeur renvoyer par notre fonction ft_strdup 
		n'est pas nul\n");
	printf("...\n");
	printf("La nouvelle chaine ' %s ' a ete atribuer en memoire a l'adresse 
		%p", new_mem, new_mem);
	
	free(new_mem);
	
	return (0);
}
*/