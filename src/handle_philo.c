/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:43:50 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/01 16:41:56 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>

void	*handle_philo(void *arg)
{
	t_data	*data;
	int		i;
	int		philo_tt_die;
	int		last_meal;

	data = arg;
	while (!check_is_alive(&data->table->stop, &data->table->mutex_alive))
	{
		i = 0;
		while (i < data->philo[0].nb_philo)
		{
			pthread_mutex_lock(data->philo[i].local_mutex);
			philo_tt_die = data->philo[i].philo_alive;
			last_meal = data->philo[i].last_meal;
			pthread_mutex_unlock(data->philo[i].local_mutex);
			if (get_time() - last_meal >= philo_tt_die)
			{
				if (pthread_mutex_lock(&data->table->mutex_die))
					return (NULL);
				print_msg(get_time(), "died\n", data->philo, data->table);
				change_status(&data->table->stop, 1,
					&data->table->mutex_status);
				if (pthread_mutex_unlock(&data->table->mutex_die))
					return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}
