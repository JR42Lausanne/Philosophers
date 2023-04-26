/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:03:27 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/26 14:22:50 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static pthread_mutex_t	**init_forks(t_args *args)
{
	pthread_mutex_t	**forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(pthread_mutex_t) * args->nb_forks);
	if (!forks)
		return (NULL);
	while (i < args->nb_forks)
	{
		if (pthread_mutex_init(forks[i], NULL))
			return (NULL);
		i++;
	}
	return (forks);
}

static	void	init_mutex(t_table	*table)
{
	if (pthread_mutex_init(&table->write_mutex, NULL))
		return ;
	if (pthread_mutex_init(&table->mutex, NULL))
		return ;
	table->stop = 0;
}

t_data	*manage_philo(t_args	*args)
{
	t_data			*data;
	pthread_mutex_t	**forks;
	int				i;

	i = -1;
	data = malloc(sizeof(t_philo) * args->nb_philo);
	if (!data)
		return (NULL);
	forks = init_forks(args);
	if (!forks)
		return (NULL);
	data->philo->start_time = get_time();
	init_mutex(data->table);
	while (++i < args->nb_philo)
	{
		data->philo[i].id = i + 1;
		data->philo[i].nb_of_eat = 0;
		data->philo[i].time_to_eat = args->time_to_eat;
		data->philo[i].time_to_sleep = args->time_to_sleep;
		data->philo[i].left_fork = forks[i];
		data->philo[i].right_fork = forks[(i + 1) % args->nb_philo];
	}
	//	TODO free forks, but only the array
	return (data);
}
