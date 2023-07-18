/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 12:40:20 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/15 22:11:56 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define FT_H

typedef struct s_pars_dict
{
	long long			number;
	char				*w_number;
}	t_parsed;

int									secure_ception(char *splited, int i);
int									sec_dic(char *str);
int									size_dict(char *dict, char **str);
char								**ft_split(char *str, char *charset);
char								*ft_strdup(char *src);
void								free_splt(char **splitted, int i);
void								free_parsed(struct s_pars_dict *parsed);
void								ft_show_tab(struct s_pars_dict *par);
int									ft_atoi(char *str);
struct s_pars_dict					*fill_struct(struct s_pars_dict *parsed,
										char *str, int lin, int k);

#endif
