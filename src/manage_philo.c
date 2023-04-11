/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:03:27 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/11 17:54:43 by jlaiti           ###   ########.fr       */
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
		pthread_mutex_init(forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	*manage_philo(t_args	*args)
{
	t_philo			*philo;
	pthread_mutex_t	**forks;
	int				i;

	i = 0;
	philo = malloc(sizeof(t_philo) * args->nb_philo);
	if (!philo)
		return (NULL);
	forks = init_forks(args);
	if (!forks)
		return (NULL);
	while (i < args->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].nb_of_eat = 0;
		philo[i].time_to_eat = args->time_to_eat;
		philo[i].time_to_sleep = args->time_to_sleep;
		philo[i].start_time = get_time();
		philo[i].left_fork = forks[i];
		philo[i].right_fork = forks[(i + 1) % args->nb_philo];
		i++;
	}
	//	TODO free forks, but only the array
	return (philo);
}
