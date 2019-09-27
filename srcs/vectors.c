/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 20:23:19 by jblack-b          #+#    #+#             */
/*   Updated: 2019/09/25 19:29:34 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3			ft_vec3_neg(t_vec3 v)
{
	return (ft_vec3_scalar_multiply(v, -1));
}

double			ft_vec3_angle(t_vec3 a, t_vec3 b)
{
	t_vec3		v1;
	t_vec3		v2;

	v1 = ft_vec3_normalize(a);
	v2 = ft_vec3_normalize(b);
	return (acos(ft_vec3_dot_multiply(v1, v2)));
}

double			ft_vec3_length(t_vec3 v1)
{
	return (sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z));
}

t_vec3			ft_vec3_sum_poin3(t_vec3 a, t_point3 b)
{
	t_vec3		new;

	new.x = (a.x + b.x);
	new.y = (a.y + b.y);
	new.z = (a.z + b.z);
	return (new);
}

t_vec3			ft_vec3_multiply_matrix(t_vec3 v, t_mat4 m)
{
	t_vec3		res;

	res.x = v.x * m.matrix[0][0] +
			v.y * m.matrix[0][1] +
			v.z * m.matrix[0][2] +
			v.w * m.matrix[0][3];
	res.y = v.x * m.matrix[1][0] +
			v.y * m.matrix[1][1] +
			v.z * m.matrix[1][2] +
			v.w * m.matrix[1][3];
	res.z = v.x * m.matrix[2][0] +
			v.y * m.matrix[2][1] +
			v.z * m.matrix[2][2] +
			v.w * m.matrix[2][3];
	res.w = v.x * m.matrix[3][0] +
			v.y * m.matrix[3][1] +
			v.z * m.matrix[3][2] +
			v.w * m.matrix[3][3];
	return (res);
}
