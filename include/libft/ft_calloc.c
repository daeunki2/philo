/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 03:47:42 by theveste          #+#    #+#             */
/*   Updated: 2024/06/18 14:59:04 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementSize, size_t elementCount)
{
	void	*new_mem;

	if (elementSize != 0 && elementCount > (size_t) - 1 / elementSize)
		return (NULL);
	new_mem = malloc(elementCount * elementSize);
	if (new_mem == NULL)
		return (NULL);
	ft_bzero(new_mem, (elementCount * elementSize));
	return (new_mem);
}
/*
int	main() 
{
	char	*mem;
	int i = 0;
	mem = ft_calloc(10, 4);
	while (i < 10)
	{
		printf("%d", mem[i]);
		i++;
	}	
}
*/