/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:17:43 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/21 18:20:21 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_mat4				ft_mat4_rotation_matrix(t_vec3 axis, double alpha)
{
	t_mat4			res;
	double			sin_t;
	double			cos_t;
	double			inv_cos_t;

	res = ft_mat4_identity_matrix();
	axis = ft_vec3_normalize(axis);
	sin_t = sin(alpha);
	cos_t = cos(alpha);
	inv_cos_t = 1 - cos_t;
	res.matrix[0][0] = cos_t + inv_cos_t * axis.x * axis.x;
	res.matrix[1][0] = inv_cos_t * axis.x * axis.y - sin_t * axis.z;
	res.matrix[2][0] = inv_cos_t * axis.x * axis.z + sin_t * axis.y;
	res.matrix[0][1] = inv_cos_t * axis.y * axis.x + sin_t * axis.z;
	res.matrix[1][1] = cos_t + inv_cos_t * axis.y * axis.y;
	res.matrix[2][1] = inv_cos_t * axis.y * axis.z - sin_t * axis.x;
	res.matrix[0][2] = inv_cos_t * axis.z * axis.x - sin_t * axis.y;
	res.matrix[1][2] = inv_cos_t * axis.z * axis.y + sin_t * axis.x;
	res.matrix[2][2] = cos_t + inv_cos_t * axis.z * axis.z;
	return (res);
}

void				ft_mat4_print(t_mat4 mat)
{
	int				j;
	int				k;

	j = 0;
	k = 0;
	while (j < 4)
	{
		k = 0;
		printf("|");
		while (k < 4)
		{
			printf("%f ", mat.matrix[j][k]);
			k++;
		}
		printf("|\n");
		j++;
	}
}
