/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_radius.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:46:54 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/07 18:57:10 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float					return_radius(t_objpoint *f)
{
	float				rad;
	char				*str;

	str = f->file[numb_of_line(f->start, f->end, "Radius", f->file)];
	if ((rad = return_float(ft_strchr(str, 58))) <= 0)
	{
		ft_putstrv1("Your radius size is not possible");
		return (-1);
	}
	return (rad);
}
