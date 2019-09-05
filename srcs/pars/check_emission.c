/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_emission.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:16:21 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/05 19:04:09 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					check_emission2(int i, int j, t_objpoint *f)
{
	if (check_num_of_param(f->file[numb_of_line(i, j,
		"red", f->file)], "red") != 0)
		return (-1);
	if (check_num_of_param(f->file[numb_of_line(i, j,
		"green", f->file)], "green") != 0)
		return (-1);
	if (check_num_of_param(f->file[numb_of_line(i, j,
		"blue", f->file)], "blue") != 0)
		return (-1);
	return (0);
}

int					check_emission(t_objpoint *f)
{
	int				i;
	int				j;
	int				k;

	i = numb_of_line(f->start, f->end, "Emission", f->file);
	if ((j = find_end_of_block(i, f)) == -1)
	{
		ft_putstrv1("You have problem with block 'Emission'");
		return (-1);
	}
	if (repit(i, j, "red", f->file) != 1 ||
		repit(i, j, "green", f->file) != 1 ||
		repit(i, j, "blue", f->file) != 1)
		return (-1);
	if (check_emission2(i, j, f) != 0)
		return (-1);
	return (0);
}
