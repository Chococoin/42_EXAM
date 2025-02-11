/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:54:13 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/31 18:11:40 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int 	start;
	int	end;

	start = 0;
	end = 0;
	if (argc == 2)
	{
		while (argv[1][end])
			end++;
		end--;
		while (argv[1][end] == ' ' || argv[1][end] == '\t')
			end--;
		start = end;
		while (argv[1][start] != ' ' && argv[1][start] != '\t')
			start--;
		start++;
		while (start <= end)
			write(1, &argv[1][start++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
