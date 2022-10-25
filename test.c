/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadjane <kadjane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:44:50 by kadjane           #+#    #+#             */
/*   Updated: 2022/10/25 12:26:05 by kadjane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include <pthread.h>

void	*routine()
{
	printf("test test \n");
	return(NULL) ;
}

int main()
{
	pthread_t	t, t1;
	if(pthread_create(&t, NULL, &routine, NULL) != 0)
		return 1;
	pthread_create(&t1, NULL, &routine, NULL);
	pthread_join(t, NULL);
	pthread_join(t1, NULL);
	return (0);
}