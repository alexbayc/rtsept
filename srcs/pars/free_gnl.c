/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:28:15 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/24 18:17:49 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				free_gnl(char **s)
{
	int				i;
	char			*p;

	i = 0;
	while (i <= 9999)
	{
		p = s[i];
		free(p);
		i++;
	}
}
