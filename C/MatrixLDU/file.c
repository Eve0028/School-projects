#include <stdio.h>

#pragma warning (disable: 4996)

void open_file(FILE** file_to_read, char file_name[])
{
	do
	{
		printf("\nEnter the name of an existing file to read (e.g. data.txt):\n");
		scanf("%s", file_name);
		*file_to_read = fopen(file_name, "r");
	} while (!(*file_to_read));
}