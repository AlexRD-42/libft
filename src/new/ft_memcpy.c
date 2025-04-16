/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 14:35:33 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/15 14:35:33 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static inline void	ft_fwdcpy(uint8_t *dst, const uint8_t *src, size_t n)
{
	const size_t		words = n / sizeof(uintptr_t);
	const uintptr_t		*src_word;
	uintptr_t			*dst_word;

	n = n % sizeof(uintptr_t) + 1;
	while (--n > 0)
		*dst++ = *src++;
	src_word = (const uintptr_t *) src;
	dst_word = (uintptr_t *) dst;
	while (n++ < words)
		*dst_word++ = *src_word++;
}

static inline void	ft_bwdcpy(uint8_t *dst, const uint8_t *src, size_t n)
{
	const size_t		words = n / sizeof(uintptr_t *);
	const uintptr_t		*src_word;
	uintptr_t			*dst_word;

	n = n % sizeof(uintptr_t *) + 1;
	while (--n > 0)
		*--dst = *--src;
	src_word = (const uintptr_t *) src;
	dst_word = (uintptr_t *) dst;
	while (n++ < words)
		*--dst_word = *--src_word;
}

// 0. If there are less than 16 bytes to be copied, do normal byte copying
// 1. Determine copy direction and word alignment
// 2. Copy byte by byte until aligned
// 3. Copy word by word
// 4. Perform tail copy byte by byte

void	*ft_memcpy(void *dst_void, const void *src_void, size_t n)
{
	const size_t		words = n / sizeof(uintptr_t);
	const unsigned char	*src = (const unsigned char *) src_void;
	unsigned char		*dst;

	dst = (unsigned char *) dst_void;
	if (n >= 16)
	{
		
	}

	return (dst_void);
}
