#include <fcntl.h>
#include "get_next_line.h"

int	main(void)
{
	int i;
	char *s;

	i = open("hi.txt", O_RDONLY);
	s = get_next_line(i);
	printf("%s", s);
	return (i);
}
