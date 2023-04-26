/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:47:03 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/26 14:43:23 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"
#include <pthread.h>

static int	philo_eat(t_philo *philo, t_table *table)
{
	int	time_stamp;

	time_stamp = get_time();
	if (pthread_mutex_lock(philo->right_fork))
		return (-1);
	if (pthread_mutex_lock(philo->left_fork))
		return (-1);
	print_msg(time_stamp, "has taken right fork\n", philo, table);
	print_msg(time_stamp, "has taken left fork\n", philo, table);
	print_msg(time_stamp, "is eating\n", philo, table);
	if (change_status(&philo->nb_of_eat, philo->nb_of_eat + 1,
				&table->mutex ) == -1)
		return (-1);
	custom_sleep(	
	if (pthread_mutex_unlock(philo->right_fork))
		return (-1);
	if (pthread_mutex_unlock(philo->left_fork))
		return (-1);
	return (0);
}

static int	philo_think(t_philo *philo, t_table *table)
{

}

void	activity(t_philo *philo, t_table *table)
{
	if (philo_eat(philo, table) == -1)
		return ;
	if (philo_think(philo, table) == -1)
		return ;



}
	
}
print_stamp(philo->t_last_meal, "is eating\n", philo);
	if (safe_var_change(&philo->eat_count, &philo->mut_count,
			philo->eat_count + 1) == -1)
		return (-1);
	custom_sleep(philo->t_last_meal + philo->info_tab->time_to[TIME_TO_EAT],
		philo->info_tab);
	if (fork_action(philo, 1) == -1)
		return (-1);
	return (0);	
