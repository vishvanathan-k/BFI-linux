#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		printf("BFI: fatal: No input file");
		return -1;
	}
	else
	{
		for (int i = 1; i < argc; i++)
		{
			FILE *fp = NULL;
			fp = fopen(argv[i], "r");
			char array[3000] = {0};
			char *ptr;
			ptr = array;
			if (fp != NULL)
			{
				char code[1000];
				char *p;
				p = code;
				fscanf(fp, "%s", p);
				while (*p != '\0')
				{
					if (*p == '>')
						++ptr;
					else if (*p == '<')
						--ptr;
					else if (*p == '+')
						++*ptr;
					else if (*p == '-')
						--*ptr;
					else if (*p == '.')
						putchar(*ptr);
					else if (*p == ',')
						*ptr = getchar();
					else if (*p == '[')
					{
						int var = 0;
						if (*ptr == 0)
						{
							while (*p != ']' && var != 0)
							{
								if (*p == ']' && var != 0)
									var--;
								if (*p == '[')
									var++;
								p++;
							}
						}
					}
					else if (*p == ']')
					{
						int var = 0;
						if (*ptr != 0)
						{
							while (*p != '[' && var != 0)
							{
								if (*p == '[' && var != 0)
									var--;
								if (*p == ']')
									var++;
								p--;
							}
						}
					}
					p++;
				}
			}
			for(int j = 0; j < 1000; j++){
				if(array[j] == '\0') break;
				printf("\n%d %d",j, array[j]);
			}
			fclose(fp);
			printf("\n--- %s interpreted Successfully ---\n", argv[i]);
		}
	}
	return 0;
}
