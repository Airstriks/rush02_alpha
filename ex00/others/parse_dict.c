/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:25:47 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/15 22:14:35 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	size_dict(char *dict, char **str)
{
	int				fd;
	int				size;
	char			buffer[1];

	size = 0;
	fd = open(dict, O_RDONLY);
	if (fd < 0)
		return (fd);
	while (read(fd, buffer, 1) != 0)
		size++;
	*str = malloc((size + 1) * sizeof(char));
	if (*str == NULL)
	{
		fd = close(fd);
		return (fd);
	}
	close (fd);
	fd = open(dict, O_RDONLY);
	if (fd < 0)
		return (fd);
	read(fd, *str, size);
	(*str)[size] = 0;
	return (fd);
}

struct s_pars_dict	*alloc_struct(char *str)
{
	int					i;
	int					lin;
	int					k;
	t_parsed			*parsed;

	i = 0;
	lin = 0;
	k = 0;
	while (str[i])
	{
		if ((str[i] == '\n') && (str[i + 1] > 47 && str[i + 1] < 58))
			lin++;
		i++;
	}
	parsed = malloc((lin + 2) * sizeof (struct s_pars_dict));
	if (parsed == NULL)
		return (parsed);
	parsed = fill_struct(parsed, str, lin, k);
	if (parsed[0].number < 0)
		free_parsed(parsed);
	parsed[lin + 1].w_number = 0;
	free(str);
	return (parsed);
}

struct	s_pars_dict	*fill_struct(struct s_pars_dict *parsed, char *str, int lin,
	int k)
{
	char			**splitted_str;
	int				i;

	splitted_str = ft_split(str, "\n:");
	if (splitted_str == NULL)
		return (parsed);
	i = 0;
	while (splitted_str[i])
	{
		parsed[k].number = atoi(splitted_str[i]);
		free(splitted_str[i]);
		parsed[k].w_number = ft_strdup(splitted_str[i + 1]);
		if (parsed[k].w_number == NULL)
		{
			free_splt(splitted_str, i + 1);
			break ;
		}
		free(splitted_str[i + 1]);
		k++;
		i += 2;
	}
	free(splitted_str);
	if (k != lin + 1)
		parsed[0].number = -(k);
	return (parsed);
}

int	main(void)
{
	char			*str;
	int				fd;
	t_parsed		*parsed;

	fd = size_dict("numbers.dict", &str);
	if (fd < 0)
	{
		//ft_error;
		return (1);
	}
	if (str == NULL)
		return (1);
	if (sec_dic(str) < 0)
		return (1);
	if (sec_dic(str) > 0)
	{
		write(1, "e", 1);
		//ft_error();
		return (1);
	}
	parsed = alloc_struct(str);
	if (parsed == NULL)
		return (1);
	write(1, "good\n", 5);
	free_parsed(parsed);
	return (0);
}
