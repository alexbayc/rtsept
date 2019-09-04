/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_for_objpoint.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:04:31 by odale-dr          #+#    #+#             */
/*   Updated: 2019/08/31 17:45:55 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_objpoint			*memory_for_objpoint(void)
{
	t_objpoint		*x;

	x = malloc(sizeof(t_objpoint));
	if (x == NULL)
	{
		ft_putstr("\n________________ Memory error. Try again\n");
		return (NULL);
	}
	x->next = NULL;
	x->start = -1;
	x->end = -1;
	return (x);
}
