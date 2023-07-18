/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 21:32:59 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/15 22:33:15 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	sec_dic(char *str)
{
	char			**splited;
	int				i[2];

	splited = ft_split(str, "\n");
	if (splited == NULL)
		return (-1);
	i[0] = 0;
	i[1] = 1;
	while (splited[i[0]])
	{
		if (splited[i[0]][0] < '0' || splited[i[0]][0] > '9')
			return (1);
		while (splited[i[0]][i[1]] && splited[i[0]][i[1]] != ':')
		{
			if ((splited[i[0]][i[1]] != 32) && (splited[i[0]][i[1]] < '0'
				|| splited[i[0]][i[1]] > '9'))
				return (1);
			i[1]++;
		}
		if (secure_ception(splited[i[0]], i[1] + 1))
			return (1);
		i[0]++;
	}
	free_splt(splited, 0);
	return (0);
}

int	secure_ception(char *splited, int i)
{
	if (splited[i] == 0)
		return (1);
	while (splited[i] && splited[i] == 32)
		i++;
	if (splited[i] == 0)
		return (1);
	while (splited[i])
	{
		if (splited[i] < 32 || splited[i] > 126)
			return (1);
		i++;
	}
	return (0);
}
