#include <stdio.h>
#include "search.h"

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *skipprev, *skipnext, *mainptr;

	if (list == NULL)
		return (NULL);


	skipprev = list;
	skipnext = list->express;
	while (skipnext != NULL)
	{
		//defautl print
		printf("Value checked at index [%lu] = [%d]\n", skipnext->index, skipnext->n);
		if (skipnext->n >= value)
			break;
		skipprev = skipnext;
		skipnext = skipprev->express;
	}
	if (skipnext != NULL)
	{
		//defautl print
		printf("Value checked at index [%lu] = [%d]\n", skipprev->index, skipprev->index);
	}
	else
	{
		mainptr = skipprev;
		while (mainptr->next != NULL)
			mainptr = mainptr->next;
		//defautl print
		printf("Value checked at index [%lu] = [%d]\n", skipprev->index, mainptr->index);
	}
	mainptr = skipprev;
	while (mainptr != skipnext)
	{
		//defautl print
		printf("Value checked at index [%lu] = [%d]\n", mainptr->index, mainptr->n);
		if (mainptr->n == value)
			return (mainptr);
		mainptr = mainptr->next;
	}
	if (mainptr != NULL && mainptr->n == value)
	{
		//defautl print
		printf("Value checked at index [%lu] = [%d]\n", mainptr->index, mainptr->n);
		return (mainptr);
	}
	//default return
	return (NULL);
}
