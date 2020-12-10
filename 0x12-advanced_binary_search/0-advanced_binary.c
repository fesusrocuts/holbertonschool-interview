#include <stdlib.h>
#include <stdio.h>
#include "search_algos.h"

int recursive1(int *array, int *clone, size_t size, int value)
{
	size_t idx_num_split = (size - 1) / 2;
	size_t i = 0;
	// char extstr[] = "  ";

	if (size < 1)
		return (-1);
	printf("Searching in array: ");
	for (i = 0; i < size; i++){
		if (i < size - 1){
			printf("%d%s", clone[i], ", ");
		}
		else
		{
			printf("%d%s", clone[i], "\n");
		}
	}
	if (!idx_num_split && *clone >= value){
		if (*clone == value){
			return (clone - array);
		}else{
			return (-1);
		}
	}
	if (clone[idx_num_split] >= value){
		return (recursive1(array, clone, 1 + idx_num_split, value));
	}
	return (recursive1(array, clone + 1 + idx_num_split, size - 1 - idx_num_split, value));
}

int advanced_binary(int *array, size_t size, int value)
{
	return (recursive1(array, array, size, value));
}