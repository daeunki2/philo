/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:52:04 by theveste          #+#    #+#             */
/*   Updated: 2023/11/22 13:50:03 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	nb = n;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	nb = nb % 10;
	ft_putchar_fd((nb + 48), fd);
}
