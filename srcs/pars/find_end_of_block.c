/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_end_of_block.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 18:15:47 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/04 18:43:56 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					find_end_of_block(int i, t_objpoint *f)
{
	int				start;
	int				q;

	start = i;
	q = 0;

	while (start <= f->end)
	{
		if (ft_strstr(f->file[start], "{") != NULL)
			q++;
		if (ft_strstr(f->file[start], "}") != NULL || q == 2)
			break ;
		start++;
	}
	if (q == 1)
		return (start);
	return (-1);
}
