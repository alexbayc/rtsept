/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulling_con.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:51:00 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/11 19:51:31 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					pulling_con(t_objpoint *f)
{
	float			rad;
	char			*str;

	if ((f->fig = malloc(sizeof(t_obj))) == NULL)
		return (-1);
	f->fig->type = CONE;
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
	if (return_rotation(f) == -1)
		return (-1);
	f->fig->plane_d = 0;
	return (0);
}
