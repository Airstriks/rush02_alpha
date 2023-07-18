/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 13:45:37 by vlevy             #+#    #+#             */
/*   Updated: 2023/07/15 21:53:55 by vlevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char			*dest;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (src[j] == 32)
		j++;
	i = j;
	while (src[i])
		i++;
	dest = malloc((i + 1) * (sizeof (char)));
	i = 0;
	if (dest == NULL)
		return (NULL);
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	printf("Control : %s|\nTest : %s|\n", strdup(argv[1]), ft_strdup(argv[1]));
	return (0);
}*/
