#include "../include/read_lines.h"
//gcc source/* -o read_lines.exe -D BUFFER_SIZE=10
int main()
{
    int		fd;
	char	*line;
	static liste leftovers=NULL;
	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		line = readline(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
    return 0;
}

