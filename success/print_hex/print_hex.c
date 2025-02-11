/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:19:18 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/31 13:11:44 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char const *ptr)
{
	int	result;
	int	sign;
	
	sign = 1;
	result = 0;
	while (*ptr == ' ' || (*ptr >= 9 && *ptr <= 13))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign = -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
	{
		result = result * 10 + (*ptr - '0');
		ptr++;
	}
	return (result * sign);	
}

void	dec_to_hex(int const dec)
{
	char hex_digit[] = "0123456789abcdef";
	if (dec >= 16)
		dec_to_hex(dec/16);
	write(1, &hex_digit[dec % 16], 1);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int number = ft_atoi(argv[1]);
		dec_to_hex(number);
	}
	write(1, "\n", 1);
	return (0);
}

