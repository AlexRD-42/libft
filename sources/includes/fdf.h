/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:58:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/22 10:51:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <stddef.h>
# include "mlx.h"
# include "mlx_int.h"
# include "fdf_structs.h"

# define WIDTH 1920
# define HEIGHT 1080
# define SCALE 16
# define ZSCALE 1
# ifndef EPS
#  define EPS 0.00000011920929f
# endif

void	*mlx_int_new_image(t_xvar *xvar, int width, int height, int format);
void	fdf_read(const char *str, const char *charset, t_vars *vars);
void	fdf_init(const char *str, const uint8_t byte, t_vars *vars);
void	mat_chain(t_vars *vars);
void	draw_lines(t_vars *vars);

void	cmlx_putrgb(t_img *img, uint32_t x, uint32_t y, uint32_t argb);
void	cmlx_destroy(t_vars *vars);

int 	cmlx_keydown(int keycode, t_vars *vars);
int 	cmlx_keyup(int keycode, t_vars *vars);
int 	cmlx_mousedown(int button, int x, int y, t_vars *vars);
int 	cmlx_mouseup(int button, int x, int y, t_vars *vars);
int 	cmlx_expose(t_vars *vars);
void	apply_iso(t_vars *vars);

#endif