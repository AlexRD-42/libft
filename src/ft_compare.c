/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 20:25:35 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/12 20:25:35 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int32_t	ft_memcmp(const void *addr1_void, const void *addr2_void, size_t data_size)
{
	const uint8_t	*addr1 = (const uint8_t *) addr1_void;
	const uint8_t	*addr2 = (const uint8_t *) addr2_void;

	if (addr1_void == addr2_void)
		return (0);
	while (data_size > 0)
	{
		if (*addr1 != *addr2)
			return (*addr1 - *addr2);
		addr1++;
		addr2++;
		data_size--;
	}
	return (0);
}

int32_t	ft_memrcmp(const void *addr1_void, const void *addr2_void, size_t data_size)
{
	const uint8_t	*addr1 = (const uint8_t *) addr1_void + data_size - 1;
	const uint8_t	*addr2 = (const uint8_t *) addr2_void + data_size - 1;

	if (addr1_void == addr2_void)
		return (0);
	while (data_size > 0)
	{
		if (*addr1 != *addr2)
			return (*addr1 - *addr2);
		addr1--;
		addr2--;
		data_size--;
	}
	return (0);
}

int32_t	ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 != 0 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *) str1 - *(unsigned char *) str2);
}

int32_t	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (n > 0)
	{
		if (*str1 != *str2)
			return (*(unsigned char *) str1 - *(unsigned char *) str2);
		if (*str1 == 0)
			break ;
		str1++;
		str2++;
		n--;
	}
	return (0);
}
