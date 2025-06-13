/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:36:17 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/13 17:37:03 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
 #define FT_TYPES_H

#include <stdint.h>
#include <stddef.h>

typedef union u_type32
{
	uint32_t	ui;
	int32_t		i;
	uint8_t		b[4];
	float		f;
}	t_32;

typedef union u_type64
{
	uint64_t	ul;
	int64_t		l;
	double		d;
	float		f[2];
	uint32_t	ui[2];
	int32_t		i[2];
	uint8_t		b[8];
}	t_64;

typedef union u_pointers
{
	void		*v0;
	int8_t		*i8;
	uint8_t		*u8;
	int32_t		*i32;
	uint32_t	*u32;
	int64_t		*i64;
	uint64_t	*u64;
	float		*f32;
	double		*f64;
}	t_pointers;

typedef struct s_array
{
	t_pointers	ptr;
	size_t		length;
}	t_array;

#endif