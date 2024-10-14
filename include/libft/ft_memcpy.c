/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 00:35:57 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 13:14:42 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	while (i < count)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	int	og[4] = {1, 58, 2147483647, -25};
	int	*temp_mem = malloc(sizeof(int) * 4);
	if (temp_mem == NULL)
		return (0);
	temp_mem = ft_memcpy(temp_mem, og, 4*4);
	int	i = 0;
	while (i < 4)
	{
		printf("%d ", temp_mem[i]);
		i++;
	}
}
*/
