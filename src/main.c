/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:59:07 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/04 11:44:05 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>

void	ft_error(char *str)
{
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(str, 2);
}

int	main(int argc, char *argv[])
{
	t_args	*args;

	args = NULL;
	if (argc < 5)
		ft_error("Numbers of arguments is invalid\n");
	else if (argc == 5 || argc == 6)
	{
		if (!(parse_args(argv, args)))
			ft_error("Type of arguments is invalid");
	}
	return (0);
}
