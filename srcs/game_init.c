/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 19:37:44 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/25 19:40:45 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			game_init(t_game *game)
{
	game->sdl = malloc(sizeof(t_sdl));
	game->image = ft_surface_create(WIN_W, WIN_H);
	game->main_objs.lights = ft_memalloc(sizeof(t_light) * 5);
	game->main_objs.lights[0] = (t_light){(t_vec3){0, 0, -5}, 2};
	game->main_objs.lights[1] = (t_light){(t_vec3){-5, 0, -5}, 2};
	game->main_objs.lights[2] = (t_light){(t_vec3){-2, 0, -5}, 2};
	game->main_objs.lights[3] = (t_light){(t_vec3){5, 0, -5}, 2};
	game->main_objs.elum_num = 5;
	game->init_render = 1;
	game->origin = (t_vec3){0, 0, 5, 1};
}
