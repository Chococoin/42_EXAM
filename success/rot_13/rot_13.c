/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:30:26 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/30 17:38:30 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	int	i;
	char	c;

	if (argc != 2 || !argv[1][0])
	{
		write(1, "\n", 1);
		return 0;
	}
	i = 0;
	while(argv[1][i])
	{
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')	
			c = ((argv[1][i] - 'a' + 13) % 26) + 'a';
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			c = ((argv[1][i] - 'A' + 13) % 26) + 'A';
		else
			c = argv[1][i];
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
