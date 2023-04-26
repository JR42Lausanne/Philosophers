/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:19:39 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/26 11:02:51 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int	check_is_alive(int *var, pthread_mutex_t *is_alive)
{
	int	ret;

	if (pthread_mutex_lock(is_alive))
		return (-1);
	ret = *var;
	if (pthread_mutex_unlock(is_alive))
		return (-1);
	return (ret);
}

static void	*thread_routine(void *data)
{
	t_philo	*philo;
	t_table	*table;

	table = (t_table *)data;
	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!check_is_alive(&table->stop, &table->is_alive))
	{
		activity(philo, table);
	}
}

void	execute_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo->id)
	{
		if (pthread_create(&data->philo[i].philo_thread,
				NULL, thread_routine, &data->philo[i]) == -1)
			return ;
		i++;
	}
}
