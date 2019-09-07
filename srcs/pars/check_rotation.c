/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rotation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:14:31 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/07 16:17:44 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					check_rotation2(int i, int j, t_objpoint *f)
{
	if (check_num_of_param(f->file[numb_of_line(i, j,
		"x", f->file)], "x") != 0)
		return (-1);
	if (check_num_of_param(f->file[numb_of_line(i, j,
		"y", f->file)], "y") != 0)
		return (-1);
	if (check_num_of_param(f->file[numb_of_line(i, j,
		"z", f->file)], "z") != 0)
		return (-1);
	return (0);
}

int					check_rotation(t_objpoint *f)
{
	int				i;
	int				j;
	int				k;

	i = numb_of_line(f->start, f->end, "Rotation", f->file);
	if ((j = find_end_of_block(i, f)) == -1)
	{
		ft_putstrv1("You have problem with block 'Rotation'");
		return (-1);
	}
	if (repit(i, j, "x", f->file) != 1 ||
		repit(i, j, "y", f->file) != 1 ||
		repit(i, j, "z", f->file) != 1)
		return (-1);
	if (check_rotation2(i, j, f) != 0)
		return (-1);
	return (0);
}
