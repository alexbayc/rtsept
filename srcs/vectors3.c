/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:28:33 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/25 19:29:39 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3			ft_vec3_scalar_multiply(t_vec3 a, float b)
{
	return ((t_vec3){a.x * b, a.y * b, a.z * b});
}

t_vec3			ft_vec3_cross_multiply(t_vec3 a, t_vec3 b)
{
	t_vec3		result;

	result.x = a.y * b.z - a.z * b.y;
	result.y = a.z * b.x - a.x * b.z;
	result.z = a.x * b.y - a.y * b.x;
	return (result);
}

float			ft_vec3_norm(t_vec3 vect)
{
	return (sqrt(vect.x * vect.x + vect.y * vect.y + vect.z * vect.z));
}

t_vec3			ft_vec3_normalize(t_vec3 vect)
{
	float		norm;

	norm = ft_vec3_norm(vect);
	vect.x = vect.x / norm;
	vect.y = vect.y / norm;
	vect.z = vect.z / norm;
	return (vect);
}

float			ft_vec3_projection(t_vec3 a, t_vec3 b)
{
	return (ft_vec3_dot_multiply(b, a) / ft_vec3_norm(b));
}
