/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_others.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:51:33 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/20 13:15:06 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

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
