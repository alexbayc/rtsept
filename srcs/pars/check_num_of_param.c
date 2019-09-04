/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_of_param.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odale-dr <odale-dr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 19:23:55 by odale-dr          #+#    #+#             */
/*   Updated: 2019/09/04 20:44:00 by odale-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					check_num2(char *stroka)
{
	char			*s;
	int				i;
	int				j;

	s = stroka;
	i = 0;
	while (s[i] != '\0')
	{
		j = ft_isdigit(s[i]);
		if (j != 0)
			return (0);
		i++;
	}
	ft_putstrv("You have not parametr at one of your line");
	ft_putstrv("Right record for example: ' ''distance y'' : 0.5 , ' ");
	return (-1);
}

int					check_num(char *stroka)
{
	char			*s;
	int				i;
	int				j;

	s = stroka;
	i = 0;
	while (s[i] != 58)
	{
		j = ft_isdigit(s[i]);
		if (j != 0)
		{
			ft_putstrv("You have wrong record of parametr line");
			ft_putstrv("Maybe you have parametr before separator");
			ft_putstrv("Right record for example: ' ''distance y'' : 0.5 , ' ");
			return (-1);
		}
		i++;
	}
	return (0);
}

int					check_num_of_param(char *stroka, char *parametr)
{
	char			*s;
	int				t;

	if ((s = ft_strstr(stroka, parametr) + ft_strlen(parametr)) == NULL)
	{
		ft_putstrv("You have not parametr:");
		ft_putstrv(parametr);
		return (-1);
	}
	if ((s = ft_strstr(s, ":")) == NULL)
	{
		ft_putstrv("You must have seperator ':' at your parametr line");
		ft_putstrv("For example ' ''distance y'' : 0.5 , ' ");
		return (-1);
	}
	if (check_num(stroka) != 0 || check_num2(stroka) != 0)
		return (-1);
	return (0);
}
