/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:46:31 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/25 12:33:15 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

static inline
t_mat4	build_pmatrix(t_params params)
{
	const t_vec3	vcos = {cosf(params.rx), cosf(params.ry), cosf(params.rz)};
	const t_vec3	vsin = {sinf(params.rx), sinf(params.ry), sinf(params.rz)};
	const t_mat4	matrix = {{
		{vcos.z * vcos.y, - vsin.z * vcos.y, vsin.y, params.dx},
		{vcos.z * vsin.y * vsin.x + vsin.z * vcos.x, - vsin.z * vsin.y * vsin.x
		+ vcos.z * vcos.x, - vcos.y * vsin.x, params.dy},
		{-vcos.z * vsin.y * vcos.x + vsin.z * vsin.x, vsin.z * vsin.y * vcos.x
		+ vcos.z * vsin.x, vcos.y * vcos.x, params.dz},
		{0, 0, 0, 1}}};

	return (matrix);
}

static inline
t_mat4	build_mvpmatrix(t_params p, t_frustrum f)
{
	const t_vec3	vc = {cosf(p.rx), cosf(p.ry), cosf(p.rz)};
	const t_vec3	vs = {sinf(p.rx), sinf(p.ry), sinf(p.rz)};
	const t_vec4	v1 = {1.0f / tanf(f.fov * 0.5f), -vc.z * vs.y * vc.x + vs.z
		* vs.x, vs.z * vs.y * vc.x + vc.z * vs.x, vc.y * vc.x};
	const t_vec4	v2 = {v1.x / f.ar, v1.x, (f.far + f.near)
		/ (f.near - f.far), 2.0f * f.far * f.near / (f.near - f.far)};

	return ((t_mat4){{
		{v2.x * vc.z * vc.y, v2.x * -vs.z * vc.y, v2.x * vs.y, v2.x * p.dx},
		{v2.y * (vc.z * vs.y * vs.x + vs.z * vc.x), v2.y * (-vs.z * vs.y * vs.x + vc.z * vc.x), v2.y * (-vc.y * vs.x), v2.y * p.dy},
		{v2.z * v1.y, v2.z * v1.z, v2.z * v1.w, v2.z * p.dz + v2.w},
		{-v1.y, -v1.z, -v1.w, -p.dz}}});
}

static inline
void	mat4_apply_vertex(const t_mat4 *m, t_vec4 *v, size_t length)
{
	size_t	i;
	t_vec4	r;
	float	invw;

	i = 0;
	while (i < length)
	{
		r.x = m->a1 * v[i].x + m->a2 * v[i].y + m->a3 * v[i].z + m->a4;
		r.y = m->b1 * v[i].x + m->b2 * v[i].y + m->b3 * v[i].z + m->b4;
		r.z = m->c1 * v[i].x + m->c2 * v[i].y + m->c3 * v[i].z + m->c4;
		r.w = m->d1 * v[i].x + m->d2 * v[i].y + m->d3 * v[i].z + m->d4;
		invw = 1.0f / (r.w + EPS);
		if (r.w > -EPS && r.w < EPS)
			write(1, "OHNO, ", 6);
		v[i].x = r.x * invw;
		v[i].y = r.y * invw;
		v[i].z = r.z * invw;
		i++;
	}
}

void	fdf_rotate(t_vars *vars, float rx, float ry, float rz)
{
	const t_params		params = {0.0f, 0.0f, 0.0f, rx, ry, rz};
	const t_mat4		proj = build_pmatrix(params);
	mat4_apply_vertex(&proj, vars->vec, vars->length);
	// ft_memset(vars->img->data, 0, HEIGHT * WIDTH * sizeof(int32_t));
	// draw_lines(vars);
	// mlx_put_image_to_window(vars->mlx, vars->mlx->win_list, vars->img, 0, 0);
}

void	fdf_translate(t_vars *vars, float dx, float dy, float dz)
{
	const t_params		params = {dx, dy, dz, 0.0f, 0.0f, 0.0f};
	const t_mat4		proj = build_pmatrix(params);
	mat4_apply_vertex(&proj, vars->vec, vars->length);
	// ft_memset(vars->img->data, 0, HEIGHT * WIDTH * sizeof(int32_t));
	// draw_lines(vars);
	// mlx_put_image_to_window(vars->mlx, vars->mlx->win_list, vars->img, 0, 0);
}

void	apply_iso(t_vars *vars)
{
	const t_params		params = {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f};
	// const t_frustrum	vport = {1.0f, 1000.0f, 1.6, AR};
	// const t_mat4		proj = build_mvpmatrix(params, vport);
	const t_mat4		proj = build_pmatrix(params);
	mat4_apply_vertex(&proj, vars->vec, vars->length);
	// mat4_apply_vertex(&proj, vars->vec, 0, vars->length);
	// ft_memset(vars->img->data, 0, HEIGHT * WIDTH * sizeof(int32_t));
	// draw_lines(vars);
	// mlx_put_image_to_window(vars->mlx, vars->mlx->win_list, vars->img, 0, 0);
}
