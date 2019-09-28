/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 00:55:58 by olesgedz          #+#    #+#             */
/*   Updated: 2019/09/28 15:29:17 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double				ft_percent(int start, int end, int current)
{
	double			placement;
	double			distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}
