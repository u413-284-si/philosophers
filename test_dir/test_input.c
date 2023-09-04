/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sqiu <sqiu@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:50:01 by sqiu              #+#    #+#             */
/*   Updated: 2023/09/04 10:56:23 by sqiu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static int	str_occ(char const *s, char c);
static char	*get_str(char const *s, char c);
static char	**fill_arr(char **arr, char const *s, char c, int str_count);

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	if (c > 255)
		c -= 256 * (c / 256);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((void *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((void *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		str_count;

	if (!s)
		return (NULL);
	str_count = str_occ(s, c);
	arr = malloc (sizeof(char *) * (str_count + 1));
	if (!arr)
		return (NULL);
	arr = fill_arr(arr, s, c, str_count);
	return (arr);
}

static char	**fill_arr(char **arr, char const *s, char c, int str_count)
{
	char	*tmp;
	int		i;
	size_t	j;

	i = -1;
	while (++i < str_count)
	{
		tmp = get_str(s, c);
		arr[i] = (char *) malloc (sizeof(char) * (ft_strlen(tmp) + 1));
		if (!arr[i])
			return (NULL);
		j = -1;
		while (++j < ft_strlen(tmp))
			arr[i][j] = tmp[j];
		arr[i][j] = '\0';
		if (!(i == str_count - 1))
		{
			while (*s == c)
				s++;
			s += ft_strlen(tmp) + 1;
		}
		free(tmp);
	}
	arr[i] = NULL;
	return (arr);
}

static int	str_occ(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] == c && s[j + 1] != c && s[j + 1] != '\0')
			i++;
		if (s[j] != c && i == 0)
			i++;
		j++;
	}
	return (i);
}

static char	*get_str(char const *s, char c)
{
	char	*tmp;
	char	*str;
	int		len;
	int		i;

	while (*s == c)
		s++;
	tmp = ft_strchr(s, c);
	if (!tmp)
		len = ft_strlen(s);
	else
		len = tmp - s;
	str = (char *) malloc (sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = *s++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static void	ft_cleanup(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	test_wrapper(char *title, int argc, char *input)
{
	char	**argv;
	t_input	params;

	argv = ft_split(input, ' ');
	ft_setup(argc, argv, &params);
	printf("=== %s ===\n\n", title);
	printf("Num_philos: %d\n", params.num_philos);
	printf("Time_to_die: %d\n", params.time_to_die);
	printf("Time_to_eat: %d\n", params.time_to_eat);
	printf("Time_to_sleep: %d\n", params.time_to_sleep);
	if (argc == 6)
		printf("Req_meals: %d\n", params.req_meals);
	ft_cleanup(argv);
}

void	test_input(void)
{
	test_wrapper("Zero values", 5, "./philo 0 200 100 100");
}
