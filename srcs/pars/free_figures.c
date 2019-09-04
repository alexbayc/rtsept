/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_figures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 18:05:01 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/04 20:56:23 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				free_figures(t_objpoint *f)
{
	t_objpoint		*x;

	//ft_putstrv(" 1 EEEENDDD");

	while (f->next != NULL)
	{
		x = f;
		f = f->next;
		free(x);
		x = NULL;
	}
	//ft_putstrv(" 2 EEEENDDD");
	free(f);
	f = NULL;
}
