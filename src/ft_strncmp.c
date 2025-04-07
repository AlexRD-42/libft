/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:33:11 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/07 11:33:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (n > 0)
	{
		n--;
		if (*str1 != *str2)
			return (*(unsigned char *) str1 - *(unsigned char *) str2);
		if (*str1 == 0)
			break;
		str1++;
		str2++;
	}
	return (0);
}