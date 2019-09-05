/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_reflection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:14:59 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/05 19:22:22 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					check_reflection(t_objpoint *f)
{
	int				i;

	i = numb_of_line(f->start, f->end, "Reflection", f->file);
	if (check_num_of_param(f->file[i], "Reflection") != 0)
		return (-1);
	return (0);
}
