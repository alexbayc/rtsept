/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:21:59 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/21 18:23:00 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mat4				ft_mat4_scalar_multiply(t_mat4 m, double n)
{
	int				i;
	int				j;

	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4)
			m.matrix[i][j] *= n;
	return (m);
}

t_mat4				ft_mat4_sum_mat4(t_mat4 a, t_mat4 b)
{
	int				i;
	int				j;

	i = -1;
	while (++i < 4 && (j = -1))
		while (++j < 4)
			a.matrix[i][j] += b.matrix[i][j];
	return (a);
}

t_mat4				ft_mat4_translation_matrix(t_vec3 v)
{
	t_mat4			res;

	res = ft_mat4_identity_matrix();
	res.matrix[0][3] = v.x;
	res.matrix[1][3] = v.y;
	res.matrix[2][3] = v.z;
	return (res);
}

t_mat4				ft_mat4_scale_matrix(double a, double b, double c)
{
	t_mat4			res;

	res = ft_mat4_identity_matrix();
	res.matrix[0][0] = a;
	res.matrix[1][1] = b;
	res.matrix[2][2] = c;
	return (res);
}

t_mat4				ft_mat4_transpose(t_mat4 mat)
{
	t_mat4			new;
	int				j;
	int				k;

	j = 0;
	k = 0;
	while (j < 4)
	{
		k = 0;
		while (k < 4)
		{
			new.matrix[k][j] = mat.matrix[j][k];
			k++;
		}
		j++;
	}
	return (new);
}
