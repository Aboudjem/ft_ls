/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboudjem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 00:27:36 by aboudjem          #+#    #+#             */
/*   Updated: 2017/04/21 02:03:00 by aboudjem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <dirent.h>

# define CHECK_BIT(var, pos)	(var & pos)
# define L	1
# define A	2
# define R	4
# define T	8
# define RR	16
# define FINISH 32
# define PRINT	64

# define BUFF_SIZE 20

# define STOP      	"\033[0m"
# define BOLD       "\033[1m"
# define ITALIC     "\033[3m"
# define UNDERLINE  "\033[4m"
# define BLACK   	"\033[30m"
# define RED     	"\033[31m"
# define GREEN   	"\033[32m"
# define YELLOW  	"\033[33m"
# define BLUE   	"\033[34m"
# define MAGENTA 	"\033[35m"
# define CYAN    	"\033[36m"
# define WHITE   	"\033[37m"

typedef struct		s_flags
{
	int				bit;
	int				l;
	int				a;
	int				r;
	int				t;
	int				rr;
}					t_flags;

void				print_flags(t_flags f);
int					check_flags(char *argv, t_flags *f);

/*
** libft
*/
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				ft_free_tab(char **str);
int					ft_isdigit(int c);
int					ft_isdig_str(char *ptr);
void				*ft_memalloc(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar(char c);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_strchr(char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
char				**ft_strsplit(char *s, char c);
int					tab_len(char **tab);

#endif
