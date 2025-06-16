/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:33:11 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 12:49:14 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	ft_strncmp(const char *str1, const char *str2, size_t length)
{
	while (length > 0)
	{
		if (*str1 != *str2 || *str1 == 0)
			return (*(unsigned char *) str1 - *(unsigned char *) str2);
		str1++;
		str2++;
		length--;
	}
	return (0);
}
