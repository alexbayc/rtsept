/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:57:44 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/11 19:56:16 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int							ret_rot2(int i, int j, t_objpoint *f)
{
	float						x;
	float						y;
	float						z;

	while (i <= j)
	{
		if (ft_strstr(f->file[i], "x") != NULL)
			x = return_xyz(f->file[i]);
		if (ft_strstr(f->file[i], "y") != NULL)
			y = return_xyz(f->file[i]);
		if (ft_strstr(f->file[i], "z") != NULL)
			z = return_xyz(f->file[i]);
		i++;
	}
	if (x == -123456789 || y == -123456789 || z == -123456789)
		return (-1);
	if ((x != 0 && y != 0) || (x != 0 && z != 0) || (y != 0 && z != 0))
	{
		ft_putstrv1("Some of your object rotation is bad");
		return (-1);
	}
	f->fig->v = create_cfloat3(x, y, z);
	return (0);
}

int							return_rotation(t_objpoint *f)
{
	int						i;
	int						j;

	i = numb_of_line(f->start, f->end, "Rotation", f->file);
	j = find_end_of_block(i, f);
	if (ret_rot2(i, j, f) == -1)
		return (-1);
	return (0);
}
