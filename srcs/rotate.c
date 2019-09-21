/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:02:42 by jblack-b          #+#    #+#             */
/*   Updated: 2019/09/21 19:01:20 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3				ft_vec3_project_test1(t_vec3 p)
{
	t_vec3		new;

	p.z += 300;
	new.x = (p.x * 500) / p.z + 320;
	new.y = (p.y * 500) / p.z + 240;
	return (new);
}

t_vec3				help_rotate(float mat[3][3], t_vec3 p)
{
	t_vec3			new;

	new.x = p.x * mat[0][0] + p.y * mat[1][0] + p.z * mat[2][0];
	new.y = p.x * mat[0][1] + p.y * mat[1][1] + p.z * mat[2][1];
	new.z = p.x * mat[0][2] + p.y * mat[1][2] + p.z * mat[2][2];
	return (new);
}

t_vec3				ft_vec3_rotate_test1(t_vec3 p, t_vec3 angle)
{
	float			mat[3][3];
	t_vec3			new;
	t_superfloat	x;

	x.xdeg = angle.x * M_PI / 180;
	x.ydeg = angle.y * M_PI / 180;
	x.zdeg = angle.z * M_PI / 180;
	x.sx = (float)sin(x.xdeg);
	x.sy = (float)sin(x.ydeg);
	x.sz = (float)sin(x.zdeg);
	x.cx = (float)cos(x.xdeg);
	x.cy = (float)cos(x.ydeg);
	x.cz = (float)cos(x.zdeg);
	mat[0][0] = x.cx * x.cz + x.sx * x.sy * x.sz;
	mat[1][0] = -x.cx * x.sz + x.cz * x.sx * x.sy;
	mat[2][0] = x.cy * x.sx;
	mat[0][1] = x.cy * x.sz;
	mat[1][1] = x.cy * x.cz;
	mat[2][1] = -x.sy;
	mat[0][2] = -x.cz * x.sx + x.cx * x.sy * x.sz;
	mat[1][2] = x.sx * x.sz + x.cx * x.cz * x.sy;
	mat[2][2] = x.cx * x.cy;
	new = help_rotate(mat, p);
	return (new);
}

t_vec3				ft_vec3_project_test2(t_vec3 p)
{
	p.x *= 1;
	p.y *= 1;
	p.x += 300;
	p.y += 300;
	return (p);
}

t_vec3				ft_vec3_rotate_test2(t_vec3 p, t_vec3 angle)
{
	t_vec3			v;
	double			x;
	double			y;
	double			z;

	x = p.x;
	z = p.z;
	v.x = cos(angle.y) * x + sin(angle.y) * z;
	v.z = -sin(angle.y) * x + cos(angle.y) * z;
	y = p.y;
	z = v.z;
	v.y = cos(angle.x) * y - sin(angle.x) * z;
	v.z = sin(angle.x) * y + cos(angle.x) * z + 300;
	x = v.x;
	y = v.y;
	v.x = cos(angle.z) * x - sin(angle.z) * y;
	v.y = sin(angle.z) * x + cos(angle.z) * y;
	return (v);
}
