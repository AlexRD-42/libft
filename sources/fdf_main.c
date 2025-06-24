/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:24:50 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/24 20:30:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"
#include "libft_math.h"

int	main(void)
{
	t_vars vars;

	fdf_read("resources/maps/elem2.fdf", " \n", &vars);
	vars.mlx = mlx_init();
	mlx_new_window(vars.mlx, WIDTH, HEIGHT, "Hello world!");
	vars.img = mlx_int_new_image(vars.mlx, WIDTH, HEIGHT, ZPixmap);
	mlx_hook(vars.mlx->win_list, KeyPress, KeyPressMask, cmlx_keydown, &vars);
	mlx_hook(vars.mlx->win_list, KeyRelease, KeyReleaseMask, cmlx_keyup, &vars);
	mlx_hook(vars.mlx->win_list, ButtonPress, ButtonPressMask, cmlx_mousedown, &vars);
	mlx_hook(vars.mlx->win_list, ButtonRelease, ButtonReleaseMask, cmlx_mouseup, &vars);
	mlx_hook(vars.mlx->win_list, Expose, ExposureMask, cmlx_expose, &vars);
	mlx_loop(vars.mlx);
	cmlx_destroy(&vars);
	return (0);
}
