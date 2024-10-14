/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:26:33 by theveste          #+#    #+#             */
/*   Updated: 2023/11/14 13:49:37 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

/*
int main(void)
{
	// On creer un tableau d'int qui se fera initialiser a
		 0 grace a notre fonction bzero
	int tab_int[4] = {2, 2147483647, 2, 3};
	int	i = 0;
	// On affiche notre tableau pour etre sur des que les valeur 
		on bien ete rentre
	printf("Les valeurs du tableau : ");
	while (i < 4)
	{
		printf("%d", tab_int[i]);
		i++;
	}
	i = 0;

	printf("\nLes valeur du tableau apres utilisation de la fonction bzero : ");
	ft_bzero(tab_int, 25);
	while(i < 4)
	{
		printf("%d", tab_int[i]);
		i++;
	}
}
*/