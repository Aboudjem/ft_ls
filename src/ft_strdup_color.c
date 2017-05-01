#include "ft_ls.h"

char	*ft_strdup_color(const char *s1, char *color)
{
	int		i;
	int		j;
	size_t	len;
	char	*str;
	char	*stop;

	stop = STOP;
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(color) + ft_strlen(STOP);
	str = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (!str)
		exit(0);
	while (color[j])
	{
		str[j] = color[j];
		j++;
	}
	while (s1[i] != '\0')
	{
		str[i+j] = s1[i];
		i++;
	}
	i = i+j;
	j = 0;
	while (stop[j])
	{
		str[i+j] = stop[j];
		j++;
	}
	str[i+j] = '\0';
	return (str);
}
