/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:26:48 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/25 19:27:29 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3			ft_vec3_create(float x, float y, float z)
{
	t_vec3		new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec3			ft_vec3_sum(t_vec3 a, t_vec3 b)
{
	t_vec3		new;

	new.x = (a.x + b.x);
	new.y = (a.y + b.y);
	new.z = (a.z + b.z);
	return (new);
}

t_vec3			ft_vec3_substract(t_vec3 a, t_vec3 b)
{
	t_vec3		new;

	new.x = (a.x - b.x);
	new.y = (a.y - b.y);
	new.z = (a.z - b.z);
	return (new);
}

void			ft_vec3_print(t_vec3 a)
{
	printf("x:%f y:%f z:%f w:%f\n", a.x, a.y, a.z, a.w);
}

float			ft_vec3_dot_multiply(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
