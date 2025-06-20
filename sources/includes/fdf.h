/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:58:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/20 16:44:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stddef.h>
# include "mlx.h"
# include "mlx_int.h"

#define WIDTH 1920
#define HEIGHT 1080
#define SCALE 16
#define ZSCALE 2
#define EPS 1.90734863e-06

// int32_t (*image_array)[array->cols] = (int32_t (*)[array->cols])array->ptr;

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

typedef struct s_fdf_array
{
	t_vtx		*ptr;
	size_t		length;
	int32_t		max;
	int32_t		min;
	uint32_t	rows;
	uint32_t	cols;
}	t_fdf_array;

// Maybe need to make a union to make this efficient with matmult
// typedef union u_vec3
// {
// 	struct
// 	{
// 		int32_t	x;
// 		int32_t	y;
// 		int32_t	z;
// 		int32_t	rgb;
// 	};
// 	void		*ptr;
// }	t_vec3;

void	*mlx_int_new_image(t_xvar *xvar, int width, int height, int format);
void	fdf_read(const char *str, const char *charset, t_fdf_array *array);
uint32_t ft_lerp(int32_t max, int32_t min, int32_t value);
void	cmlx_putrgb(t_img *img, uint32_t x, uint32_t y, uint32_t argb);
void	cmlx_destroy(t_xvar *mlx, t_img *img, t_fdf_array *array);
void	mat_chain(t_fdf_array *array);
void	draw_lines(t_img *img, t_fdf_array *array);
#endif