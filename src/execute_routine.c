/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:19:39 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/27 11:00:03 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int	check_is_alive(int *var, pthread_mutex_t *mutex)
{
	int	ret;

	if (pthread_mutex_lock(mutex))
		return (-1);
	ret = *var;
	if (pthread_mutex_unlock(mutex))
		return (-1);
	return (ret);
}

int	change_status(int *var, int new_var, pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex))
		return (-1);
	*var = new_var;
	if (pthread_mutex_unlock(mutex))
		return (-1);
	return (0);
}

static void	*thread_routine(void *data)
{
	t_philo	*philo;
	t_table	*table;

	philo = data;
	table = philo->table;
	printf("philo %d started at %d\n", philo->id, get_time());
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!check_is_alive(&table->stop, &table->mutex))
	{
		activity(philo, table);
	}
	printf("philo %d finished at %d\n", philo->id, get_time());
	return (NULL);
}

void	execute_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo[0].nb_philo)
	{
		if (pthread_create(&data->philo[i].philo_thread,
				NULL, thread_routine, &data->philo[i]) != 0)
			return ;
		i++;
	}
}
