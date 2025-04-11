/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:34:36 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 16:34:36 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_reverse(void *array_void, size_t size)
{
	unsigned char	*start;
	unsigned char	*end;
	unsigned char	buffer;

	start = (unsigned char *) array_void;
	end = start + size - 1;
	while (start < end)
	{
		buffer = *start;
		*start = *end;
		*end = buffer;
		start++;
		end--;
	}
}
