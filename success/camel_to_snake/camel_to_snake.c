/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glugo-mu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:41:25 by glugo-mu          #+#    #+#             */
/*   Updated: 2025/01/30 18:53:26 by glugo-mu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int total_char = 0;
    int total_capitals = 0;
    char *result, *start;
    int i = 0, j = 0;

    if (argc != 2)
    {
	write(1, "\n", 1);
        return (1);
    }
    // Contar caracteres y mayúsculas
    while (argv[1][total_char])
    {
        if (argv[1][total_char] >= 'A' && argv[1][total_char] <= 'Z')
            total_capitals++;
        total_char++;
    }

    // Reservar memoria para la nueva cadena
    result = malloc(sizeof(char) * (total_char + total_capitals + 1));
    if (!result)
        return (1);

    start = result; // Guardamos la dirección original

    // Convertir a snake_case
    while (argv[1][i])
    {
        if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            if (i > 0) // No agregar _ si la mayúscula es la primera letra
                result[j++] = '_';
            result[j++] = argv[1][i] + 32;
        }
        else
        {
            result[j++] = argv[1][i];
        }
        i++;
    }
    result[j] = '\0'; // Agregar terminación de string

    // Imprimir resultado
    write(1, start, j);
    write(1, "\n", 1);

    // Liberar memoria correctamente
    free(start);
    return (0);
}

