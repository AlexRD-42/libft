/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:14:04 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/21 12:45:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTS_H
# define FDF_STRUCTS_H
# include "mlx.h"
# include "mlx_int.h"

typedef union u_argb
{
	struct
	{
		uint8_t	a;
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;
	};
	uint32_t	argb;
}	t_argb;

typedef struct s_vertex
{
	int32_t		x;
	int32_t		y;
	int32_t		z;
	uint32_t	argb;
}	t_vtx;

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
	double			f64;
	uint64_t		u64;
}	t_vec2;

typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef struct t_vec4
{
	float	x;	// Abscissa
	float	y;	// Ordinate
	float	z;	// Altitude
	float	w;	// Normalization Vector
}	t_vec4;

typedef union u_mat4
{
	t_vec4		row[4];
	float		m[4][4];
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
}	t_mat4;

typedef struct s_params
{
	float	dx;		// (Top-view) Moves right and left
	float	dy;		// (Top-view) Moves up and down
	float	dz;		// (Top-view) Moves towards the camera
	float	rx;		// Roll
	float	ry;		// Pitch
	float	rz;		// Yaw
}	t_params;

typedef struct s_frustrum
{
	float	near;	// Near z plane camera
	float	far;	// Far z plane camera
	float	fov;	// Field of view
	float	ar;		// Aspect Ratio
}	t_frustrum;

typedef struct s_event_status
{
	uint8_t	alt_pressed;
}	t_evstatus;

typedef struct s_vars
{
	t_xvar		*mlx;
	t_img		*img;
	t_vtx		*ptr;
	size_t		length;
	int32_t		max;
	int32_t		min;
	uint32_t	rows;
	uint32_t	cols;
	t_evstatus	evstatus;
}	t_vars;

#endif