/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plot_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:44:59 by jblack-b          #+#    #+#             */
/*   Updated: 2019/09/28 15:37:35 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

static int			ft_put_points(t_surface *surface,
					t_line *l, t_point *p1, int color)
{
	ft_put_pixel(surface, p1, color);
	l->err2 = l->err;
	if (l->err2 > -l->dx)
	{
		l->err -= l->dy;
		p1->x += l->sx;
	}
	if (l->err2 < l->dy)
	{
		l->err += l->dx;
		p1->y += l->sy;
	}
	return (0);
}

void				ft_plot_line(t_surface *surface,
					t_point *p1, t_point *p2, int color)
{
	t_line			line;

	p1->x = (int)p1->x;
	p2->x = (int)p2->x;
	p1->y = (int)p1->y;
	p2->y = (int)p2->y;
	line.start = *p1;
	line.end = *p2;
	line.dx = (int)ABS((int)p2->x - (int)p1->x);
	line.sx = (int)p1->x < (int)p2->x ? 1 : -1;
	line.dy = (int)ABS((int)p2->y - (int)p1->y);
	line.sy = (int)p1->y < (int)p2->y ? 1 : -1;
	line.err = (line.dx > line.dy ? line.dx : -line.dy) / 2;
	while (((int)p1->x != (int)p2->x || (int)p1->y != (int)p2->y))
		if (ft_put_points(surface, &line, p1, color))
			break ;
}

