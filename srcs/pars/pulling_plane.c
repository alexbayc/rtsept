/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulling_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:49:56 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/11 19:46:04 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rtv1.h"

int					pulling_plane(t_objpoint *f)
{
	float			rad;
	char			*str;

	if ((f->fig = malloc(sizeof(t_obj))) == NULL)
		return (-1);
	f->fig->type = PLANE;
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
	if ((f->fig->plane_d = return_plane_d(f)) == -1)
		return (-1);
	f->fig->v = create_cfloat3(0.0f, 0.0f, 0.0f);
	return (0);
}
