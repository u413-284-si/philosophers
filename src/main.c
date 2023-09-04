/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 19:35:18 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/04 18:21:03 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.c
 * @brief Contains initial thread executing the main routine.
 */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_input	params;
	t_meta	data;

	ft_check_input(argc, argv);
	ft_setup(argc, argv, &params, &data);
/* 	ft_feast();
	if (philo == dead)
		printf("Another one bites the dust\n");
	else if (philo == fed)
		printf("Ich bin so satt, ich mag kein Blatt\n");
	ft_cleanup(); */
	return (0);
}
