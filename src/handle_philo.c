/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:43:50 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/02 11:56:03 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>
#include <limits.h>

void	*handle_philo(void *arg)
{
	t_data	*data;
	int		i;
	int		philo_tt_die;
	int		last_meal;
	int		min_nb_of_eat;

	data = arg;
	while (!check_is_alive(&data->table->stop, &data->table->mutex_stop))
	{
		i = 0;
		min_nb_of_eat = INT_MAX;
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
					&data->table->mutex_stop);
				if (pthread_mutex_unlock(&data->table->mutex_die))
					return (NULL);
			}
			pthread_mutex_lock(data->philo[i].local_mutex);
			if (data->philo[i].nb_of_eat < min_nb_of_eat)
				min_nb_of_eat = data->philo[i].nb_of_eat;
			pthread_mutex_unlock(data->philo[i].local_mutex);
			i++;
		}
		if (min_nb_of_eat >= data->table->philo_loop
			&& data->table->philo_loop != -1)
		{
			print_msg(0, "All the philosophers have eaten enough time", NULL, data->table);
			change_status(&data->table->stop, 1,
				&data->table->mutex_stop);
		}
	}
	return (NULL);
}
