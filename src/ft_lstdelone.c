/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:44:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 16:50:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Takes a node as parameter and frees its content
// using the function del. Free the node itself but
// does NOT free the next node.
// lst: The node to free.
// del: The address of the function used to delete
// the content.
void	ft_lstdelone(t_list *lst, void (*del)(void	*))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}
