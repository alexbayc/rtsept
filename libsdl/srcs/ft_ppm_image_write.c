/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppm_image_write.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 00:59:06 by olesgedz          #+#    #+#             */
/*   Updated: 2019/05/16 19:06:33 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"
#include "fcntl.h"
#include <stdio.h>
#include <unistd.h>

/*
*	Fucntion: saves ppm image to hdd
*	Parameters: surface to save
*	Return: if was completed 
*	! too slow, needs optimization
*/

int ft_ppm_image_write(t_surface *surface)
{
    int fd;
	t_rgba *color;
	fd = open( "ll.ppm",  O_RDWR | O_APPEND | O_CREAT | O_TRUNC, 0664);	
	ft_putstr_fd("P3\n", fd);
	ft_putstr_fd(ft_itoa(surface->width), fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(ft_itoa(surface->height), fd);
	ft_putstr_fd("\n255\n", fd);
	if (fd<0)
	{
		printf("Open failed\n");
		return 1;
	}
	int j = 0;
	printf("%x\n", surface->data[1+ 1 * surface->width]);

	printf("w:%zu h:%zu\n",surface->width, surface->height);
	int count = 0;
	while (j < surface->height)
	{
		int k = 0;
		while (k < surface->width)
		{
			color = ft_hex_to_rgb(surface->data[k + j * surface->width],255);
			ft_putstr_fd(ft_itoa(color->r), fd);
			ft_putstr_fd(" ", fd);
			ft_putstr_fd(ft_itoa(color->g), fd);
			ft_putstr_fd(" ", fd);
			ft_putstr_fd(ft_itoa(color->b), fd);
			ft_putstr_fd(" ", fd);
			//dprintf(fd, "%d %d %d", color->r, color->g, color->b); //deoesn't work
			k++;
		}
		j++;
	}
	ft_putstr("Saved\n");
	close(fd);
	return (0);
}