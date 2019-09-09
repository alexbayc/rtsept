/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:43:32 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/09 19:55:34 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int							ret_col2(int i, int j, t_objpoint *f)
{
	float						x;
	float						y;
	float						z;

	while (i <= j)
	{
		if (ft_strstr(f->file[i], "red") != NULL)
			x = return_clr(f->file[i]);
		if (ft_strstr(f->file[i], "green") != NULL)
			y = return_clr(f->file[i]);
		if (ft_strstr(f->file[i], "blue") != NULL)
			z = return_clr(f->file[i]);
		i++;
	}
	if (x < 0 || y < 0 || z < 0)
		return (-1);
	f->fig->color = create_cfloat3(x, y, z);
	return (0);
}

int							return_color(t_objpoint *f)
{
	int						i;
	int						j;

	i = numb_of_line(f->start, f->end, "Color", f->file);
	j = find_end_of_block(i, f);
	if (ret_col2(i, j, f) == -1)
		return (-1);
	return (0);
}
