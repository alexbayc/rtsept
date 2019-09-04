/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_surface_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 00:29:45 by olesgedz          #+#    #+#             */
/*   Updated: 2019/05/16 20:00:18 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

/*
*	Fucntion: creates a surface
*	Parameters: width, height os the surface
*	Return: malloced surface
*/

t_surface *ft_surface_create(int width, int height)
{
	t_surface *new_surface;
	new_surface = ft_memalloc(sizeof(t_surface));
	new_surface->data = ft_memalloc(sizeof(Uint32) * width * height);
	new_surface->height = height;
	new_surface->width = width;
	return (new_surface);
}