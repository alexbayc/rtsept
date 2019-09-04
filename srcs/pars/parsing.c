/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:57:20 by odale-dr          #+#    #+#             */
/*   Updated: 2019/08/31 19:44:46 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int						check_q(int st, int end, char **file)
{
	if (repit(st, end, "Type", file) != 1)
	{
		return (-1);
	}
	return (0);
}

int						extract(int st, int end, char **file, t_objpoint *f)
{
	int					type;

	if (check_q(st, end, file) != 0)
		return (-1);
	if ((type = fig_valid(st, end, file)) == -1)
		return (-1);
	while (f->end != -1)
		f = f->next;
	f->start = st;
	f->end = end;
	f->file = file;
	if (valid_type(f, type) != 0)
		return (-1);
	ft_putstr(ft_itoa(f->end));
	ft_putstr(" <--------++++++ end of obj\n\n\n");
	f->next = memory_for_objpoint();
	return (0);
}

int						cuting(char **file, int *i, t_objpoint *f)
{
	int					start;
	int					end;
	int					c;

	c = 0;
	start = *i;
	end = *i;
	while (file[end] != NULL)
	{
		if (ft_strstr(file[end], "{") != NULL)
			c++;
		if (ft_strstr(file[end], "}") != NULL)
			c--;
		if (c == 0 || c == 3)
			break ;
		end++;
	}
	*i = end;
	if (c != 3)
		c = extract(start, end, file, f);
	if (c == -1 || c == 3)
	{
		ft_putstrv1("Check and fix your object before the line - ");
		ft_putendl(ft_itoa(end));
	}
	return (c);
}

int						parsing(t_objpoint *f, char **file)
{
	int					i;
	int					flag;

	flag = 0;
	i = 0;
	while (file[i] != NULL && i <= 10000 && flag == 0)
	{
		//ft_putstrv(file[i]);
		if (ft_strstr(file[i], "{") != NULL)
			flag = cuting(file, &i, f);
		i++;
	}
	ft_putstr(ft_itoa(i));
	return (flag);
}
