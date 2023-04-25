/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaiti <jlaiti@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:57:05 by jlaiti            #+#    #+#             */
/*   Updated: 2023/04/25 15:04:49 by jlaiti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define INTMAX +2147483647
# define INTMIN -2147483648

typedef struct s_args
{
	int	nb_philo;
	int	nb_forks;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	nb_of_loop_philo;
}			t_args;

typedef struct s_philo
{
	int				id;
	int				time_to_eat;
	int				time_to_sleep;
	int				start_time;
	pthread_t		philo_thread;
	pthread_t		id_philo_die;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	long int		last_meal;
	int				nb_of_eat;
}				t_philo;

typedef struct s_table
{
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	is_alive;
	int				stop;
	t_philo			*all_philo;
}				t_table;

t_philo		*manage_philo(t_args	*args);
int			parse_args(char **argv, t_args *args, int argc);
void		execute_philo(t_philo *philo);
int			check_is_alive(int *var, pthread_mutex_t *is_alive);	

//utils
int			ft_error(char *str);
void		ft_puchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
int			ft_atoi(char *str);
int			get_time(void);

#endif
