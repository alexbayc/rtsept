/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cfloat3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:52:04 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/21 14:54:06 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

cl_float3				create_cfloat3(float x, float y, float z)
{
	cl_float3			re;

	re.v4[0] = x;
	re.v4[1] = y;
	re.v4[2] = z;
	return (re);
}