/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmlx_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:34:26 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/23 14:37:17 by adeimlin         ###   ########.fr       */
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
	vars->evstatus.alt_pressed = (keycode == XK_Alt_L);
	apply_iso(vars);
}

// 3 KeyPress
int cmlx_keyup(int keycode, t_vars *vars)
{
	vars->evstatus.alt_pressed = (keycode == XK_Alt_L);
}

// 4 ButtonPress
int cmlx_mousedown(int button, int x, int y, t_vars *vars)
{
	static size_t a = 0;
	ft_putnbr(a % 10, 1, ',');
	a++;
}

// 5 ButtonRelease
int cmlx_mouseup(int button, int x, int y, t_vars *vars)
{
	
}

// 12 Expose (why does it run twice)
int cmlx_expose(t_vars *vars)
{
	static uint8_t	index = 0;

	if (index == 0)
		apply_iso(vars);
	index = !index;
}
