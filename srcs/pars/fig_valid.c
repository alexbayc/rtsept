/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fig_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:05:36 by odale-dr          #+#    #+#             */
/*   Updated: 2019/08/31 17:29:35 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					fig_valid(int st, int end, char **file)
{
	int				i;
	int				type;

	type = -1;
	if ((i = numb_of_line(st, end, "Type", file)) == -1)
		return (-1);
	type = type_select(file[i]);
	return (type);
}
