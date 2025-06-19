/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:32:44 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/19 17:30:38 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

// void	draw_image(t_img *img, t_fdf_array *array)
// {
// 	size_t	i;
// 	size_t	j;
// 	int32_t (*image_array)[array->cols] = (int32_t (*)[array->cols])array->ptr;

// 	i = 0;
// 	j = 0;
// 	while (i < array->rows)
// 	{
// 		j = 0;
// 		while (j < array->cols)
// 		{
// 			cmlx_putpixel(img, j, i, ft_lerp(array->max, array->min, image_array[i][j]));
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	bresenham_draw_line(t_img *img, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
{
	const int32_t	dx = (x1 - x0);
	const int32_t	dy = (y1 - y0);
	int32_t			offset;

	offset = 2 * dy - dx;
	while (x0 < x1 || y0 < y1)
	{
		cmlx_putpixel(img, x0, y0, 0x00FFFFFF);
		y0 += (offset > 0);
		x0++;
		offset += (dy << 1) - (dx << (offset > 0));
	}
}