/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 00:56:56 by olesgedz          #+#    #+#             */
/*   Updated: 2019/09/28 15:20:25 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

int					ft_get_color(int c1, int c2, double p)
{
	int				r;
	int				g;
	int				b;

	if (c1 == c2)
		return (c1);
	r = ft_get_light((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, p);
	g = ft_get_light((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, p);
	b = ft_get_light(c1 & 0xFF, c2 & 0xFF, p);
	return (r << 16 | g << 8 | b);
}
