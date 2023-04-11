/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:03:27 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/11 11:03:38 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void	manage_philo(t_args	*args)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = malloc(sizeof(t_philo) * args->nb_philo);
	if (!philo)
		return ;
	while (i < args->nb_philo)
	{
		philo[i].id = i + 1;
		philo[i].id_philo = philo->id;
		philo[i].nb_of_eat = 0;
		philo[i].time_to_eat = args->time_to_eat;
		philo[i].time_to_sleep = args->time_to_sleep;
		philo[i].start_time = get_time();
		philo[i].left_fork = philo->id->left_fork;
		philo[i].right_fork = philo[i + 1].right_fork;
		i++;
	}
	execute_philo(philo);
}
