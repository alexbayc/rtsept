/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:59:14 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/24 20:00:27 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_quaternion		ft_quaternion_covert_to_unit_norm(t_quaternion q)
{
	t_quaternion	new;
	float			angle;

	angle = ft_degree_to_rad(q.s);
	new.v = ft_vec3_normalize(q.v);
	new.s = cosf(angle * 0.5);
	new.v = ft_vec3_scalar_multiply(q.v, sinf(angle * 0.5));
	return (new);
}

t_quaternion		ft_quaternion_conjugate(t_quaternion q)
{
	float			scalar;
	t_vec3			imaginary;

	scalar = q.s;
	imaginary = ft_vec3_scalar_multiply(q.v, -1);
	return ((t_quaternion){scalar, imaginary});
}

t_quaternion		ft_quaternion_inverse(t_quaternion q)
{
	float			abs;
	t_quaternion	conjugare_val;
	float			scalar;
	t_vec3			imaginary;

	abs = ft_quaternion_norm(q);
	abs *= abs;
	abs = 1 / abs;
	conjugare_val = ft_quaternion_conjugate(q);
	scalar = conjugare_val.s * abs;
	imaginary = ft_vec3_scalar_multiply(conjugare_val.v, abs);
	return ((t_quaternion){scalar, imaginary});
}
