/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:54:49 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 12:54:49 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..\..\includes\libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 != 0 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *) str1 - *(unsigned char *) str2);
}