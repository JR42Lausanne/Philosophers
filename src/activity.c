/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:47:03 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/26 12:11:15 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>



static int	philo_eat(t_philo *philo, t_table *table)
{
	int	start_time;

	start_time = get_time();
	if (pthread_mutex_lock(philo->right_fork))
		return (-1);
	if (pthread_mutex_lock(philo->left_fork))
		return (-1);
	print_msg(start
}

void	activity(t_philo *philo, t_table *table)
{
	if (philo_eat(philo, table) == -1)
		return ;



}

{
	pthread_mutex_lock(&ph->l_f);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	if (!ph->r_f)
	{
		ft_usleep(ph->pa->die * 2);
		return ;
	}
	pthread_mutex_lock(ph->r_f);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("has taken a fork\n", ph);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	pthread_mutex_lock(&ph->pa->write_mutex);
	write_status("is eating\n", ph);
	pthread_mutex_lock(&ph->pa->time_eat);
	ph->ms_eat = actual_time();
	pthread_mutex_unlock(&ph->pa->time_eat);
	pthread_mutex_unlock(&ph->pa->write_mutex);
	ft_usleep(ph->pa->eat);
	pthread_mutex_unlock(ph->r_f);
	pthread_mutex_unlock(&ph->l_f);
	sleep_think(ph);
}
