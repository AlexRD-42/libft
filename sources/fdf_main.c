/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:24:50 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/19 17:31:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

void	draw_line_float(t_img *img, uint32_t x0, uint32_t y0, uint32_t x1, uint32_t y1)
{
	const uint32_t	length = ft_imax(ft_iabs((x1 - x0)), ft_iabs((y1 - y0)));
	const float		dx = (double) (x1 - x0) / (double) length;
	const float		dy = (double) (y1 - y0) / (double) length;
	uint32_t		i;

	i = 0;
	while (i < length)
	{
		cmlx_putpixel(img, x0, y0, 0x00FFFFFF);
		x0 += dx;
		y0 += dy;
		i++;
	}
}

void	wireframe(t_img *img, t_fdf_array *array)
{
	size_t			row;
	size_t			col;
	const float		dx = WIDTH / array->cols;
	const float		dy = HEIGHT / array->rows;
	int32_t (*image_array)[array->cols] = (int32_t (*)[array->cols])array->ptr;

	row = 0;
	while (row < array->rows - 1)
	{
		col = 0;
		while (col < array->cols - 1)
		{
			// if (image_array[row][col] && image_array[row][col + 1])
			// 	draw_line(img, col * dx, row * dy, (col + 1) * dx, row * dy);
			if (image_array[row][col] && image_array[row + 1][col])
				draw_line_float(img, col * dx, row * dy, col * dx, (row + 1) * dy);	
			col++;
		}
		row++;
	}
}

int	main(void)
{
	t_xvar		*mlx;
	t_img		*img;
	t_fdf_array	array;

	fdf_read("resources/maps/42.fdf", " \n", &array);
	mlx = mlx_init();
	mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img = mlx_int_new_image(mlx, WIDTH, HEIGHT, ZPixmap);
	wireframe(img, &array);
	// draw_line(img, 32, 32, 256, 256);
	mlx_put_image_to_window(mlx, mlx->win_list, img, 0, 0);
	cmlx_destroy(mlx, img, &array);
}
