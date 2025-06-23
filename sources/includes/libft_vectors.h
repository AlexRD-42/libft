/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_vectors.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 22:02:29 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/22 22:26:47 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_VECTORS_H
# define LIBFT_VECTORS_H

# include <stdint.h>
typedef union u_vec2
{
	struct
	{
		float		x;
		float		y;
	};
	struct
	{
		int32_t		ix;
		int32_t		iy;
	};
	struct
	{
		uint32_t	ux;
		uint32_t	uy;
	};
	uint32_t	u32[2];
	float		f32[2];
	double		f64;
	uint64_t	u64;
}	t_vec2;

typedef union u_vec3
{
	struct
	{
		float		x;
		float		y;
		float		z;
	};
	struct
	{
		int32_t		ix;
		int32_t		iy;
		int32_t		iz;
	};
	struct
	{
		uint32_t	ux;
		uint32_t	uy;
		uint32_t	uz;
	};
	uint32_t	u32[3];
	float		f32[3];
}	t_vec3;

typedef union u_vec4
{
	struct
	{
		float		x;
		float		y;
		float		z;
		float		w;
	};
	struct
	{
		int32_t		ix;
		int32_t		iy;
		int32_t		iz;
		int32_t		iw;
	};
	struct
	{
		uint32_t	ux;
		uint32_t	uy;
		uint32_t	uz;
		uint32_t	uw;
	};
	uint32_t	u32[4];
	float		f32[4];
	uint64_t	u64[2];
	double		f64[2];
	__uint128_t	u128;
	__float128	f128;
}	t_vec4;

typedef union u_mat3
{
	struct
	{
		float	a1;
		float	a2;
		float	a3;
		float	b1;
		float	b2;
		float	b3;
		float	c1;
		float	c2;
		float	c3;
	};
	float		d1[9];
	float		d2[3][3];
	t_vec3		row[3];
}	t_mat3;

typedef union u_mat4
{
	struct
	{
		float	a1;
		float	a2;
		float	a3;
		float	a4;
		float	b1;
		float	b2;
		float	b3;
		float	b4;
		float	c1;
		float	c2;
		float	c3;
		float	c4;
		float	d1;
		float	d2;
		float	d3;
		float	d4;
	};
	float		d1[16];
	float		d2[4][4];
	t_vec4		row[4];
}	t_mat4;

#endif