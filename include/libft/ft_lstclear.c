/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:51:36 by theveste          #+#    #+#             */
/*   Updated: 2023/11/23 11:32:09 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = *lst;
	while (temp != NULL)
	{
		temp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}

/*

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp; // Creation d'une variable temporaire 
	pour ne pas perdre le pointeur origin

	while (*lst)   (|| *lst != NULL )
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, *del);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}

*/