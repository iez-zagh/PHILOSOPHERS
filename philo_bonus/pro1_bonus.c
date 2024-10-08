/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads1_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:06:59 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/24 18:16:43 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_usleep(useconds_t time)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(100);
	return (0);
}

size_t	get_time(void)
{
	struct timeval	the_time;

	gettimeofday(&the_time, NULL);
	return ((the_time.tv_sec * 1000) + (the_time.tv_usec / 1000));
}

sem_t	*create_semaphore(int i)
{
	int		j;
	sem_t	*sem1;

	j = 0;
	sem_unlink("/sema2");
	sem1 = sem_open("/sema2", O_CREAT, 0644, i);
	if (sem1 == SEM_FAILED)
		return (write(2, "problem in semaphore creation\n", 31), NULL);
	return (sem1);
}
