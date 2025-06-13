/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 10:17:49 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/27 11:49:00 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_tmp;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	lst_tmp = *lst;
	while (lst_tmp->next != NULL)
		lst_tmp = (lst_tmp)->next;
	lst_tmp->next = new;
}
