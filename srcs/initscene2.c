/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initscene2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:41:50 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/21 15:29:13 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				initscene2(t_obj *cpu_spheres, int n, t_objpoint *ff)
{
	int				i;
	t_objpoint		*f;

	i = 0;
	f = ff;
	while (i < n)
	{
		cpu_spheres[i].radius = f->fig->radius;
		cpu_spheres[i].position = f->fig->position;
		cpu_spheres[i].color = f->fig->color;
		cpu_spheres[i].emission = f->fig->emission;
		cpu_spheres[i].type = f->fig->type;
		cpu_spheres[i].reflection = f->fig->reflection;
		cpu_spheres[i].plane_d = f->fig->plane_d;
		cpu_spheres[i].v = f->fig->v;
		i++;
		f = f->next;
	}
}
