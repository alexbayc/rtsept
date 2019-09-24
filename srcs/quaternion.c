/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:26:22 by jblack-b          #+#    #+#             */
/*   Updated: 2019/09/24 20:00:24 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_quaternion		ft_quaternion_multiply(t_quaternion a, t_quaternion b)
{
	float			scalar;
	t_vec3			imaginary;

	scalar = a.s * b.s - ft_vec3_dot_multiply(a.v, b.v);
	imaginary = ft_vec3_sum(ft_vec3_sum(ft_vec3_scalar_multiply(b.v, a.s),
				ft_vec3_scalar_multiply(a.v, b.s)),
				ft_vec3_cross_multiply(a.v, b.v));
	return ((t_quaternion){scalar, imaginary});
}

t_quaternion		ft_quaternion_multiply2(t_quaternion a, t_quaternion b)
{
	t_quaternion new;

	new.s = (a.s * b.s - a.v.x * b.v.x - a.v.y * b.v.y - a.v.z * b.v.z);
	new.v.x = (a.s * b.v.x + a.v.x * b.s + a.v.y * b.v.z - a.v.z * b.v.y);
	new.v.y = (a.s * b.v.y - a.v.x * b.v.z + a.v.y * b.s + a.v.z * b.v.x);
	new.v.z = (a.s * b.v.z + a.v.x * b.v.y - a.v.y * b.v.x + a.v.z * b.s);
	return (new);
}

t_quaternion		ft_quaternion_local_rotation(t_vec3 axis, float angle)
{
	t_quaternion local_rotation;

	angle = angle * M_PI / 180.0;
	local_rotation.s = cosf(angle / 2);
	local_rotation.v.x = axis.x * sinf(angle / 2);
	local_rotation.v.y = axis.y * sinf(angle / 2);
	local_rotation.v.z = axis.z * sinf(angle / 2);
	return (local_rotation);
}

t_vec3				ft_vec3_rotate_quaterion(float a, t_vec3 vec, t_vec3 axis)
{
	t_quaternion	p;
	t_quaternion	q;
	t_quaternion	q_invesrse;
	t_quaternion	rotated;

	p = (t_quaternion){0, vec};
	q = (t_quaternion){a, ft_vec3_normalize(axis)};
	q = ft_quaternion_covert_to_unit_norm(q);
	q_invesrse = ft_quaternion_inverse(q);
	rotated = ft_quaternion_multiply2(ft_quaternion_multiply(q, p), q_invesrse);
	return (rotated.v);
}

t_vec3				ft_vec3_rotate_quaterion2(float a, t_vec3 vec, t_vec3 axis)
{
	t_vec3			new;
	t_quaternion	local_rotation;
	t_quaternion	total;

	local_rotation = ft_quaternion_local_rotation(axis, a);
	total = (t_quaternion){1, {0, 0, 0}};
	total = ft_quaternion_multiply2(local_rotation, total);
	new.x = (1 - 2 * pow(total.v.y, 2) - 2.0 * pow(total.v.z, 2)) * vec.x
	+ (2 * total.v.x * total.v.y - 2 * total.s * total.v.z) * vec.y
	+ (2 * total.v.x * total.v.z + 2 * total.s * total.v.y) * vec.z;
	new.y = (2 * total.v.x * total.v.y + 2 * total.s * total.v.z) * vec.x
	+ (1 - 2 * pow(total.v.x, 2) - 2 * pow(total.v.z, 2)) * vec.y
	+ (2 * total.v.y * total.v.z - 2 * total.s * total.v.x) * vec.z;
	new.z = (2 * total.v.x * total.v.z - 2 * total.s * total.v.y) * vec.x
	+ (2 * total.v.y * total.v.z + 2 * total.s * total.v.x) * vec.y
	+ (1 - 2 * pow(total.v.x, 2) - 2 * pow(total.v.y, 2)) * vec.z;
	return (new);
}
