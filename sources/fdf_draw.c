/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:32:44 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/25 00:04:03 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

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
		if (vector.x > 0 && vector.y > 0 && vector.x < WIDTH && vector.y < HEIGHT)
			cmlx_putrgb(img, vector.x, vector.y, 0xFFFFFF);
		vector.x += dx;
		vector.y += dy;
		i++;
	}
}

// Clamping should occur in draw line
// It is acceptable for the image to have pairs that are outside of the drawing region
// But the slope of the line should be preseved when clamping
// If all points are outside of the draw region, no-op
static
void	draw(t_vars *vars, t_vec3 fp0, t_vec3 fp1)
{
	t_vtx	p0;
	t_vtx	p1;

	p0.x = (fp0.x + 1.0f) * 0.5f * vars->cols * vars->zoom;
	p0.y = (fp0.y + 1.0f) * 0.5f * vars->rows * vars->zoom;
	p1.x = (fp1.x + 1.0f) * 0.5f * vars->cols * vars->zoom;
	p1.y = (fp1.y + 1.0f) * 0.5f * vars->rows * vars->zoom;
	dline_float(vars->img, p0, p1);
}

// Could pre-compute neighbour pairs for better cache prediction and eliminate branching
// Total number of pairs = (rows - 1) * cols + (cols - 1) * rows
// = 2 rows*cols - rows - cols
void	draw_lines(t_vars *vars)
{
	size_t	row;
	size_t	col;
	t_vec3 	(*vector)[vars->cols] = (t_vec3 (*)[vars->cols])vars->vec;

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
