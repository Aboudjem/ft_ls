#include "ft_ls.h"

void	add_infos(t_dir *file, t_stat buf, t_ls *ls)
{	
	ls->data.mod = get_mod(buf, get_type(file->d_type));
	ls->data.link = buf.st_nlink;
	ls->data.user = get_uid(buf.st_uid);
	ls->data.group = get_gid(buf.st_gid);
	ls->data.size = buf.st_size;
	ls->data.time = get_time(buf.st_mtime);
	ls->data.name = ft_strdup(file->d_name);
	ls->data.t = (size_t)buf.st_mtime;
	ls->next = NULL;
}

t_ls 	*new_lst(t_dir *file, t_stat buf)
{
	t_ls *ls;

	if(!(ls = (t_ls*)ft_memalloc(sizeof(t_ls))))
		exit (0);
	add_infos(file, buf, ls);
	return (ls);
}

t_ls	*add_list(t_ls *lst, t_dir *file, t_stat buf)
{
	t_ls *tmp;

	if (!lst->data.name)
	{
		add_infos(file, buf, lst);
		return(lst);
	}
	else
	{
		tmp = lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_lst(file, buf);
	}
	return(lst); // on renvoi le maillon de depart de list;
}
