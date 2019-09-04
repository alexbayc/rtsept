/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 00:55:58 by olesgedz          #+#    #+#             */
/*   Updated: 2019/05/16 19:00:00 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	Fucntion: calculate on what precent of the way, point is being raight now
*	Parameters: start, end, current position
*	Return: precent
*/

double			ft_percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}