/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppm_image_read.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 22:13:42 by olesgedz          #+#    #+#             */
/*   Updated: 2019/05/16 19:04:31 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"
#include "libft.h"
#include <fcntl.h>
#include <unistd.h>

/*
*	Fucntion: reads ppm image to surface
*	Parameters: name of the file
*	Return: t_surface
*	! Work in progress doesnt work
*/

t_surface *ft_ppm_image_read(char *s)
{
    int fd = open(s, O_RDONLY);
	char *line;
	while (get_next_line(fd, &line) > 0)
	{
		printf("%s\n",line);
	}
	return (NULL);
}