/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 10:34:59 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/25 00:19:18 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

static inline
float	fdf_lerp(const int32_t min, const int32_t max, const int32_t val)
{
	// return ((float)(((double)((min + val) << 1) / (double)(max + min)) - 1.0));
	return (((val - min) * 2.0f) / (max - min) - 1.0f);
}

static
void	fdf_create_vector(t_vars *vars)
{
	size_t		i;
	int32_t		y_index;
	int32_t		x_index;

	i = 0;
	y_index = 0;
	x_index = 0;
	while (i < vars->length)
	{
		x_index = (vars->fdf[i].index % vars->cols);
		y_index += (x_index == 0) && (i != 0);
		vars->vec[i].x = fdf_lerp(0, vars->cols, x_index);
		vars->vec[i].y = fdf_lerp(0, vars->rows, y_index);
		vars->vec[i].z = fdf_lerp(vars->min, vars->max, vars->fdf[i].height) * ZSCALE;
		i++;
	}
}

void	fdf_init(const char *str, const uint8_t byte, t_vars *vars)
{
	const uint8_t	*ustr = (const uint8_t *) str;
	size_t			i;

	vars->rows = 0;
	while (*ustr != 0)
	{
		vars->rows += (*ustr == byte);
		ustr++;
	}
	if (vars->rows == 0 || vars->length % vars->rows != 0)
		return ; // Error Handling
	vars->cols = vars->length / vars->rows;
	vars->min = INT32_MAX;
	vars->max = INT32_MIN;
	vars->zoom = 4.0f;
	i = 0;
	while (i < vars->length)
	{
		if (vars->fdf[i].height > vars->max)
			vars->max = vars->fdf[i].height;
		if (vars->fdf[i].height < vars->min)
			vars->min = vars->fdf[i].height;
		i++;
	}
	fdf_create_vector(vars);
}
