/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:22:15 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/04 19:19:32 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					check_blocks(t_objpoint *f)
{
	if (check_position(f) == -1)
		return (-1);
	if (check_color(f) == -1)
		return (-1);
	if (check_emission(f) == -1)
		return (-1);
	return (0);
}

int					check_rep_param(t_objpoint *f)
{
	if (repit(f->start, f->end, "Radius", f->file) != 1)
		return (-1);
	if (repit(f->start, f->end, "Position", f->file) != 1)
		return (-1);
	if (repit(f->start, f->end, "Color", f->file) != 1)
		return (-1);
	if (repit(f->start, f->end, "Emission", f->file) != 1)
		return (-1);
	if (repit(f->start, f->end, "Reflection", f->file) != 1)
		return (-1);
	return (0);
}

int					check_all_param(t_objpoint *f)
{
	if (numb_of_line(f->start, f->end, "Radius", f->file) == -1)
		return (-1);
	if (numb_of_line(f->start, f->end, "Position", f->file) == -1)
		return (-1);
	if (numb_of_line(f->start, f->end, "Color", f->file) == -1)
		return (-1);
	if (numb_of_line(f->start, f->end, "Emission", f->file) == -1)
		return (-1);
	if (numb_of_line(f->start, f->end, "Reflection", f->file) == -1)
		return (-1);
	return (0);
}

int					type_sphere(t_objpoint *f)
{
	if (check_all_param(f) == -1 || check_rep_param(f) == -1)
		return (-1);
	if (check_blocks(f) == -1)
		return (-1);
	return (0);
}
