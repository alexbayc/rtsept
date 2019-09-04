/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb_of_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:07:46 by odale-dr          #+#    #+#             */
/*   Updated: 2019/08/31 19:43:41 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int						numb_of_line(int s, int end, char *sl, char **file)
{
	int					st;

	st = s;
	while (st <= end)
	{
		if (ft_strstr(file[st], sl) != 0)
			return (st);
		st++;
	}
	ft_putstrv1("You have NOT ''");
	ft_putstr(sl);
	ft_putstr("'' at your object between lines ");
	ft_putstr(ft_itoa(s));
	ft_putstr(" - ");
	ft_putstr(ft_itoa(end));
	ft_putstr(".  (First letter of parameter must be uppercase).");
	ft_putstr("\n\n");
	return (-1);
}
