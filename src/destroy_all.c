/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:10:39 by jlaiti            #+#    #+#             */
/*   Updated: 2023/05/02 16:29:22 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdlib.h>

void	destroy_all(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo->nb_philo)
	{
		pthread_mutex_destroy(&data->philo->left_fork[i]);
		free(&data->philo->left_fork[i]);
		pthread_mutex_destroy(&data->philo->right_fork[i]);
		free(&data->philo->right_fork[i]);
		pthread_mutex_destroy(&data->philo->local_mutex[i]);
		//free(&data->philo->local_mutex[i]);
		i++;
	}
	//free(&data->philo->left_fork);
//	free(&data->philo->right_fork);
//	free(&data->philo->local_mutex);
	pthread_mutex_destroy(&data->table->write_mutex);
	pthread_mutex_destroy(&data->table->mutex_stop);
	pthread_mutex_destroy(&data->table->mutex_die);
	//free(data->table);
	//free(data->philo);
	//free(data);
}
