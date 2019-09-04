/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 17:02:02 by odale-dr          #+#    #+#             */
/*   Updated: 2019/08/31 18:17:47 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					type_select(char *s)
{
	if (ft_strstr(s, "sphere") != 0 || ft_strstr(s, "Sphere") != 0)
		return (1);
	if (ft_strstr(s, "cylinder") != 0 || ft_strstr(s, "Cylinder") != 0)
		return (2);
	if (ft_strstr(s, "plane") != 0 || ft_strstr(s, "Plane") != 0)
		return (3);
	if (ft_strstr(s, "cone") != 0 || ft_strstr(s, "Cone") != 0)
		return (4);
	ft_putstrv("You have unknown Type of object at json-file");
	return (-1);
}
