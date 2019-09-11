/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_plane_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 19:37:02 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/11 19:44:26 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float					return_plane_d(t_objpoint *f)
{
	float				rad;
	char				*str;

	str = f->file[numb_of_line(f->start, f->end, "Plane_d", f->file)];
	if ((rad = return_float(ft_strchr(str, 58))) <= 0)
	{
		ft_putstrv1("Your Plane_d size is not possible");
		return (-1);
	}
	if (rad >= 100)
	{
		ft_putstrv1("Your Plane_d size is too big (more than 100)");
		return (-1);
	}
	printf("\n -> %f <- \n", rad);
	return (rad);
}
