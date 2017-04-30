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

#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <uuid/uuid.h>

# define CHECK_BIT(var, pos)	(var & pos)
# define L	1
# define A	2
# define R	4
# define T	8
# define RR	16

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

typedef struct dirent 	t_dir;
typedef struct stat 	t_stat;
typedef struct passwd 	t_pwd;
typedef struct group 	t_grp;


typedef struct		s_flags
{
	int				bit;
	int				l;
	int				a;
	int				r;
	int				t;
	int				rr;
}					t_flags;

typedef struct 		s_data
{
	char			*mod;
	size_t			link;
	char			*user;
	char			*group;
	long			size;
	char			*time;
	char			*name;
}					t_data;
typedef struct		s_ls
{
	t_data			data;
	struct s_ls		*next;
}					t_ls;
void	sort_list(t_ls *lst);

// int					check_sort(t_ls *lst);
void				init_flags(t_flags *f);
void				print_flags(t_flags f);
int					check_flags(char *argv, t_flags *f);

void				add_infos(t_dir *file, t_stat buf, t_ls *ls);
t_ls 				*new_lst(t_dir *file, t_stat buf);
t_ls				*add_list(t_ls *lst, t_dir *file, t_stat buf);

void			 	print_lst(t_ls *lst);
t_ls				*stock_list(t_ls *lst, t_dir *file, DIR *dir);
void				ls_simple(void);

/*
** get
*/

char				get_type(size_t n);
char				*get_time(time_t n);
char				*get_uid(unsigned int n);
char				*get_gid(unsigned int n);
char				*get_mod(t_stat buf, char type);
/*
** libft
*/

void				ft_putnbr(int n);
int					ft_isdigit(int c);
void				ft_putchar(char c);
int					tab_len(char **tab);
char				*ft_strnew(size_t size);
void				ft_free_tab(char **str);
int					ft_isdig_str(char *ptr);
int					ft_atoi(const char *str);
void				ft_putstr(char const *s);
size_t				ft_strlen(const char *s);
void				*ft_memalloc(size_t size);
char				*ft_strchr(char *s, int c);
char				*ft_strdup(const char *s1);
void				ft_bzero(void *s, size_t n);
char				**ft_strsplit(char *s, char c);
void				ft_putstr_fd(char const *s, int fd);
void				*ft_memset(void *b, int c, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strdup_color(const char *s1, char *color);


#endif
