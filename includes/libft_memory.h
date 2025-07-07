/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:40:44 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 20:10:17 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H

# include <stdint.h>
# include <stddef.h>

void		*ft_calloc(size_t arr_size, size_t type_size);
void		*ft_realloc(void *src, size_t src_size, size_t dst_size);
void		**ft_free_array(void *array, size_t length);

void		*ft_memset(void *dst_void, const uint8_t byte, size_t length);
void		*ft_bzero(void *dst_void, size_t length);
void		*ft_memcpy(void *dst_void, const void *src_void, size_t length);

int64_t		ft_memcmp(const void *ptr1_v, const void *ptr2_v, size_t length);
int64_t		ft_memrcmp(const void *ptr1_v, const void *ptr2_v, size_t length);
const void	*ft_memchr(const void *ptr_void, uint8_t byte, size_t length);

void		ft_swap(void *a_void, void *b_void, size_t length);
void		ft_swap8(void *a, void *b);
void		ft_swap32(void *a, void *b);
void		ft_swap64(void *a, void *b);
void		ft_reverse(void *array, size_t length, size_t element_size);

#endif
