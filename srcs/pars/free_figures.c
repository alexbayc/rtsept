/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:05:01 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/24 18:17:37 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				free_figures(t_objpoint *f)
{
	t_objpoint		*x;

	while (f->next != NULL)
	{
		x = f;
		f = f->next;
		free(x);
		x = NULL;
	}
	free(f);
	f = NULL;
}
