/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iez-zagh <iez-zagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:53:32 by iez-zagh          #+#    #+#             */
/*   Updated: 2024/08/24 18:11:09 by iez-zagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	free_philo(t_philo *philo, int n)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	while (philo && i++ < n)
	{
		tmp = philo;
		philo = philo->next;
		free(tmp);
	}
}

void	ft_free(t_data *st)
{
	free_philo(st->s_philo, st->philo_n);
}
