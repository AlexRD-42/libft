/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:36:17 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/22 22:01:26 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

# include <stdint.h>
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef union u_type32
{
	uint32_t	u32;
	int32_t		i32;
	uint8_t		u8[4];
	float		f32;
}	t_32;

typedef union u_type64
{
	uint64_t	u64;
	int64_t		i64;
	double		f64;
	float		f32[2];
	uint32_t	u32[2];
	int32_t		i32[2];
	uint8_t		u8[8];
}	t_64;

typedef struct s_array
{
	union
	{
		void		*v;
		size_t		*w;
		int8_t		*i8;
		uint8_t		*u8;
		int32_t		*i32;
		uint32_t	*u32;
		int64_t		*i64;
		uint64_t	*u64;
		float		*f32;
		double		*f64;
	};
	size_t		length;
}	t_array;

#endif