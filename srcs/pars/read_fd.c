/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 12:08:43 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/24 18:28:36 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int						read_gnl(int fd, t_objpoint *f, char **file)
{
	int					i;

	i = 0;
	while (get_next_line(fd, &file[i]) != 0 && i < 9999)
	{
		i++;
	}
	if (i >= 9999)
	{
		ft_putstrv("Your json-file is too big. Fix your file");
		free_gnl(file);
		return (-1);
	}
	if (parsing(f, file) != 0)
	{
		free_gnl(file);
		return (-1);
	}
	free_gnl(file);
	return (0);
}

int						read_fd(int fd, t_objpoint *f)
{
	char				**file;

	if ((file = malloc(sizeof(char *) * 10000)) == NULL)
	{
		ft_putstrv("Memory error. Maybe you have not free space");
		return (-1);
	}
	if (read_gnl(fd, f, file) != 0)
	{
		free(file);
		return (-1);
	}
	free(file);
	return (0);
}
