/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:13:07 by jblack-b          #+#    #+#             */
/*   Updated: 2019/05/16 18:45:27 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"
#include <stdlib.h>

/*
*	Fucntion: exits from program, closes SDL, parameter for freeing stuff
*	Parameters: pointer to function (free stuff) or NULL for nothing
*	Return: none
*/

void	ft_exit(int (*f)(void))
{
	if (f)
		f();
	SDL_Quit();
	exit(-1);
}
