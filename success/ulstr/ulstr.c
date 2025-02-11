/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:22:42 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/31 16:52:35 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int	i;
	char 	c;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{	
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				c = argv[1][i] - 32;
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				c = argv[1][i] + 32;
			else
				c = argv[1][i];
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
