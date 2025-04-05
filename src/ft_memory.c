/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:36:02 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/05 14:36:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "..\includes\libft.h"

void	*ft_memcpy(void *dst_void, const void *src_void, size_t n)
{
	char		*dst;
	const char	*src;
	size_t		i;

	dst = (char *) dst_void;
	src = (const char *) src_void;
	if (n == 0 || dst == src)
		return (dst_void);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst_void);
}

void	*ft_memmove(void *dst_void, const void *src_void, size_t n)
{
	char		*dst;
	const char	*src;
	size_t		i;

	dst = (char *) dst_void;
	src = (const char *) src_void;
	if (n == 0 || dst == src)
		return (dst_void);
	if ((unsigned long) dst < (unsigned long) src)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (--n > 0)
			dst[n] = src[n];
		dst[0] = src[0];
	}
	return (dst_void);
}

void	*ft_memchr(const void *addr_void, int c, size_t n)
{
	const char	*addr;
	size_t		i;

	addr = (const char *) addr_void;
	i = 0;
	while (i < n)
	{
		if (addr[i] == (unsigned char) c)
			return ((void *) (addr + i));
		i++;
	}
	return (NULL);
}

int	ft_memcmp(const void *addr1_void, const void *addr2_void, size_t n)
{
	const char	*addr1;
	const char	*addr2;
	size_t	i;

	addr1 = (const char *) addr1_void;
	addr2 = (const char *) addr2_void;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (addr1[i] != addr2[i])
			return ((unsigned char) addr1[i] - (unsigned char) addr2[i]);
		i++;
	}
	return (0);
}

void	*ft_memset(void *dst_void, int c, size_t n)
{
	char	*dst;
	size_t	i;

	dst = (char *) dst_void;
	i = 0;
	while (i < n)
	{
		dst[i] = (unsigned char) c;
		i++;
	}
	return(dst_void);
}