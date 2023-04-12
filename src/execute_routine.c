/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:19:39 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/12 11:52:44 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static void	*thread_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *) data;
	pthread_mutex_lock(philo->left_fork);
	pthread_mutex_lock(philo->right_fork);
	usleep(philo->time_to_eat);
	philo->start_time += philo->time_to_eat;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (NULL);
}

void	execute_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->id)
	{
		if (pthread_create(&philo[i].philo_thread,
				NULL, thread_routine, &philo[i]) == -1)
			return ;
		i++;
	}
}
