/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 19:32:45 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 19:32:45 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds the node new at the end of the list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst == NULL || new == NULL)
		return;
	// check this shit
	if (*lst == NULL)
	{
		*lst = new;
		return;
	}
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}