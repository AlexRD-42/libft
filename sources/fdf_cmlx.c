/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cmlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:20:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/20 13:12:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft.h"
#include <math.h>
#include "fdf.h"

// Check if this is multiplication
__always_inline
void	cmlx_putrgb(t_img *img, uint32_t x, uint32_t y, uint32_t argb)
{
	((uint32_t (*)[img->width])img->data)[y][x] = argb;
}

// __always_inline
// void	put_argb(t_img *img, uint32_t x, uint32_t y, uint32_t argb)
// {
//     t_argb			*dst;
// 	const t_argb	src = {.argb = argb};

// 	dst = (t_argb *) (img->data + y * img->width + x);
// 	dst->r += (int32_t) (src.r - dst->r) * src.a >> 8; 
// 	dst->g += (int32_t) (src.g - dst->g) * src.a >> 8; 
// 	dst->b += (int32_t) (src.b - dst->b) * src.a >> 8; 
// 	dst->a += (int32_t) (0x0FF - dst->a) * src.a >> 8;
// }

// __always_inline
// void	cmlx_putargb(t_img *img, uint32_t x, uint32_t y, uint32_t src)
// {
// 	uint32_t		*dst;
// 	const uint32_t	alpha = src >> 24;
// 	uint32_t		rb_dst; 
// 	uint32_t		ga_dst;

// 	dst = (uint32_t *) (img->data + y * img->width + x);
// 	rb_dst = *dst & 0x00FF00FF;
// 	ga_dst = (*dst >> 8) & 0x00FF00FF;
// 	rb_dst += (((src & 0x00FF00FF) - rb_dst) * alpha) >> 8;
// 	ga_dst += ((((src >> 8) & 0x00FF00FF) - ga_dst) * alpha) >> 8;
// 	*dst = (rb_dst & 0x00FF00FF) | ((ga_dst & 0x00FF00FF) << 8);
// }

void	cmlx_destroy(t_xvar *mlx, t_img *img, t_fdf_array *array)
{
	mlx_destroy_window(mlx, mlx->win_list);
	mlx_destroy_image(mlx, img);
	mlx_destroy_display(mlx);
	free(mlx);
	free(array->ptr);
	array->ptr = NULL;
}
