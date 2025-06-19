/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cmlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:20:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/18 16:06:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include "fdf.h"

__always_inline
void	cmlx_putpixel(t_img *img, uint32_t x, uint32_t y, uint32_t argb)
{
	((uint32_t (*)[img->width])img->data)[y][x] = argb;
}

void	cmlx_destroy(t_xvar *mlx, t_img *img, t_fdf_array *array)
{
	mlx_destroy_window(mlx, mlx->win_list);
	mlx_destroy_image(mlx, img);
	mlx_destroy_display(mlx);
	free(mlx);
	free(array->ptr);
	array->ptr = NULL;
}
