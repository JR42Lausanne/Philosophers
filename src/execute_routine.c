/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:19:39 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/25 15:06:13 by jlaiti           ###   ########.fr       */
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

	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (!check_is_alive()

	return ;
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
