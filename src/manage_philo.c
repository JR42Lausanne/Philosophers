/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:03:27 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/26 17:15:32 by jlaiti           ###   ########.fr       */
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
	forks = malloc(sizeof(pthread_mutex_t *) * args->nb_forks);
	if (!forks)
		return (NULL);
	while (i < args->nb_forks)
	{
		forks[i] = malloc(sizeof(pthread_mutex_t));
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
	int				start_time;
	int				i;

	i = -1;
	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	forks = init_forks(args);
	if (!forks)
		return (NULL);
	data->philo = malloc(sizeof(t_philo) * args->nb_philo);
	if (!data->philo)
		return (NULL);
	data->table = malloc(sizeof(t_table));
	if (!data->table)
		return (NULL);
	init_mutex(data->table);
	start_time = get_time();
	while (++i < args->nb_philo)
	{
		data->philo[i].nb_philo = args->nb_philo;
		data->philo[i].start_time = start_time;
		data->philo[i].id = i + 1;
		data->philo[i].nb_of_eat = 0;
		data->philo[i].time_to_eat = args->time_to_eat;
		data->philo[i].time_to_sleep = args->time_to_sleep;
		data->philo[i].left_fork = forks[i];
		data->philo[i].right_fork = forks[(i + 1) % args->nb_philo];
		data->philo[i].table = data->table;
	}
	//	TODO free forks, but only the array
	return (data);
}
