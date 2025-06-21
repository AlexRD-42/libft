/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:46:31 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/21 12:51:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "fdf.h"

static
t_mat4	build_matrix(t_params params)
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

// wtf is this abomination jesusss
// static
// t_mat4	build_matrix(t_params p, t_frustrum f)
// {
// 	const t_vec3	vc = {cosf(p.rx), cosf(p.ry), cosf(p.rz)};
// 	const t_vec3	vs = {sinf(p.rx), sinf(p.ry), sinf(p.rz)};
// 	const t_vec4	v1 = {1.0f / tanf(f.fov * 0.5f), -vc.z * vs.y * vc.x + vs.z
// 		* vs.x, vs.z * vs.y * vc.x + vc.z * vs.x, vc.y * vc.x};
// 	const t_vec4	v2 = {v1.x / f.ar, v1.x, (f.far + f.near)
// 		/ (f.near - f.far), 2.0f * f.far * f.near / (f.near - f.far)};

// 	return ((t_mat4){{
// 		{v2.x * vc.z * vc.y, v2.x * -vs.z * vc.y, v2.x * vs.y, v2.x * p.dx},
// 		{v2.y * (vc.z * vs.y * vs.x + vs.z * vc.x), v2.y * (-vs.z * vs.y * vs.x + vc.z * vc.x), v2.y * (-vc.y * vs.x), v2.y * p.dy},
// 		{v2.z * v1.y, v2.z * v1.z, v2.z * v1.w, v2.z * p.dz + v2.w},
// 		{-v1.y, -v1.z, -v1.w, -p.dz}}});
// }

// Maybe updating z isn't necessary
static inline
void	mat4_apply_vertex(const t_mat4 *m, t_vtx *v, size_t i, size_t length)
{
	float	rx;
	float	ry;
	float	rz;
	float	rw;
	float	invw;

	while (i < length)
	{
		rx = m->row[0].x * ((float) v[i].x) + m->row[0].y * ((float) v[i].y)
			+ m->row[0].z * ((float) v[i].z) + m->row[0].w;
		ry = m->row[1].x * ((float) v[i].x) + m->row[1].y * ((float) v[i].y)
			+ m->row[1].z * ((float) v[i].z) + m->row[1].w;
		rz = m->row[2].x * ((float) v[i].x) + m->row[2].y * ((float) v[i].y)
			+ m->row[2].z * ((float) v[i].z) + m->row[2].w;
		rw = m->row[3].x * ((float) v[i].x) + m->row[3].y * ((float) v[i].y)
			+ m->row[3].z * ((float) v[i].z) + m->row[3].w;
		invw = 1.0f / (rw + (float) (rw > -EPS && rw < EPS));
		v[i].x = ((int32_t)(rx * invw)) + WIDTH / 2;
		v[i].y = ((int32_t)(ry * invw)) + HEIGHT / 2;
		v[i].z = ((int32_t)(rz * invw));
		i++;
	}
}

void	mat_chain(t_vars *vars)
{
	float			cx = (vars->cols - 1) * 0.5f * SCALE;
	float			cy = (vars->rows - 1) * 0.5f * SCALE;
	const t_params	params = {-cx, -cy, 0.0f,  0.5f, 0.0f, 0.0f};
	const t_mat4	proj = build_matrix(params);

	mat4_apply_vertex(&proj, vars->ptr, 0, vars->length);
	draw_lines(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx->win_list, vars->img, 0, 0);
}

void	apply_iso(t_vars *vars)
{
	const t_mat4 iso = {.row = {
		{ 0.0000f,  0.7071f, -0.7071f, 0.0f},
		{ 0.0000f,  0.7071f,  0.7071f, 0.0f},
		{ 1.0000f,  0.0000f,  0.0000f, 0.0f},
		{ 0.0000f,  0.0000f,  0.0000f, 1.0f}
	}};
	mat4_apply_vertex(&iso, vars->ptr, 0, vars->length);
	draw_lines(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx->win_list, vars->img, 0, 0);
}
