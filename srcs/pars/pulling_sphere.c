/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulling_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:30:36 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/11 19:27:21 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					pulling_sphere(t_objpoint *f)
{
	float			rad;
	char			*str;

	if ((f->fig = malloc(sizeof(t_obj))) == NULL)
		return (-1);
	f->fig->type = SPHERE;
	if ((f->fig->radius = return_radius(f)) == -1)
		return (-1);
	if ((f->fig->reflection = return_reflection(f)) == -1)
		return (-1);
	if (return_position(f) == -1)
		return (-1);
	if (return_color(f) == -1)
		return (-1);
	if (return_emission(f) == -1)
		return (-1);
	f->fig->plane_d = 0;
	f->fig->v = create_cfloat3(0.0f, 0.0f, 0.0f);
	return (0);
}
