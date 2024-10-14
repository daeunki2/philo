/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 05:10:04 by theveste          #+#    #+#             */
/*   Updated: 2023/11/15 13:18:52 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;
	size_t	n_len;
	char	*bg;

	if ((big == NULL || little == NULL) && !len)
		return (NULL);
	if (!*little)
		return ((char *)big);
	i = 0;
	bg = (char *)big;
	n_len = ft_strlen(little);
	if (n_len == 0 || big == little)
		return (bg);
	while (bg[i] != '\0' && i < len)
	{
		c = 0;
		while (bg[i + c] && little[c] && bg[i + c] == little[c]
			&& i + c < len)
			c++;
		if (c == n_len)
			return (bg + i);
		i++;
	}
	return (NULL);
}

/*
int	main()
{
	char str[] = "abcDEFghijklmDEFnopqrstuvwxyz";
	//char fnd[] = "";
	char fnd[] = "DEF";
	printf("%s", ft_strnstr(str, fnd, 6));
	return (0);
}
*/
