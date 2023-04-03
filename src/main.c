/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:59:07 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/03 18:13:16 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>

void	ft_error(char *str)
{
	ft_putstr_fd("error", 2);
	ft_putstr_fd(str, 2);
}

int	main(int argc, char *argv[])
{
	t_args	*args;

	if (argc < 5)
		ft_error("Numbers of arguments is invalid");
	else if (argc == 5 || argc == 6)
	{
		if (!(parse_args(argc, argv, args)))
			ft_error("Type of arguments is invalid");
	}
	return (0);
}
