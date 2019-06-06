/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 18:02:36 by fhenrion          #+#    #+#             */
/*   Updated: 2019/06/02 18:18:25 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/************* change t_list**************/
t_list    *ft_creator(char c, int *tet_pattern)
{
	int *tab;
	
	
    t_list *new = (t_list *)malloc(sizeof(*new));
	new ->content = (int *)malloc(sizeof(int) * 9);
    if (new == NULL)
        return (NULL);
	int i = - 1;
	while (++i < 9)
	{
		((int *)(new->content))[i] = tet_pattern[i];
	}
	
  //  new->content = tet_pattern;
    new->content_size = 9;
    return (new);
}

t_list	*ft_save_piece(char *piece, char c)
{
	static t_list	*list;
	t_list			*tmp;
	int				*tab;
	
	// enregistre les coordonnees ainsi que le charactere
	tab = ft_parse_piece(piece, c);
	// cree la liste si premiere piece
	if (!list && tab)
	{
		// ?? int 9
		// the content in the list is not correct.
		//list = ft_lstnew(tab,9);
		list = ft_creator('A', tab);
		int i = -1;
		free(tab);
	}
	// sinon cree un nouveau chainon et ajoute a la ?? tete ?? liste
	else if (tab)
	{
		tmp = ft_lstnew(tab,sizeof(int)*8);
		free(tab);
		ft_lstadd(&list, tmp);
	}
	else
		return (NULL);
	return (list);
}

int		ft_check_piece(char *piece, int end)
{
	int	i;
	int	hash;
	
	i = 0;
	hash = 0;
	while (piece[i] != '\0')
	{
		// verifie mauvais characteres
		if (!(piece[i] == '#' || piece[i] == '.' || piece[i] == '\n'))
			return (1);
		// pour verifier le nombre de #
		if (piece[i] == '#')
			hash++;
		// verifie le bon postionnement des \n si piece du milieu ou derniere
		else if (end && piece[i] == '\n'
				&& !(i == 4 || i == 9 || i == 14 || i == 19))
			return (1);
		else if (!end && piece[i] == '\n'
				&& !(i == 4 || i == 9 || i == 14 || i == 19 || i == 20))
			return (1);
		i++;
	}
	// verifie si la derniere piece fait bien 20 en size
	if (end && ft_strlen(piece) != 20)
		return (1);
	// verifie le nombre de #
	if (hash != 4)
		return (1);
	return (0);	
}

t_list	*ft_read_file(int fd)
{
	int		count;
	char	buf[21];
	char	c;

	c = 'A';
	// tant que lit 21 charactere sur 21 de buffer
	while ((count = read(fd, buf, 21)) == 21)
	{
		buf[count] = '\0';
		// check formatage de piece (0 pour dire qu'il ne s'agit pas de la derniere)
		if (ft_check_piece(buf, 0))
			return (NULL);
		// enregistre la piece dans la liste
		else if (!ft_save_piece(buf, c++))
			return (NULL);
	}
	buf[count] = '\0';
	// check formatage pour la derniere piece (pas de \n a la fin)
	if (ft_check_piece(buf, 1))
		return (NULL);
	else
		return (ft_save_piece(buf, c)); // retourne la liste a la fin
}
