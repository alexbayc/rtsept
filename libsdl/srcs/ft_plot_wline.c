/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plot_wline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 15:39:46 by jblack-b          #+#    #+#             */
/*   Updated: 2019/05/17 14:39:55 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

/*
*	Fucntion: draws line on the screen using Xiaolin Wu's line algorithm
*	Parameters: surface, point 1, point 2, color of the line
*	Return: none
*	? Is it any better? I have no idea
*/


static void plot(t_surface *surface, int x, int y, float opacity, int color)
{
    opacity = powf(opacity, 1/2.2f);
    int *pix = ((int*) surface->data) + y * surface->width + x;
    int r0 = (*pix >> 16) & 0xFF, r1 = (color >> 16) & 0xFF;
    int g0 = (*pix >>  8) & 0xFF, g1 = (color >>  8) & 0xFF;
    int b0 = (*pix >>  0) & 0xFF, b1 = (color >>  0) & 0xFF;
    int r = max(r0, opacity*r1);
    int g = max(g0, opacity*g1);
    int b = max(b0, opacity*b1);
    *pix = (r << 16) | (g << 8) | b;
}

void		ft_plot_wline(t_surface *surface,
	t_fpoint *p0, t_fpoint *p1, int color)
{
    int steep = fabsf(p1->y - p0->y) > fabsf(p1->x - p0->x);
    if(steep)   { float tmp; tmp=p0->x; p0->x=p0->y; p0->y=tmp; tmp=p1->x; p1->x=p1->y; p1->y=tmp; }
    if(p0->x > p1->x) { float tmp; tmp=p0->x; p0->x=p1->x; p1->x=tmp; tmp=p0->y; p0->y=p1->y; p1->y=tmp; }
    float dx = p1->x-p0->x, dy = p1->y-p0->y, gradient = dy/dx;
    int xend = (int)(p0->x + 0.5f);
    int yend = p0->y + gradient * (xend - p0->x);
    float xgap = rfpart(p0->x + 0.5f);
    int xpxl1 = xend;
    int ypxl1 = (int)(yend);
    if(steep)
    {
        plot(surface,ypxl1,   xpxl1, rfpart(yend) * xgap, color);
        plot(surface,ypxl1+1, xpxl1,  fpart(yend) * xgap, color);
    }
    else
    {
        plot(surface,xpxl1, ypxl1  , rfpart(yend) * xgap, color);
        plot(surface,xpxl1, ypxl1+1,  fpart(yend) * xgap, color);
    }
    float intery = yend + gradient;
    xend = (int)(p1->x + 0.5f);
    yend = p1->y + gradient * (xend - p1->x);
    xgap = fpart(p1->x + 0.5);
    int xpxl2 = xend;
    int ypxl2 = (int)(yend);
    if(steep)
    {
        plot(surface, ypxl2  , xpxl2, rfpart(yend) * xgap, color);
        plot(surface, ypxl2+1, xpxl2,  fpart(yend) * xgap, color);
    }
    else
    {
        plot(surface,xpxl2, ypxl2,  rfpart(yend) * xgap, color);
        plot(surface,xpxl2, ypxl2+1, fpart(yend) * xgap, color);
    }
    // main loop
    for(int x = xpxl1 + 1; x < xpxl2; ++x, intery += gradient)
        if(steep)
        {
            plot(surface, (int)(intery)  , x, rfpart(intery), color);
            plot(surface, (int)(intery)+1, x,  fpart(intery), color);
        }
        else
        {
            plot(surface, x, (int)(intery),  rfpart(intery), color);
            plot(surface, x, (int)(intery)+1, fpart(intery), color);
        }
}