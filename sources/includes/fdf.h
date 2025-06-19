/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:58:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/19 15:56:03 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stddef.h>
# include "mlx.h"
# include "mlx_int.h"

#define WIDTH 640
#define HEIGHT 480

typedef struct s_fdf_array
{
	int32_t		*ptr;
	size_t		length;
	int32_t		max;
	int32_t		min;
	uint32_t	rows;
	uint32_t	cols;
}	t_fdf_array;

typedef struct s_vec3
{
	int32_t	x;
	int32_t	y;
	int32_t	z;
	int32_t	rgb;
}	t_vec3;

typedef struct s_vec4
{
	float	x;	// Abscissa
	float	y;	// Ordinate
	float	z;	// Altitude
	float	w;	// Normalization Vector
}	t_vec4;

void	*mlx_int_new_image(t_xvar *xvar, int width, int height, int format);
void	fdf_read(const char *str, const char *charset, t_fdf_array *array);
uint32_t ft_lerp(int32_t max, int32_t min, int32_t value);
void	cmlx_putpixel(t_img *img, uint32_t x, uint32_t y, uint32_t argb);
void	cmlx_destroy(t_xvar *mlx, t_img *img, t_fdf_array *array);
void	draw_image(t_img *img, t_fdf_array *array);

#endif