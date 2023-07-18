#include <string.h>
#include <stdio.h>
#include "centaine.c"
#include "dizaine.c"
#include "unite.c"
#include "ft_itoa.c"
#include "ft_atoi.c"

long	*ft_strcat(long *dest, long *src, long size)
{
	long count;
	long	i;

	count = 0;
	i = 0;
	while (dest[count] < size)
	{
		count++;
	}
	while (src[i] < size)
	{
		dest[count + i] = src[i];
		i++;
	}
	return (dest);
}


long	*concat(long int nb)
{
	long	temp;
	long	tab[4][4];
	long	i;
	long	**prefinal;
	long	nbtot;
	long	*final;


	prefinal = malloc(4*sizeof(char*));
	*prefinal = malloc(20*sizeof(char));
	i = 3;
	nbtot = nb;
	while(nb >= 0)
	{
		temp = nb % 1000;
		nb = nb / 1000;
		tab[0][i] = temp;
		i--;
	}
	i++;
	nb = nbtot;
	while(i <= 3)
	{
		temp = nb;
		nb = nb / 1000;
		tab[1][i] = temp;
		i++;
	}

	i = 0;
	while(i <= 3)
	{
		if(tab[0][i] >= 100)
		{
			if(i == 3)
				temp = 4;
			else
				temp = 5;
			
			prefinal[i] = centaine(tab[0][i], tab[1][i]);

		}
		else if(tab[0][i] >= 10)
		{
			if(i == 3)
				temp = 2;
			else
				temp = 3;	

			prefinal[i] = dizaine(tab[0][i],tab[1][i] );
		}
		else
		{
			if(i == 3)
				temp = 1;
			else
				temp = 2;

			prefinal[i] = unite(tab[0][i], tab[1][i]);
		}
	i++;
	}

	ft_strcat(prefinal[0],prefinal[1],5);
	ft_strcat(prefinal[0],prefinal[2],5);
	ft_strcat(prefinal[0],prefinal[3],5);
	ft_strcat(prefinal[0],prefinal[4],5);

	return (prefinal[0]);
}
int main()
{
	int i = 0;
	while(i<20)
	{
		printf("%ln \n",concat(31851953));
	i++;
	}

	return 0;
}