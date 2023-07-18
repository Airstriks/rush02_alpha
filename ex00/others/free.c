/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:45:18 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/15 22:34:05 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_splt(char **splitted, int i)
{
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

void	free_parsed(struct s_pars_dict *parsed)
{
	int				i;

	i = 0;
	while (parsed[i].w_number)
	{
		free(parsed[i].w_number);
		i++;
	}
	free(parsed);
}
