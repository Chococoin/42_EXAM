/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:16:35 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/31 13:45:47 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

char	*ft_itoa(int nbr)
{
	int	temp;
	int	len;
	int	is_negative;
	char	*result;

	len = 0;
	is_negative = 0;
	if (nbr == 0)
		return ("0");
	if (nbr < 0)
	{
		is_negative = 1;
		nbr = -nbr;
		len++;
	}
	
	temp = nbr;	
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);

	result[len] = '\0';

	while (nbr)
    	{
        	result[--len] = (nbr % 10) + '0';
        	nbr /= 10;
    	}	

    	if (is_negative)
        	result[0] = '-';

    	return (result);
}

