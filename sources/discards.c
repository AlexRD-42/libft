/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   discards.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:51:33 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/24 20:35:17 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
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


void	fill_screen(t_img *img, uint32_t argb)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			cmlx_putpixel(img, i, j, argb);
			j++;
		}
		i++;
	}
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

__always_inline
void	cmlx_putargb(t_img *img, uint32_t x, uint32_t y, uint32_t src)
{
	uint32_t	*dst;
	uint64_t	argb_dst;
	uint64_t	argb_src;
	uint64_t	alpha;
	uint64_t	reg64;

	alpha = (src >> 24);
	dst = (uint32_t *) (img->data + y * img->width + x);
	argb_dst = (((uint64_t) *dst) & 0xFF00FF00ULL) << 32;
	argb_dst |= ((uint64_t) *dst) & 0x00FF00FFULL;
	argb_src = (((uint64_t) src) & 0xFF00FF00ULL) << 32;
	argb_src |= ((uint64_t) src) & 0x00FF00FFULL;
	reg64 = (argb_dst + (argb_src - argb_dst) * alpha) >> 8;
	reg64 &= 0x00FF00FF00FF00FFULL;
	reg64 = ((reg64 >> 32) | reg64) & 0xFFFFFFFFULL;
	*dst = (uint32_t) reg64;
}


// dp how many pixels changed
// void	motion_smoothing(uint8_t dp)
// {
// 	static	size_t	total = 0;

// 	total = total << dp + total >> 1;
// }

// void	motion_smoothing(float dxyz)
// {
// 	static float	total = 1;

// 	total *= (dxyz + 0.5);
// }
