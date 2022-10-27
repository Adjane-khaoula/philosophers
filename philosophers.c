/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:35:24 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/27 19:17:36 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// void	*routine(void *arg)
// {
	
// }

// void	create_philosophers(data_t *data)
// {
// 	if(pthread_create(&(data->philo), NULL, &routine, data) != 0)
// 		return ;
// 	pthread_join(data->philo, NULL);
// }

int main(int ac, char **av)
{
	 struct timeval current_time;
	(void)av;
	(void)ac;
	// data_t	*data;

	// if (ac == 5)
	// {
	// 	while (--ac)
	// 	{
	// 		if (ft_atoi(av [ac]) == -1)
	// 		{
	// 			ft_putstr("check you parameters");
	// 			return(0);
	// 		}
	// 	}
	// 	data->i = 0;
	// 	data->nbr_of_philo= ft_atoi(av[1]);
	// 	data->time_to_die = ft_atoi(av[2]);
	// 	data->time_to_eat = ft_atoi(av[3]);
	// 	data->time_to_sleep = ft_atoi(av[4]);
	// 	pthread_mutex_init(&(data->mtx), NULL);
	// 	create_philosophers(data);
	// }
	// else
	// {
	// 	ft_putstr("check you parameters");
	// 	return (0);
	// }
	gettimeofday(&current_time, NULL);
	  printf("seconds : %ld\nmicro seconds : %d",current_time.tv_sec, current_time.tv_usec);
}