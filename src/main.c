/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:59:07 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/11 16:41:36 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_error(char *str)
{
	ft_putstr_fd("error: ", 2);
	ft_putstr_fd(str, 2);
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_args	args;
	t_philo	*philo;

	if ((argc < 5) || (argc > 6))
		ft_error("Numbers of arguments is invalid\n");
	else if (argc == 5 || argc == 6)
	{
		if (!(parse_args(argv, &args, argc)))
			ft_error("Type of arguments is invalid");
		philo = manage_philo(&args);
		execute_philo(philo);
	}
	return (0);
}
