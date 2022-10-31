/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:35:24 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/31 23:09:52 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	*routine(void *philosophers)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)philosophers;
	// while(1)
	// {
		eat(philosopher);
		ft_sleep_think(philosopher);
	// }
	return(0);
}

void	create_philosophers(t_philo *philosophers,t_data *data)
{
	int	i;
	struct timeval	current_time;

	i = -1;
	gettimeofday(&current_time, NULL);
	pthread_mutex_init(&(data->print), NULL);
	pthread_mutex_init(&(data->last_eat), NULL);
	data->start_time = (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
	while (++i < data->nbr_of_philo)
	{
		pthread_mutex_init(&(data->forks[i]),NULL);
		philosophers[i].id = i + 1;
		philosophers[i].data = data;
	}
	i = -1;
	while(++i < data->nbr_of_philo)
	{
		if (pthread_create(&(philosophers[i].philo), NULL, &routine, &(philosophers[i])) != 0)
			return ;
		usleep(50);
	}
	i = -1;
	while(++i < data->nbr_of_philo)
	{
		if(pthread_join(philosophers[i].philo, NULL) !=0)
			return ;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philosophers;
	
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
		data = malloc(sizeof(t_data));
		data->nbr_of_philo= ft_atoi(av[1]);
		data->time_to_die = ft_atoi(av[2]);
		data->time_to_eat = ft_atoi(av[3]);
		data->time_to_sleep = ft_atoi(av[4]);
		philosophers = malloc(sizeof(t_philo) * (data->nbr_of_philo));
		data->forks = malloc(sizeof(pthread_mutex_t) * data->nbr_of_philo);
		data->last_time_eat = 0;
		create_philosophers(philosophers, data);
	
		// while (1)
		// {
		// 	if(data->last_time_eat > data->time_to_die)
		// 		return (0);
		// }
	}
	else
	{
		ft_putstr("check you parameters");
		return (0);
	}
}