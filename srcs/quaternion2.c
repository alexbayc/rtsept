/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 19:29:05 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/24 19:44:25 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_quaternion			t_quaternion_sum(t_quaternion a, t_quaternion b)
{
	t_quaternion		new;

	new.s = a.s + b.s;
	new.v = ft_vec3_sum(a.v, b.v);
	return (new);
}

t_quaternion			t_quaternion_substract(t_quaternion a, t_quaternion b)
{
	t_quaternion		new;

	new.s = a.s - b.s;
	new.v = ft_vec3_substract(a.v, b.v);
	return (new);
}

float					ft_quaternion_norm(t_quaternion q)
{
	float				scalar;
	float				imaginary;

	scalar = q.s * q.s;
	imaginary = ft_vec3_dot_multiply(q.v, q.v);
	return (sqrt(scalar + imaginary));
}

float					ft_degree_to_rad(float degree)
{
	return (degree * M_PI / 180);
}

t_quaternion			ft_quaternion_normalize(t_quaternion q)
{
	t_quaternion		new;
	float				norm;
	float				norm_value;

	norm = ft_quaternion_norm(q);
	if (norm != 0)
	{
		norm_value = 1 / norm;
		new.s = q.s * norm_value;
		new.v = ft_vec3_scalar_multiply(q.v, norm_value);
	}
	return (new);
}
