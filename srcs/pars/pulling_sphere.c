/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulling_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:30:36 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/07 18:59:02 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					pulling_sphere(t_objpoint *f)
{
	float			rad;
	char			*str;

	ft_putendl("+++++++++++++++");
	if ((rad = return_radius(f)) == -1)
		return (-1);
	ft_putendl("+++++++++++++++");
	f->fig = malloc(sizeof(t_obj));
	f->fig->type = SPHERE;
	return (0);
}
