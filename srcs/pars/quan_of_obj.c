/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quan_of_obj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 20:13:32 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/11 19:59:28 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int						quan_of_obj(t_objpoint *f)
{
	int					n;
	t_objpoint			*ff;

	ff = f;
	n = 0;
	while (ff->next != NULL || ff->end != -1)
	{
		ff = ff->next;
		n++;
	}
	return (n);
}
