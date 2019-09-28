/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 00:55:35 by olesgedz          #+#    #+#             */
/*   Updated: 2019/09/28 15:20:49 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}
