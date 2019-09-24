/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:03:08 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/24 19:21:54 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				ft_putstrv2(char *s, int end)
{
	ft_putstr("\n");
	ft_putstr("___________________________ ");
	ft_putstr(s);
	ft_putendl(ft_itoa(end));
}

void				ft_putstrv1(char *s)
{
	ft_putstr("\n");
	ft_putstr("___________________________ ");
	ft_putstr(s);
}

void				ft_putstrv(char *s)
{
	ft_putstr("\n");
	ft_putstr("___________________________ ");
	ft_putstr(s);
	ft_putstr("\n");
}
