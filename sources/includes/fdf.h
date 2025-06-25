/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:58:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/25 10:58:58 by adeimlin         ###   ########.fr       */
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
# define AR (float) WIDTH / (float) HEIGHT
# define SCALE 16
# define ZSCALE 0.3f
# define DEFAULT_ZOOM 4.0f
# ifndef EPS
#  define EPS 0.00000011920929f
# endif
# define PI 3.141592653589793238462643383279502884L

void	*mlx_int_new_image(t_xvar *xvar, int width, int height, int format);
void	fdf_read(const char *str, const char *charset, t_vars *vars);
void	fdf_create_vector(t_vars *vars);
void	draw_lines(t_vars *vars);

void	cmlx_putrgb(t_img *img, uint32_t x, uint32_t y, uint32_t argb);
void	cmlx_destroy(t_vars *vars);
void	fdf_error(t_vars *vars, uint8_t error_code, int32_t fd);

int 	cmlx_keydown(int keycode, t_vars *vars);
int 	cmlx_keyup(int keycode, t_vars *vars);
int 	cmlx_mousedown(int button, int x, int y, t_vars *vars);
int 	cmlx_mouseup(int button, int x, int y, t_vars *vars);
int 	cmlx_expose(t_vars *vars);

void	apply_iso(t_vars *vars);
int		cmlx_loop(t_vars *vars);
void	fdf_rotate(t_vars *vars, float rx, float ry, float rz);
void	fdf_translate(t_vars *vars, float dx, float dy, float dz);
#endif