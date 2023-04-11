/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 10:19:39 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/11 18:10:20 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	*thread_routine(void *data)
{
	(void) data;
}

void	execute_philo(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->id)
	{
		philo[i].id = pthread_create(&philo->philo_thread,
				NULL, thread_routine, NULL);
		i++;
	}
}
