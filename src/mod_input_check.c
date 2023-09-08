/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_input_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 12:07:16 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/08 15:16:27 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file mod_input_check.c
 * @brief Functions to verify correctness of input parameters.
 */

#include "mod_input_check.h"

/**
 * @brief General input check handler.
 * 
 * Check for number of arguments/parameters.
 * Check for empty strings.
 * Check for characters other than numeric values.
 * @param argc 	Amout of input arguments.
 * @param argv 	Array of strings containing the arguments.
 */
void	ft_check_input(int argc, char **argv)
{
	ft_check_argc(argc);
	ft_check_empty_str(argc, argv);
	ft_check_num(argc, argv);
}

/**
 * @brief Check for correct amount of input parameters.
 * 
 * Including the program name.
 * 5: number_of_philosophers, time_to_die, time_to_eat,
 * time_to_sleep
 * 6: above + optionally number_of_times_each_philosopher_must_eat
 * @param argc 	Amout of input arguments.
 */
void	ft_check_argc(int argc)
{
	if (argc != 5 && argc != 6)
		ft_print_err_and_exit(ERR_ARGCOUNT, false, \
		"Expect 4, optionally 5 arguments. 🙄\n");
}

/**
 * @brief Check for empty string in input parameters.
 * 
 * Start from argument 1 (first parameter after program name).
 * End with argument argc - 1 (last parameter).
 * If empty string found, return err message and exit with
 * according error value.
 * @param argc 	Amout of input arguments.
 * @param argv 	Array of strings containing the arguments.
 */
void	ft_check_empty_str(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (argv[i][0] == '\0')
			ft_print_err_and_exit(ERR_EMPTYSTR, false, \
				"Empty string encountered. 🥴\n");
}

/**
 * @brief Check for characters other than numeric values in input.
 * 
 * Start from argument 1 (first parameter after program name).
 * End with argument argc - 1 (last parameter).
 * If non-numeric char found, return err message and exit with
 * according error value. 
 * @param argc 
 * @param argv 
 */
void	ft_check_num(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				ft_print_err_and_exit(ERR_NONNUMERIC, false, \
				"Input contains non-numeric characters. 👽\n");
	}
}
