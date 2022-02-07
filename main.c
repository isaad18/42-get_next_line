#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int i;

	i = open("hi.c", O_RDONLY);
	printf("%s", get_next_line(i));
	printf("%s", get_next_line(i));
	return (i);
}
