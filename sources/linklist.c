#include "../include/ft_printf.h"

void    push(t_format **head, t_format *new_node)
{
    t_format *tmp;
    tmp = *head;

    if (tmp == NULL)
        *head = new_node;
    else
    {
        while (tmp->next)
            tmp = tmp->next;
        tmp->next = new_node;
    }
}