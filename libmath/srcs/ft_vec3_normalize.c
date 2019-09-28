/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_normalize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:32:37 by jblack-b          #+#    #+#             */
/*   Updated: 2019/09/28 15:13:36 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vec3				ft_vec3_normalize(t_vec3 vect)
{
	float			norm;

	norm = ft_vec3_norm(vect);
	vect.x = vect.x / norm;
	vect.y = vect.y / norm;
	vect.z = vect.z / norm;
	return (vect);
}
