/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_cyl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:23:39 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/07 17:43:25 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					check_blocksc(t_objpoint *f)
{
	if (check_position(f) == -1)
		return (-1);
	if (check_color(f) == -1)
		return (-1);
	if (check_emission(f) == -1)
		return (-1);
	if (check_reflection(f) == -1)
		return (-1);
	if (check_rotation(f) == -1)
		return (-1);
	if (check_radius(f) == -1)
		return (-1);
	return (0);
}

int					check_rep_paramc(t_objpoint *f)
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
	if (repit(f->start, f->end, "Rotation", f->file) != 1)
		return (-1);
	return (0);
}

int					check_all_paramc(t_objpoint *f)
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
	if (numb_of_line(f->start, f->end, "Rotation", f->file) == -1)
		return (-1);
	return (0);
}

int					type_cyl(t_objpoint *f)
{
	if (check_all_paramc(f) == -1 || check_rep_paramc(f) == -1)
		return (-1);
	if (check_blocksc(f) == -1)
		return (-1);
	return (0);
}
