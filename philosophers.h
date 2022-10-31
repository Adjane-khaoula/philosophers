/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:30:58 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/31 23:10:30 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	int				i;
	int				nbr_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				nbr_time_each_philo_eat;
	int				last_time_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	last_eat;
	int				start_time;
}	t_data;

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	pthread_mutex_t	is_eat;
	t_data			*data;
}	t_philo;

int		ft_atoi(char *str);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
void	eat(t_philo *philosopher);
// int		eat(t_philo *philosopher);
void	ft_sleep(t_philo *philosopher);
void	think(t_philo *philosopher);
int		get_time(t_data *data);
void	ft_usleep(int time, t_philo *philosopher);
void	ft_sleep_think(t_philo *philosopher);

#endif