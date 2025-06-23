/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmlx_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:20:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/22 11:03:50 by adeimlin         ###   ########.fr       */
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

__always_inline
void	cmlx_putargb(t_img *img, uint32_t x, uint32_t y, uint32_t src)
{
	uint32_t		*dst;
	const uint32_t	alpha = src >> 24;
	uint32_t		rb_dst; 
	uint32_t		ga_dst;

	dst = (uint32_t *) (img->data + y * img->width + x);
	rb_dst = *dst & 0x00FF00FF;
	ga_dst = (*dst >> 8) & 0x00FF00FF;
	rb_dst += (((src & 0x00FF00FF) - rb_dst) * alpha) >> 8;
	ga_dst += ((((src >> 8) & 0x00FF00FF) - ga_dst) * alpha) >> 8;
	*dst = (rb_dst & 0x00FF00FF) | ((ga_dst & 0x00FF00FF) << 8);
}

// __always_inline
// void	cmlx_putargb(t_img *img, uint32_t x, uint32_t y, uint32_t src)
// {
// 	uint32_t	*dst;
// 	uint64_t	argb_dst;
// 	uint64_t	argb_src;
// 	uint64_t	alpha;
// 	uint64_t	reg64;

// 	alpha = (src >> 24);
// 	dst = (uint32_t *) (img->data + y * img->width + x);
// 	argb_dst = (((uint64_t) *dst) & 0xFF00FF00ULL) << 32;
// 	argb_dst |= ((uint64_t) *dst) & 0x00FF00FFULL;
// 	argb_src = (((uint64_t) src) & 0xFF00FF00ULL) << 32;
// 	argb_src |= ((uint64_t) src) & 0x00FF00FFULL;
// 	reg64 = (argb_dst + (argb_src - argb_dst) * alpha) >> 8;
// 	reg64 &= 0x00FF00FF00FF00FFULL;
// 	reg64 = ((reg64 >> 32) | reg64) & 0xFFFFFFFFULL;
// 	*dst = (uint32_t) reg64;
// }

void	cmlx_destroy(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->mlx->win_list);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->fdf); // This already frees vec
	vars->vec = NULL;
	vars->mlx = NULL;
	vars->fdf = NULL;
}
