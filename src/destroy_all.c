/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:10:39 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/03 11:46:23 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdlib.h>

void	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo[0].nb_philo)
	{
		pthread_mutex_destroy(data->philo[i].left_fork);
		free(data->philo[i].left_fork);
		pthread_mutex_destroy(data->philo[i].local_mutex);
		free(data->philo[i].local_mutex);
		i++;
	}
	pthread_mutex_destroy(&data->table->write_mutex);
	pthread_mutex_destroy(&data->table->mutex_stop);
	pthread_mutex_destroy(&data->table->mutex_die);
	free(data->table);
	free(data->philo);
	free(data);
}
