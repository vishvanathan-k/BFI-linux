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
			char tape[30000] = {0};
			char *ptr;
			ptr = tape;
			if (fp != NULL)
			{
				char code[10000];
				char *p;
				p = code;
				while (fscanf(fp, "%s", p) != EOF)
				{
					int loop_counter = 0;
					while (*p != '\0' || *p != '\n')
					{
						switch (*p)
						{
							case '>':
								++ptr;
								break;

							case '<':
								--ptr;
								break;

							case '+':
								++*ptr;
								break;

							case '-':
								--*ptr;
								break;

							case '.':
								putchar(*ptr);
								break;

							case ',':
								*ptr = getchar();
								break;

							case '[':
								if (*ptr == 0)
								{
									loop_counter++;
									while (*p != ']' || loop_counter != 0)
									{
										++p;
										if (*p == ']')
										{
											--loop_counter;
										}
										if (*p == '[')
										{
											++loop_counter;
										}
									}
								}
								break;

							case ']':
								if (*ptr != 0)
								{
									++loop_counter;
									while (*p != '[' || loop_counter != 0)
									{
										--p;
										if (*p == '[')
										{
											--loop_counter;
										}
										if (*p == ']')
										{
											++loop_counter;
										}
									}
								}
								break;

							default:
								break;
						}
						++p;
					}
				}
			}
			fclose(fp);
			printf("\n--- %s interpreted Successfully ---\n", argv[i]);
		}
	}
	return 0;
}