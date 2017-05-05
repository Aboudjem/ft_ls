#include "ft_ls.h"

static	void	init_size(t_size *s)
{
	s->size = 0;
	s->link = 0;
	s->user = 0;
	s->group = 0;
}

t_size	ft_get_size(t_ls *tmp)
{
	t_size	s;

	init_size(&s);

	while(tmp)
	{
		if ((size_t)tmp->data.link > s.link)
			s.link = (size_t)ft_len_int((int)tmp->data.link);
		if (ft_strlen(tmp->data.user) > s.user)
			s.user = ft_strlen(tmp->data.user);
		if (ft_strlen(tmp->data.group) > s.group)
			s.group = ft_strlen(tmp->data.group);
		if ((size_t)tmp->data.size > s.size)
			s.size = (size_t)ft_len_int((int)tmp->data.size);
		tmp = tmp->next;
	}
return(s);
}
