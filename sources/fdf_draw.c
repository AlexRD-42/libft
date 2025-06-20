/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:32:44 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/20 13:33:44 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
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

// If i draw the max Z first, i can then stop drawing the line if there was something there already
// Calculate a gradient that goes from p0 to p1 color (Alpha goes from 00 to FF basically)
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

// Could pre-compute neighbour pairs for better cache prediction and eliminate branching
void	draw_lines(t_img *img, t_fdf_array *array)
{
	size_t	row;
	size_t	col;
	t_vtx 	(*vertex)[array->cols] = (t_vtx (*)[array->cols])array->ptr;

	row = 0;
	while (row < array->rows)
	{
		col = 0;
		while (col < array->cols)
		{
			if (col + 1 < array->cols)
				dline_float(img, vertex[row][col], vertex[row][col + 1]);
			if (row + 1 < array->rows)
				dline_float(img, vertex[row][col], vertex[row + 1][col]);
			col++;
		}
		row++;
	}
}
