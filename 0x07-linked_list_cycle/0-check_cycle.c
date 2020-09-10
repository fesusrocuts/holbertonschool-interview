#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

int check_cycle(listint_t *list)
{
	int i = 0;
	listint_t *tmp;
	unsigned int lastn = 9999;
	unsigned int firstn = 0;

	tmp = list;
	while (tmp != NULL)
	{
		i++;
		if (i == 1)
			firstn = list->n;
		lastn = tmp->n;
		tmp = tmp->next;
		if ((lastn == firstn && i > 1) || i > 1000)
			return 1;
	}
	return (0);
}
