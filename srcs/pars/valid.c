/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 18:41:47 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/24 19:42:04 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int						s_valid(char *json, t_objpoint *f)
{
	int					fd;

	fd = 0;
	if (json == NULL || ft_strlen(json) == 0 || ft_strstr(json, "json") == NULL)
		return (1);
	if ((fd = open(json, O_RDONLY)) == -1)
		return (2);
	if (read_fd(fd, f) != 0)
		return (3);
	return (0);
}

int						valid(char *json, t_objpoint *f)
{
	int					flag;

	flag = s_valid(json, f);
	if (flag == 1)
		ft_putstrv("Please, choose the scene './rtv scene/...' ");
	if (flag == 2)
		ft_putstrv("Impossible to open your file (fd = -1). Try again");
	f->s = ft_strnew(5);
	ft_strcpy(f->s, "hello");
	return (flag);
}
