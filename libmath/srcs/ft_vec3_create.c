/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec3_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:51:53 by jblack-b          #+#    #+#             */
/*   Updated: 2019/09/28 15:11:48 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_vec3			ft_vec3_create(float x, float y, float z)
{
	t_vec3		new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}
