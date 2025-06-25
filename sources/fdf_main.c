/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:24:50 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/25 12:17:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"
#include "libft_math.h"

// Remember to free and close fds
// Maybe an Enum would be better
// static const char *error[] = {
// 	"Error: Number of columns differ",
// 	"Error: Failed to allocate memory",
// 	"Error: Read values do not match",};

void	fdf_error(t_vars *vars, uint8_t error_code, int32_t fd)
{
	
}

int		cmlx_loop(t_vars *vars)
{
	ft_memset(vars->img->data, 0, HEIGHT * WIDTH * sizeof(int32_t));
	draw_lines(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx->win_list, vars->img, 0, 0);
}

void	init_vars(t_vars *vars)
{
	vars->mlx = NULL;
	vars->vtx = NULL;
	fdf_read("resources/maps/elem2.fdf", " \n", vars);
	fdf_create_vector(vars);
	vars->mlx = mlx_init();
	mlx_new_window(vars->mlx, WIDTH, HEIGHT, "Hello world!");
	vars->img = mlx_int_new_image(vars->mlx, WIDTH, HEIGHT, ZPixmap);
}

int		main(void)
{
	t_vars vars;

	init_vars(&vars);
	mlx_hook(vars.mlx->win_list, KeyPress, KeyPressMask, cmlx_keydown, &vars);
	mlx_hook(vars.mlx->win_list, KeyRelease, KeyReleaseMask, cmlx_keyup, &vars);
	mlx_hook(vars.mlx->win_list, ButtonPress, ButtonPressMask, cmlx_mousedown, &vars);
	mlx_hook(vars.mlx->win_list, ButtonRelease, ButtonReleaseMask, cmlx_mouseup, &vars);
	mlx_hook(vars.mlx->win_list, Expose, ExposureMask, cmlx_expose, &vars);
	mlx_loop_hook(vars.mlx, cmlx_loop, &vars);
	mlx_loop(vars.mlx);
	cmlx_destroy(&vars);
	return (0);
}
