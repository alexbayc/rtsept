/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 13:22:51 by jblack-b          #+#    #+#             */
/*   Updated: 2019/09/27 18:54:39 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsdl.h"

/*
*	Fucntion: handels input, here just because we not suppose to use anything from SDL
*			openly.
*	Parameters: main struct of program, fuction that handles events from the program
*	Return: none
*/
void	ft_input(void *main, int (*f)(void *main, SDL_Event *ev, void *game), void *game)
{
	SDL_Event ev;

	while (SDL_PollEvent(&ev))
		f(main, &ev, game);
}
