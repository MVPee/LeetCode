/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvpee <mvpee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:45:11 by mvan-pee          #+#    #+#             */
/*   Updated: 2024/01/31 15:04:56 by mvpee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <libc.h>

static int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static void	ft_int_to_char(unsigned int number, char *nbr, int i)
{
	while (number > 0)
	{
		nbr[i] = '0' + (number % 10);
		number /= 10;
		i--;
	}
}

static char	*ft_itoa(int n)
{
	int				i;
	char			*nbr;
	unsigned int	number;

	i = ft_int_len(n);
	nbr = (char *)malloc(sizeof(char) * (i + 1));
	if (!nbr)
		return (NULL);
	nbr[i--] = '\0';
	if (n == 0)
		nbr[0] = '0';
	if (n < 0)
	{
		nbr[0] = '-';
		number *= n;
	}
	else
		number = n;
	ft_int_to_char(number, nbr, i);
	return (nbr);
}

bool isPalindrome(int x)
{
    char *str;
    int i;

    str = ft_itoa(x);
    i = -1;
    while(++i < strlen(str))
        if (str[i] != str[strlen(str) - i - 1])
            return (false);
    return (true);
}

int main(void)
{
    printf("%d\n", isPalindrome(-2147483648));
    return (0);
}