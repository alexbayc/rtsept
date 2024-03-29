/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:13:28 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/09 19:19:25 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double			ft_fl_after(char *s, double x, int i)
{
	double		f;
	double		h;

	h = 10;
	f = 0;
	while (s[i + 1] != '\0' && ft_isdigit(s[i + 1]) != 0)
	{
		if (s[i + 1] != 48)
			f = f + (s[i + 1] - 48) / h;
		h = h * 10;
		i++;
	}
	return (x + f);
}

float			return_float(char *s)
{
	float			x;
	float			znak;
	int				i;

	znak = 1;
	x = 0;
	i = 0;
	while (ft_isdigit(s[i]) != 1)
	{
		if (s[i] == '\0')
			return (0);
		if (s[i] == '-')
			znak = -1;
		i++;
	}
	while (s[i] != '.' && s[i] != ',' && ft_isdigit(s[i]) != 0)
	{
		x = x * 10 + (s[i] - 48);
		if (x > 100000)
			return (100000);
		i++;
	}
	if (s[i] != '\0')
		x = (float)ft_fl_after(s, x, i);
	return (x * znak);
}
