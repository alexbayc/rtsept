/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pulling_out.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:36:56 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/11 19:32:33 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					pulling_out(t_objpoint *f, int type)
{
	int				i;

	i = 0;
	if (type == 1)
		i = pulling_sphere(f);
	if (type == 2)
		i = pulling_cyl(f);
	if (type == 3)
		i = pulling_plane(f);
	if (type == 4)
		i = pulling_con(f);
	return (i);
}
