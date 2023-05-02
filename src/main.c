/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:59:07 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/02 13:01:15 by jlaiti           ###   ########.fr       */
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

static void	join_all_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo[0].nb_philo)
	{
		if (pthread_join(data->philo[i].philo_thread, NULL))
			return ;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_args		args;
	t_data		*data;
	pthread_t	manager_id;

	if ((argc < 5) || (argc > 6))
		ft_error("Numbers of arguments is invalid\n");
	else if (argc == 5 || argc == 6)
	{
		if (!(parse_args(argv, &args, argc)))
		{
			ft_error("Type of arguments is invalid\n");
			return (-1);
		}
		data = manage_philo(&args);
		execute_philo(data);
		if (pthread_create(&manager_id, NULL, handle_philo, data))
			return (-1);
		if (pthread_join(manager_id, NULL))
			return (-1);
		join_all_philos(data);
	}
	return (0);
}
