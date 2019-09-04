/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_poly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:35:30 by jblack-b          #+#    #+#             */
/*   Updated: 2019/06/03 15:42:55 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"
#include <float.h>
#include <limits.h>

// min X and max X for every horizontal line within the triangle
static void ScanLine(long x1, long y1, long x2, long y2, long ContourX[][2], int width)
{
  long sx, sy, dx1, dy1, dx2, dy2, x, y, m, n, k, cnt;

  sx = x2 - x1;
  sy = y2 - y1;

  if (sx > 0) dx1 = 1;
  else if (sx < 0) dx1 = -1;
  else dx1 = 0;

  if (sy > 0) dy1 = 1;
  else if (sy < 0) dy1 = -1;
  else dy1 = 0;

  m = ABS(sx);
  n = ABS(sy);
  dx2 = dx1;
  dy2 = 0;

  if (m < n)
  {
    m = ABS(sy);
    n = ABS(sx);
    dx2 = 0;
    dy2 = dy1;
  }

  x = x1; y = y1;
  cnt = m + 1;
  k = n / 2;

  while (cnt--)
  {
    if ((y >= 0) && (y < width))
    {
      if (x < ContourX[y][0]) ContourX[y][0] = x;
      if (x > ContourX[y][1]) ContourX[y][1] = x;
    }

    k += n;
    if (k < m)
    {
      x += dx2;
      y += dy2;
    }
    else
    {
      k -= m;
      x += dx1;
      y += dy1;
    }
  }
}


void ft_draw_poly(t_surface *surface, t_point p0, t_point p1, t_point p2)
{
  int y;
  long ContourX[surface->height][2];
  for (y = 0; y < surface->height; y++)
  {
    ContourX[y][0] = LONG_MAX; // min X
    ContourX[y][1] = LONG_MIN; // max X
  }
	  ScanLine(p0.x, p0.y, p1.x, p1.y, ContourX, surface->width);
  	ScanLine(p1.x, p1.y, p2.x, p2.y, ContourX, surface->width);
  	ScanLine(p2.x, p2.y, p0.x, p0.y, ContourX, surface->width);
  for (y = 0; y < surface->height; y++)
  {
	  //printf("%ld >= %ld\n", ContourX[y][1], ContourX[y][0]);
    if (ContourX[y][1] >= ContourX[y][0])
    {
      long x = ContourX[y][0];
      long len = 1 + ContourX[y][1] - ContourX[y][0];

      // Can draw a horizontal line instead of individual pixels here
	 
      while (len--)
      {
        ft_put_pixel(surface, &(t_point){x++, y}, 0xff0000);
      }
    }
  }
}