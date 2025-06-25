/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmlx_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:34:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/25 12:36:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"
#include "libft_math.h"

// Probably a good idea to update in fixed cycles, or at least accumulate
// some time between frames rather than updating every mouse movement

// 2 KeyRelease
int cmlx_keydown(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
		return (mlx_loop_end(vars->mlx));
	if (keycode == XK_w)
		fdf_rotate(vars, -PI/16, 0, 0);
	if (keycode == XK_s)
		fdf_rotate(vars, PI/16, 0, 0);
	if (keycode == XK_a)
		fdf_rotate(vars, 0, -PI/16, 0);
	if (keycode == XK_d)
		fdf_rotate(vars, 0, PI/16, 0);
	if (keycode == XK_q)
		fdf_rotate(vars, 0, 0, -PI/16);
	if (keycode == XK_e)
		fdf_rotate(vars, 0, 0, PI/16);
	if (keycode == XK_Up)
		fdf_translate(vars, 0, -0.2f, 0);
	if (keycode == XK_Down)
		fdf_translate(vars, 0, 0.2f, 0);
	if (keycode == XK_Left)
		fdf_translate(vars, -0.2f, 0, 0);
	if (keycode == XK_Right)
		fdf_translate(vars, 0.2f, 0, 0);
	// if (keycode == XK_q)
	// 	fdf_translate(vars, 0, 0, -0.1f);
	// if (keycode == XK_e)
	// 	fdf_translate(vars, 0, 0, +0.1f);
}

// 3 KeyPress
int cmlx_keyup(int keycode, t_vars *vars)
{

}

// 4 ButtonPress
// 12345 = LMB MMB RMB WHEELUP WHEELDOWN
int cmlx_mousedown(int button, int32_t ix, int32_t iy, t_vars *vars)
{
	static float	x = 0.0f;
	static float	y = 0.0f;
	const float		dx = x - (float) ix / WIDTH;
	const float		dy = y - (float) iy / HEIGHT;

	if (button == 1)
	{
		fdf_translate(vars, dx, dy, 0.0f);
	}
	else if (button == 4)
	{
		vars->zoom += 0.1f;
		fdf_rotate(vars, 0, 0, 0);
	}
	else if (button == 5)
	{
		vars->zoom -= ft_max(0.0f, 0.1f);
		fdf_rotate(vars, 0, 0, 0);
	}
}

// 5 ButtonRelease
int cmlx_mouseup(int button, int x, int y, t_vars *vars)
{
	
}

// 12 Expose (why does it run twice)
int cmlx_expose(t_vars *vars)
{
	// static uint8_t	index = 0;

	// if (index == 0)
	// 	apply_iso(vars);
	// index = !index;
}
