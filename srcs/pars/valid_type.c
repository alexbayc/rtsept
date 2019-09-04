/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:15:01 by odale-dr          #+#    #+#             */
/*   Updated: 2019/08/31 19:43:39 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					valid_type(t_objpoint *f, int type)
{
	int				i;

	i = 0;
	if (type == 1)
		i = type_sphere(f);
	if (type == 2)
		i = type_cyl(f);
	if (type == 3)
		i = type_plane(f);
	if (type == 4)
		i = type_cone(f);
	return (i);
}
