/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:47:03 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/27 11:10:01 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>
#include <stdio.h>

static int	philo_eat(t_philo *philo, t_table *table)
{
	if (pthread_mutex_lock(philo->right_fork))
		return (-1);
	print_msg(get_time(), "has taken right fork\n", philo, table);
	if (pthread_mutex_lock(philo->left_fork))
		return (-1);
	print_msg(get_time(), "has taken left fork\n", philo, table);
	print_msg(get_time(), "is eating\n", philo, table);
	if (change_status(&philo->nb_of_eat, philo->nb_of_eat + 1,
			&table->mutex) == -1)
		return (-1);
	if (change_status(&philo->last_meal, get_time(),
			&table->mutex) == -1)
		return (-1);
	custom_sleep(philo->time_to_eat, table);
	if (pthread_mutex_unlock(philo->right_fork))
		return (-1);
	if (pthread_mutex_unlock(philo->left_fork))
		return (-1);
	return (0);
}

static int	philo_think(t_philo *philo, t_table *table)
{
	int	time_stamp;

	time_stamp = get_time();
	print_msg(time_stamp, "is sleeping\n", philo, table);
	custom_sleep(philo->time_to_sleep, table);
	return (0);
}

void	activity(t_philo *philo, t_table *table)
{
	if (philo_eat(philo, table) == -1)
		return ;
	if (check_is_alive(&table->stop, &table->mutex))
		return ;
	if (philo_think(philo, table) == -1)
		return ;
	if (check_is_alive(&table->stop, &table->mutex))
		return ;
	print_msg(get_time(), "is thinking\n", philo, table);
}
