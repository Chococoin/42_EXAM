/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:13:58 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/31 18:59:32 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	start;
	int	end;

	if (argc == 2)
	{
		start = 0;
		end = 0;
		while (argv[1][start] == ' ' || argv[1][start] == '\t')
			start++;
		while (argv[1][end])
			end++;
		end--;
		while (argv[1][end] == ' ' || argv[1][end] == '\t')
			end--;
		while (start <= end)
		{
			if (argv[1][start] != ' ')
			{
				write(1, &argv[1][start], 1);
				start++;
			}
			else if (argv[1][start] == ' ')
			{
				write(1, "   ", 3);
				start++;
				while(argv[1][start] == ' ')
					start++;
			}	
		}  
	}
	write(1, "\n", 1);
	return (0);
}
