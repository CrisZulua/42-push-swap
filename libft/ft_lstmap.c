/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:48:40 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/20 11:28:04 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The function ft_lstmap() iterates through the list 'lst', applies the
	function 'f' to each node's content, and creates a new list resulting
	of the  successive  applications  of  the  funciton  'f'.  The  'del'
	function is used to delete the content of a node if needed.

	RETURN
	The function ft_lstmap() returns a pointer to the new list created.
	NULL if the memory allocation fails.
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*prev;
	t_list	*node;

	new_lst = NULL;
	prev = NULL;
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (!node)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		if (!new_lst)
			new_lst = node;
		if (prev)
			prev->next = node;
		prev = node;
		lst = lst->next;
	}
	return (new_lst);
}
