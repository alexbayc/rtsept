/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:02:14 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/09 19:36:29 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int							ret_pos2(int i, int j, t_objpoint *f)
{
	float						x;
	float						y;
	float						z;

	while (i <= j)
	{
		if (ft_strstr(f->file[i], "distance x") != NULL)
			x = return_xyz(f->file[i]);
		if (ft_strstr(f->file[i], "distance y") != NULL)
			y = return_xyz(f->file[i]);
		if (ft_strstr(f->file[i], "distance z") != NULL)
			z = return_xyz(f->file[i]);
		i++;
	}
	if (x == -123456789 || y == -123456789 || z == -123456789)
		return (-1);
	f->fig->position = create_cfloat3(x, y, z);
	return (0);
}

int							return_position(t_objpoint *f)
{
	int						i;
	int						j;

	i = numb_of_line(f->start, f->end, "Position", f->file);
	j = find_end_of_block(i, f);
	if (ret_pos2(i, j, f) == -1)
		return (-1);
	return (0);
}
