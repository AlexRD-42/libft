/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:10:03 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 19:10:03 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates and returns a new node. The content member variable is initialized with the given parameter 
// content The variable next is initialized to NULL.
// Return: Pointer to the new node

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *) malloc (sizeof(t_list));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}