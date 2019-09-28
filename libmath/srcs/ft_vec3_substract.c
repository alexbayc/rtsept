/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_substract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 13:45:42 by jblack-b          #+#    #+#             */
/*   Updated: 2019/09/28 15:15:15 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vec3				ft_vec3_substract(t_vec3 a, t_vec3 b)
{
	t_vec3			new;

	new.x = (a.x - b.x);
	new.y = (a.y - b.y);
	new.z = (a.z - b.z);
	return (new);
}
