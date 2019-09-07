/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:39:13 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/07 16:48:17 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					check_plane(t_objpoint *f)
{
	int				i;

	i = numb_of_line(f->start, f->end, "Plane_d", f->file);
	if (check_num_of_param(f->file[i], "Plane_d") != 0)
		return (-1);
	return (0);
}
