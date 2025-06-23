/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:32:44 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/23 14:37:15 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

// static
// void	dline_bresenham(t_img *img, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
// {
// 	const int32_t	dx = (x1 - x0);
// 	const int32_t	dy = (y1 - y0);
// 	int32_t			offset;

// 	offset = 2 * dy - dx;
// 	while (x0 < x1 || y0 < y1)
// 	{
// 		cmlx_putpixel(img, x0, y0, 0x00FFFFFF);
// 		y0 += (offset > 0);
// 		x0++;
// 		offset += (dy << 1) - (dx << (offset > 0));
// 	}
// }

// Calculate a gradient that goes from p0 to p1 color (Alpha goes from 00 to FF basically)
// Everything here should be an integer, floats should only be used to determine p0.X -> p1.X by scaling to display
// This function should receive integer points, other function responsability to determine this
static
void	dline_float(t_img *img, t_vtx p0, t_vtx p1)
{
	const uint32_t	length = ft_imax(ft_iabs((p1.x - p0.x)), ft_iabs((p1.y - p0.y)));
	const float		dx = (double) (p1.x - p0.x) / (double) length;
	const float		dy = (double) (p1.y - p0.y) / (double) length;
	uint32_t		i;
	t_vec2			vector;

	i = 0;
	vector.x = p0.x;
	vector.y = p0.y;
	while (i <= length)
	{
		cmlx_putrgb(img, vector.x, vector.y, 0xFFFFFF);
		vector.x += dx;
		vector.y += dy;
		i++;
	}
}

static
void	draw(t_vars *vars, t_vec3 fp0, t_vec3 fp1)
{
	t_vtx	p0;
	t_vtx	p1;

	p0.x = 400 + (fp0.x + 1.0f) * 0.5f * 640;
	p0.y = 300 + (fp0.y + 1.0f) * 0.5f * 480;
	p1.x = 400 + (fp1.x + 1.0f) * 0.5f * 640;
	p1.y = 300 + (fp1.y + 1.0f) * 0.5f * 480;
	if (p1.x > WIDTH || (int) p1.x < 0 || p1.y > HEIGHT || (int) p1.y < 0)
	{
		p1.color = 0;
	}
	if (p0.x > WIDTH || (int) p0.x < 0 || p0.y > HEIGHT || (int) p0.y < 0)
	{
		p1.color = 0;
	}

	dline_float(vars->img, p0, p1);
}

static inline
float	absmaxvec(t_vec3 vec)
{
	return (ft_max(ft_abs(vec.z), ft_max(ft_abs(vec.x), ft_abs(vec.y))));
}

static
void	normalize(t_vec3 *vec, size_t length)
{
	size_t	i;
	float	max = 0.0f;

	i = 0;
	while (i < length)
		max = ft_max(ft_abs(max), absmaxvec(vec[i++]));
	max = 1.0f / max;
	i = 0;
	while (i < length)
	{
		vec[i].x *= max;
		vec[i].y *= max;
		vec[i].z *= max;
		i++;
	}
}
// Could pre-compute neighbour pairs for better cache prediction and eliminate branching
// Total number of pairs = (rows - 1) * cols + (cols - 1) * rows
// rows * cols - cols + rows * cols - rows
// = 2 rows*cols - rows - cols
void	draw_lines(t_vars *vars)
{
	size_t	row;
	size_t	col;
	t_vec3 	(*vector)[vars->cols] = (t_vec3 (*)[vars->cols])vars->vec;

	normalize(vars->vec, vars->length);
	row = 0;
	while (row < vars->rows)
	{
		col = 0;
		while (col < vars->cols)
		{
			if (col + 1 < vars->cols)
				draw(vars, vector[row][col], vector[row][col + 1]);
			if (row + 1 < vars->rows)
				draw(vars, vector[row][col], vector[row + 1][col]);
			col++;
		}
		row++;
	}
}
