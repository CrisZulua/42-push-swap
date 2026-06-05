/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: czuluaga <czuluaga@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 08:48:24 by czuluaga          #+#    #+#             */
/*   Updated: 2026/04/20 11:27:20 by czuluaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION
	The ft_lstclear() function deletes and frees the given node and all its
	successors, using the function 'del' to free its content and free() to
	free the node itself.

	Finally, set the pointer to the list to NULL.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr;
	t_list	*cnext;

	curr = *lst;
	while (curr)
	{
		cnext = curr->next;
		ft_lstdelone(curr, del);
		curr = cnext;
	}
	*lst = NULL;
}
