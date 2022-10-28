/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:35:24 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/28 16:23:38 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *philosophers)
{
	philo_t	*philosopher;

	philosopher = (philo_t *)philosophers;
	if(pthread_mutex_lock(&(philosopher->data->forks[philosopher->id])) == 0 &&
		pthread_mutex_lock(&(philosopher->data->forks[(philosopher->id + 1)
						% philosopher->data->nbr_of_philo])) == 0)
				{
					printf("%d is eating",philosopher->id);
					sleep(1);
				}
	// pthread_mutex_unlock(&(philosopher->data->forks[philosopher->id]));
	// pthread_mutex_unlock(&(philosopher->data->forks[(philosopher->id + 1)
	// 					% philosopher->data->nbr_of_philo]));
	return(0);
}

void	create_philosophers(philo_t *philosophers,data_t *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_of_philo)
	{
		pthread_mutex_init(&(data->forks[i]),NULL);
		philosophers[i].id = i + 1;
		philosophers[i].data = data;
		if (pthread_create(&(philosophers[i].philo), NULL, &routine, &(philosophers[i])) != 0)
			return ;
		if(pthread_join(philosophers[i].philo, NULL))
			return ;
	}
}

int main(int ac, char **av)
{
	// struct timeval current_time;
	data_t	*data;
	philo_t	*philosophers;
	
	if (ac == 5)
	{
		while (--ac)
		{
			if (ft_atoi(av [ac]) == -1)
			{
				ft_putstr("check you parameters");
				return(0);
			}
		}
		data = malloc(sizeof(data_t));
		data->nbr_of_philo= ft_atoi(av[1]);
		data->time_to_die = ft_atoi(av[2]);
		data->time_to_eat = ft_atoi(av[3]);
		data->time_to_sleep = ft_atoi(av[4]);
		philosophers = malloc(sizeof(philo_t ) * (data->nbr_of_philo));
		data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philo);
		create_philosophers(philosophers, data);
	}
	else
	{
		ft_putstr("check you parameters");
		return (0);
	}
	// gettimeofday(&current_time, NULL);
	//   printf("seconds : %ld\nmicro seconds : %d",current_time.tv_sec, current_time.tv_usec);
}