/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 16:20:29 by jblack-b          #+#    #+#             */
/*   Updated: 2019/09/21 18:23:03 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mat4				ft_mat4_identity_matrix(void)
{
	t_mat4			res;
	int				i;
	int				j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			res.matrix[i][j] = 0;
	}
	res.matrix[0][0] = 1;
	res.matrix[1][1] = 1;
	res.matrix[2][2] = 1;
	res.matrix[3][3] = 1;
	return (res);
}

t_vec3				ft_mat3_multiply_vec3(t_mat3 matrix, t_vec3 vector)
{
	t_vec3			new;

	new.x = matrix.matrix[0][0] * vector.x + matrix.matrix[0][1] *
			vector.y + matrix.matrix[0][2] * vector.z;
	new.y = matrix.matrix[1][0] * vector.x + matrix.matrix[1][1] *
			vector.y + matrix.matrix[1][2] * vector.z;
	new.z = matrix.matrix[2][0] * vector.x + matrix.matrix[2][1] *
			vector.y + matrix.matrix[2][2] * vector.z;
	return (new);
}

t_point3			ft_mat3_multiply_point3(t_mat3 matrix, t_point3 point)
{
	t_point3		new;

	new.x = matrix.matrix[0][0] * point.x + matrix.matrix[0][1] *
			point.y + matrix.matrix[0][2] * point.z;
	new.y = matrix.matrix[1][0] * point.x + matrix.matrix[1][1] *
			point.y + matrix.matrix[1][2] * point.z;
	new.z = matrix.matrix[2][0] * point.x + matrix.matrix[2][1] *
			point.y + matrix.matrix[2][2] * point.z;
	return (new);
}

t_mat4				ft_mat4_multiply_mat4(t_mat4 a, t_mat4 b)
{
	t_mat4			res;
	int				i;
	int				j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			res.matrix[i][j] = a.matrix[i][0] * b.matrix[0][j] +
				a.matrix[i][1] * b.matrix[1][j] +
				a.matrix[i][2] * b.matrix[2][j] +
				a.matrix[i][3] * b.matrix[3][j];
		}
	}
	return (res);
}
