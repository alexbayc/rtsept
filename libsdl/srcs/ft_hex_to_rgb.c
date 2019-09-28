/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 00:57:48 by olesgedz          #+#    #+#             */
/*   Updated: 2019/09/28 15:21:41 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

t_rgba				*ft_hex_to_rgb(int hex, int a)
{
	static t_rgba	rgb;

	rgb.r = (hex >> 16) & 0xFF;
	rgb.g = (hex >> 8) & 0xFF;
	rgb.b = hex & 0xFF;
	rgb.a = a;
	return (&rgb);
}
