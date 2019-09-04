/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:29:12 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/04 18:58:07 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			message(int st, int end, char *sl)
{
	ft_putstrv1("You have WRONG number of parameter ''");
	ft_putstr(sl);
	ft_putstr("'' at your object between lines ");
	ft_putstr(ft_itoa(st + 1));
	ft_putstr(" - ");
	ft_putstr(ft_itoa(end + 1));
	ft_putstr(".  (First letter of parameter must be uppercase).");
	ft_putstr("\n\n");
}

int				repit_d(int st, int end, char *sl, char **file)
{
	int			i;
	int			s;

	s = st;
	i = 0;
	while (s <= end)
	{
		if (ft_strstr(file[s], sl) != NULL)
			i++;
		s++;
	}
	if (i != 3)
		message(st, end, sl);
	return (i);
}

int				repit(int st, int end, char *sl, char **file)
{
	int			i;
	int			s;

	s = st;
	i = 0;
	while (s <= end)
	{
		if (ft_strstr(file[s], sl) != NULL)
			i++;
		s++;
	}
	if (i != 1)
		message(st, end, sl);
	return (i);
}
