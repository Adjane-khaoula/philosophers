/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:30:58 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/28 16:02:05 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct data_s
{
	int				nbr_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				nbr_time_each_philo_eat;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
}	data_t;

typedef struct philo_s
{
	pthread_t		philo;
	int				id;
	pthread_mutex_t	last_eat;
	pthread_mutex_t	is_eat;
	data_t			*data;
}	philo_t;

int		ft_atoi(char *str);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);

#endif