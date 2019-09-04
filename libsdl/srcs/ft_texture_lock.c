/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_lock.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:00:59 by jblack-b          #+#    #+#             */
/*   Updated: 2019/05/16 19:25:19 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

/*
*	Fucntion: used when writing to texture is needed
*	- use it to get pointer, array of pixel that texture consist of 
*	Parameters: sdl, texture
*	Return: pointer to array of pixel that texture consist of 
*/

Uint32		*ft_texture_lock(t_sdl *sdl, t_texture *texture)
{
	//SDL_LockTexture(texture->sdl_texture, NULL, (void **)texture->pixels, &texture->pitch);
	SDL_LockTexture(texture->sdl_texture, NULL, (void **)&texture->pixels, &texture->pitch);
	return (texture->pixels);
}