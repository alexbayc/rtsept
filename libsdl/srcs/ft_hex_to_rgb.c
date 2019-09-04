/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 00:57:48 by olesgedz          #+#    #+#             */
/*   Updated: 2019/05/16 18:51:30 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

/*
*	Fucntion: turns hex color to rgb 
*	Parameters: hex color, opacity
*	Return: resulting color as (t_rgba *) 
*/

t_rgba *ft_hex_to_rgb(int hex, int a)
{
	static t_rgba rgb;
	rgb.r = (hex >> 16) & 0xFF; 
	rgb.g = (hex >> 8) & 0xFF; 
	rgb.b = hex & 0xFF; 
	rgb.a = a;
	return (&rgb);
}