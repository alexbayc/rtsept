/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:13:09 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/05 19:05:34 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					check_position2(int i, int j, t_objpoint *f)
{
	if (check_num_of_param(f->file[numb_of_line(i, j,
		"distance x", f->file)], "distance x") != 0)
		return (-1);
	if (check_num_of_param(f->file[numb_of_line(i, j,
		"distance y", f->file)], "distance y") != 0)
		return (-1);
	if (check_num_of_param(f->file[numb_of_line(i, j,
		"distance z", f->file)], "distance z") != 0)
		return (-1);
	return (0);
}

int					check_position(t_objpoint *f)
{
	int				i;
	int				j;
	int				k;

	i = numb_of_line(f->start, f->end, "Position", f->file);
	if ((j = find_end_of_block(i, f)) == -1)
	{
		ft_putstrv1("You have problem with block 'Position'");
		return (-1);
	}
	if (repit_d(i, j, "distance", f->file) != 3)
		return (-1);
	if (repit(i, j, "distance x", f->file) != 1 ||
		repit(i, j, "distance y", f->file) != 1 ||
		repit(i, j, "distance z", f->file) != 1)
		return (-1);
	if (check_position2(i, j, f) != 0)
		return (-1);
	return (0);
}
