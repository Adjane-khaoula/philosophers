/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:30:58 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/27 18:50:40 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include <sys/time.h>

typedef struct data_s
{
	int				i;
	pthread_t		philo;
	pthread_mutex_t	mtx;
	int				nbr_of_philo;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				nbr_time_each_philo_eat;
}data_t;

int	ft_atoi(char *str);
void	ft_putstr(char *str);
int	ft_strlen(char *str);
int	ft_strcmp(char *s1, char *s2);

#endif