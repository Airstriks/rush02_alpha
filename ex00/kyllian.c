#include <stdlib.h>
#include <stdio.h>

int len(long nbr)
{
    int i;

    i = 0;
    while (nbr > 0)
    {
        nbr = nbr /10;
        i++;
    }
    return(i);
}

long boucle(long base)
{
    int i;
    long nb;

    i = 0;
    nb = 1;
    while (len(base) % 3 != 1)
        base = base / 10;
    while (nb *10 < base)
    {
        nb = nb *10;
        i++;
    }
    return (nb);
}
int just_centaine(int nb)
{
    int count;

    count = 0;
    while (nb > 100)
    {
        nb -= 100;
        count++;
    }
    return (count);
}

int just_dizaine(int nb)
{
    int count;

    count = 0;
    while (nb > 10)
    {
        nb -= 10;
        count++;
    }
    count *= 10;
    return (count);
}

long *centaine(int nb, long base)
{
    int count;
    long *tab;

    count = 0;
    tab = malloc(sizeof(long) * 5);
    if (tab == NULL)
        return (NULL);
    tab[0] = just_centaine(nb);
    nb = nb % 100;
    tab[1] = 100;
    tab[2] = just_dizaine(nb);
    nb = nb % 10;
    count = 0;
    while (nb != 0)
    {
        nb -= 1;
        count++;
    }
    tab[3] = count;
    tab[4]= boucle(base);
    return (tab);
}

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

long ft_power(long nb, long power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	else
	{
		return (nb * ft_power(nb, power - 1));
	}	
}

long	nblen(long nb)
{
	long	count;

	count = 0;
	while(nb!=0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

long	frstparam(long res, long *len, long nb)
{
	if(res == 0){
		*len -= 3;
		nb = (nb/(ft_power(10,*len)));
	}
	if(res == 1){
		*len -= 1;
		nb = (nb/(ft_power(10,*len)));
	}
	if(res == 2){
		*len -= 2;
		nb = (nb/(ft_power(10,*len)));
	}

	return (nb);	
}

long	*concat(long nb)
{
	long a;
	long size;
	long len;
	long tmp;
	int flag;
	long *final;
	int i = 0;

	final = malloc(20*sizeof(char));
	len = nblen(nb);
	flag = 0;
	while (i<4)
	{
		
		a = len % 3;

		tmp = frstparam(a, &len, nb); //on va checher si le mod est 0,1,2, on modif la taille en fonction et on isole.


		if (a == 0){
			if (flag == 0)		// si c'est le premier passage.
			{
				size = 5;
				flag = 1;
				final = centaine(tmp,nb);	// on met le resultat de la fonction dans final
				nb = nb - (tmp*ft_power(10,len));	// on soustrait le block a nb (si tmp = 89 et nb 89500, et bien nb =500)
			}
			else				// si c'est le deuxieme passage.
			{

				ft_strcat(final, centaine(tmp,nb),size);	// vu que c'est le deuxieme passage, on sait qu'on doit concatener
				nb = nb - (tmp*ft_power(10,len));			// on retire le block a nb.
				size = 5;					
				flag = 0;
			}
		}

	i++;
		//printf("final : %ln \n tmp = %ld",final, tmp);
		/*if (a == 1){
			if (flag == 0)
			{
				size = 2;
				flag = 1;
				final = unite(tmp,nb);
				nb = nb - (tmp*ft_power(10,len));
			}
			else
			{

				ft_strcat(final, unite(tmp,nb),size);
				nb = nb - (tmp*ft_power(10,len));
				size = 2;
				flag = 0;
			}		
		}
		if (a == 2){
			if (flag == 0)
			{
				size = 3;
				flag = 1;
				final = dizaine(tmp,nb);
				nb = nb  - (tmp*ft_power(10,len));
			}
			else
			{

				ft_strcat(final, dizaine(tmp,nb),size);
				nb = nb - (tmp*ft_power(10,len));
				size = 3;
				flag = 0;
			}			
		}*/
	}

	return(final);
}

int main()
{
	long nb=189756891;

	int i = 0;

	while(i < 20)
	{
		printf("%ln \n", concat(nb));
	}
	return 0;
}