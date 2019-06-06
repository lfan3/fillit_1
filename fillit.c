/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenrion <fhenrion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:18:13 by fhenrion          #+#    #+#             */
/*   Updated: 2019/06/02 18:38:38 by fhenrion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
/* correction : the old probem with the tab[8] to put the correct char related to 
the mistake in ft_save_piece, i created a function called ft_creator to replace your
ft_strlnew,because with your ft_strlnew, that did not work, and i can not find out 
the probleme of your function at the first time, so i prefered to created a new function to do my
test. you can compare later with your ft_strlnew in order to understand the problem*/

/* comportement bizzare que je ne comprends pas: premier excusion ./a,out=good, 
mais reecrire la command ./a.out, segmentation fault
quand je relance le programme d execusion, ca refonctionne de nouveau*/

void	ft_put_piece(char **grid, int position, int size, int *tab)
{
	int	x;
	int	y;
	int	i;

	x = position % size;
	y = position / size;
	i = 0;
	// dernier TEST -> ne recupere pas bien le char ici
	// si on peut pas faire ca, dommage ca simplifiait pas mal le code... 
	printf("tab[8] %d\n", ((int*)(tab))[7]);
	ft_putchar(tab[8]);
	ft_putchar('\n');

	while (i < 8)
	{
		// enregistre le char au coordonnees			
		grid[y + tab[i+1]][x + tab[i]]= tab[8];
		i += 2;
	}
	grid[0][0] = tab[0] + '0';
	int k;
	int j;
	k = 0;
	j = 0;
	while (k < 3){
		j = 0;
		while (j < 3)
		{
			printf("%c ", grid[k][j]);
			j++;
		}	
		printf("\n");		
		k++;
	}
	
}

int		ft_check_position(char **grid, int position, int size, int *tab)
{
	int	x;
	int	y;
	int	i;

	// fin de la grille
	if (position > size * size)
		return (-1);
	i = 0;
	x = position % size;
	y = position / size;
	while (i < 8)
	{
		// si depasse la grille en x ou y
		/*********** ??? si on depasse x, x doit revenir a 0, et y augement 1, 
		 x=col, y = row for me/
		/* code que je propose sans le tester */
		/***********
		if ((x + tab[i]) >= size || (y + tab[i + 1]) >= size)
		{
			if ((x + tab[i]) >= size)
			{
				x = 0;val
				y++;
				if (y >= size)
					return (0);
			}	
			if (y + tab[i + 1] >= size)
				return (0);
		}	**************/
		if ((x + tab[i]) >= size || (y + tab[i + 1]) >= size)
			return (0);
		// si se superpose a une autre piece
		
		if (grid[x + tab[i]][y + tab[i + 1]] != '.')
			return (0);
		i += 2;
	}
	return (1);
}

// !!! pas bon du tout en fait, ne tente pas de replacer la piece precedente si la piece en cours ne peut pas etre placee et renvoi juste faux (et donc recommence avec une grille plus grande)
int		ft_backtrack(char **grid, t_list *lst, int size, int position)
{
	int ret;

	// si toute les pieces sont placees retourne 1
	if (!lst)
		return (1);
	// tant que pas trouvee de position, test prochaine position
	
	while (!(ret = ft_check_position(grid, position, size, lst->content)))
		position++;
	// si position trouvee
	//printf("ret1 %d\n", ret);
	if (ret > 0)
	{
		// enregistre la piece sur la grille
		ft_put_piece(grid, position, size, lst->content);
		// passe a la prochaine piece
		ret = ft_backtrack(grid, lst->next, size, position++);
	}
	// pas de position trouvee
	/*
	else
		ret = 0;*/
	// si place toutes les pieces le retour sera de 1 (debut de la fonction) sinon 0 (ci-dessus)
	printf("ret %d\n", ret);
	return (ret);
}

int		ft_solve(t_list *lst)
{
	char	**grid;
	int		size;

	// taille minimun de depart
	size = ft_start_size(lst);
	// generation de la gille
	grid = ft_gen_grid(size);
	// tant que grille NOK
	
	while (!ft_backtrack(grid, lst, size, 0))
	{
		// libere la grille puis augmente size
		ft_free_grid(grid, size++);
		// cree une nouvelle grille
		grid = ft_gen_grid(size);
	}
	
	// affiche le resultat
	ft_print_grid(grid, size);
	// libere la memoire des pieces
	ft_free_coord(lst);
	return (1);
}
/*
int		main(int argc, char **argv)
{
	int		fd;
	t_list	*lst;

	if (argc != 2) // usage si mauvais nombre d'arguments
	{
		ft_putstr(USAGE);
		return (0);
	}
	else
		fd = open(argv[1], O_RDONLY); // ouverture fichier
	if (fd == -1) // erreur si probleme a l'ouverture du fichier
	{
		ft_putstr("error, can not open the file\n");
		return (0);
	}
	// lance la verification et l'enregistrement des pieces
	lst = ft_read_file(fd);
	if (lst)
	{
		ft_lstreverse(&lst); // remet les pieces dans le bon ordre
		ft_solve(lst); // recherche de la solution
	}
	else
		ft_putstr("error, mistakes in the source file\n"); // erreur si fichier incorrecte
	close(fd);
	return (0);
}*/