#include "ft_ls.h"

char	*get_mod(struct stat buf, char type)
{
	char *s;

	if(!(s = ft_strnew(10)))
		exit (0);
	s[0] = type;
	s[1] = (S_IRUSR & buf.st_mode) ? 'r' : '-';
	s[2] = (S_IWUSR & buf.st_mode) ? 'w' : '-';
	s[3] = (S_IXUSR & buf.st_mode) ? 'x' : '-';
	s[4] = (S_IRGRP & buf.st_mode) ? 'r' : '-';
	s[5] = (S_IWGRP & buf.st_mode) ? 'w' : '-';
	s[6] = (S_IXGRP & buf.st_mode) ? 'x' : '-';
	s[7] = (S_IROTH & buf.st_mode) ? 'r' : '-';
	s[8] = (S_IWOTH & buf.st_mode) ? 'w' : '-';
	s[9] = (S_IXOTH & buf.st_mode) ? 'x' : '-';
	return (s);
}

char	get_type(size_t n)
{
if (n == DT_BLK)
	return('-');
else if (n == DT_CHR)
	return('-');
else if (n == DT_DIR)
	return('d');
else if (n == DT_FIFO)
	return('-');
else if (n == DT_LNK)
	return('l');
else if (n == DT_REG)
	return('-');
else if (n == DT_SOCK)
	return('-');
else if (n == DT_UNKNOWN)
	return('-');
return(0);
}

char	*get_uid(unsigned int n)
{
	t_pwd uid;

	uid = *getpwuid(n);
	return(uid.pw_name);
}

char	*get_gid(unsigned int n)
{
	t_grp gid;

	gid = *getgrgid(n);
	return(gid.gr_name);
}

char	*get_time(time_t n)
{
	char	*time;
	size_t		i;

	time = ctime(&n);
	i = ft_strlen(time) - 1;
	while(time[i] != ':')
		i--;
	time[i] = '\0';
	return(time + 4);
}
