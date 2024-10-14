/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:21:17 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 13:07:53 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	signe;

	i = 0;
	nbr = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - 48;
		i++;
	}
	return (signe * nbr);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void) // Veuilez rentrer une chaine de character 
								//a tranformer apres le nom de l'executable
{
	printf("%d : %d\n", ft_atoi("2147483647"), atoi("2147483647"));
	printf("%d : %d\n", ft_atoi("0"), atoi("0"));
	printf("%d : %d\n", ft_atoi("-85"), atoi("-85"));
	printf("%d : %d\n", ft_atoi("15236"), atoi("15236"));
	printf("%d : %d\n", ft_atoi("-2147483648"), atoi("-2147483648"));
	printf("%d : %d\n", ft_atoi("--  458"), atoi("--  458"));
}
*/
