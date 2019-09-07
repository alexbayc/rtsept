/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_radius.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:34:02 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/07 17:40:23 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					check_radius(t_objpoint *f)
{
	int				i;

	i = numb_of_line(f->start, f->end, "Radius", f->file);
	if (check_num_of_param(f->file[i], "Radius") != 0)
		return (-1);
	return (0);
}
