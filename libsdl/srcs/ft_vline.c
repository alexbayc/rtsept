/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 20:32:54 by jblack-b          #+#    #+#             */
/*   Updated: 2019/05/16 19:25:28 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"


//teeeesttt
void			ft_vline(t_surface *surface,\
	t_point *p1, t_point *p2, int color)
{	
	// int *pix = (int*) surface->data;
	//  p1->y = clamp(p1->y, 0, surface->height-1);
	//  p2->y = clamp(p2->y, 0,surface->height-1);
	// while (p1->y != p2->y)
	// {
	// 	//ft_put_pixel(surface, p1, color);
	// 	pix[p1->y * surface->width+p1->x] = color;
	// 	p1->y++;
	// }
		int *pix = (int*)surface->data;
	 p1->y = clamp(p1->y, 0, surface->height-1);
	 p2->y = clamp(p2->y, 0, surface->height-1);
	if(p2->y == p1->y)
	 	pix[p1->y* surface->width+ p1->x] = color;
	else if(p2->y > p1->y)
	 {
	 	pix[p1->y * surface->width + p1->x] = color;
	 	for(int y=p1->y+1; y<p2->y; ++y) pix[y* surface->width + p1->x] = color;
		pix[p2->y*surface->width+p1->x] = color;
	 }
}

// static void vline(int x, int p1->y,int p2->y, int top,int middle,int bottom, t_game *game)
// {
// 	int *pix = (int*) game->sdl.surface->data;
// 	 p1->y = clamp(p1->y, 0, WIN_H-1);
// 	 p2->y = clamp(p2->y, 0, WIN_H-1);
// 	if(p2->y == p1->y)
// 	 	pix[p1->y* game->sdl.surface->width+x] = middle;
// 	else if(p2->y > p1->y)
// 	 {
// 	 	pix[p1->y *game->sdl.surface->width +x] = top;
// 	 	for(int y=p1->y+1; y<p2->y; ++y) pix[y*game->sdl.surface->width+x] = middle;
// 		pix[p2->y*game->sdl.surface->width+x] = bottom;
// 	 }
// }
