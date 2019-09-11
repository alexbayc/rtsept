/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_radius.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 18:46:54 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/11 19:48:46 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float					return_clr(char *str)
{
	float				clr;

	if ((clr = return_float(ft_strchr(str, 58))) < 0)
	{
		ft_putstrv1("One of your Colors is negative");
		return (-1);
	}
	if (clr >= 10)
	{
		ft_putstrv1("One of your Colors size is too big (more than 10)");
		return (-1);
	}
	printf("\n -> %f <- \n", clr);
	return (clr);
}

float					return_xyz(char *str)
{
	float				xyz;

	xyz = return_float(ft_strchr(str, 58));
	if (xyz >= 100000)
	{
		ft_putstrv1("Your coordinats size is too big (more than 100000)");
		return (-123456789);
	}
	printf("\n xyz -> %f <- \n", xyz);
	return (xyz);
}

float					return_reflection(t_objpoint *f)
{
	float				ref;
	char				*str;

	str = f->file[numb_of_line(f->start, f->end, "Reflection", f->file)];
	if ((ref = return_float(ft_strchr(str, 58))) < 0)
	{
		ft_putstrv1("Your Reflection size is not possible");
		return (-1);
	}
	if (ref >= 50)
	{
		ft_putstrv1("Your Reflection size is too big (more than 50)");
		return (-1);
	}
	printf("\n -> %f <- \n", ref);
	return (ref);
}

float					return_radius(t_objpoint *f)
{
	float				rad;
	char				*str;

	str = f->file[numb_of_line(f->start, f->end, "Radius", f->file)];
	if ((rad = return_float(ft_strchr(str, 58))) <= 0)
	{
		ft_putstrv1("Your Radius size is not possible");
		return (-1);
	}
	if (rad >= 100000)
	{
		ft_putstrv1("Your Radius size is too big (more than 100000)");
		return (-1);
	}
	printf("\n -> %f <- \n", rad);
	return (rad);
}
