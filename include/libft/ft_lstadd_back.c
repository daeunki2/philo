/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:33:57 by theveste          #+#    #+#             */
/*   Updated: 2023/11/22 15:31:02 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (temp == NULL)
		*lst = new;
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
	}
}

/*

CE CODE N'EST PAS VALABLE AVEC UN TESTEUR QUI N'ALLOUE PAS DE MEMOIRE POUR NEW;;

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (temp == NULL)
	{
		*lst = new;
		//// new->next = NULL;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = new;
		//// new->next = NULL; 
	}
}

#CODE VALABLE , VERIF REALISER, 
#NEXT->NULL N'EST PAS PRECISER ET EST SUPPOSER REALISEE

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last // Variable temp pour ne pas perdre le pointeur;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}
*/