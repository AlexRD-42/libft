/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:54:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 17:36:45 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

// Needs optimization
const
void	*ft_memchr(const void *ptr_void, uint8_t byte, size_t length)
{
	const uint8_t	*ptr = (const uint8_t *) ptr_void;

	while (length > 0)
	{
		if (*ptr == byte)
			return (ptr);
		length--;
		ptr++;
	}
	return (NULL);
}

// Needs optimization
int64_t	ft_memcmp(const void *ptr1_void, const void *ptr2_void, size_t length)
{
	const uint8_t	*ptr1 = (const uint8_t *) ptr1_void;
	const uint8_t	*ptr2 = (const uint8_t *) ptr2_void;

	if (ptr1_void == ptr2_void)
		return (0);
	while (length > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		length--;
	}
	return (0);
}

int64_t	ft_memrcmp(const void *ptr1_void, const void *ptr2_void, size_t length)
{
	const uint8_t	*ptr1 = (const uint8_t *) ptr1_void + length - 1;
	const uint8_t	*ptr2 = (const uint8_t *) ptr2_void + length - 1;

	if (ptr1_void == ptr2_void)
		return (0);
	while (length > 0)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1--;
		ptr2--;
		length--;
	}
	return (0);
}