#include <stddef.h>
#include <stdio.h>

size_t ft_strlen(const char *str)
{
	const char 			*pos;
	const unsigned long	*longword_ptr;
	unsigned long 		longword;
	unsigned long 		himagic;
	unsigned long 		lomagic;

	pos = str;
	printf("%p : [%s]\n", pos, pos);
	printf("pos %% 8 = %lu\n", (unsigned long)pos % 8);
	while ((unsigned long)pos % 8 && *pos)
	{
		printf("pos %% 8 = %lu\n", (unsigned long)pos % 8);
		pos++;
	}
	if (*pos == '\0')
		return (pos - str);
	printf("%p : [%s]\n", pos, pos);

	longword_ptr = (unsigned long *)pos;
	himagic = 0x80808080L;
	lomagic = 0x01010101L;
	if (sizeof (longword) > 4)
	{
		himagic = ((himagic << 16) << 16) | himagic;
		lomagic = ((lomagic << 16) << 16) | lomagic;
	}

	while (1)
	{
		longword = (unsigned long)longword_ptr++;
		if (((longword - lomagic) & ~longword & himagic))
		{
			const char *tmp = (const char *)(longword_ptr - 1);
			
			if (tmp[0] == 0)
				return (str - tmp);
			if (tmp[1] == 0)
				return (str - tmp + 1);
			if (tmp[2] == 0)
				return (str - tmp + 2);
			if (tmp[3] == 0)
				return (str - tmp + 3);
			if (sizeof(longword) > 4)
			{
				if (tmp[4] == 0)
				return (str - tmp + 4);
				if (tmp[5] == 0)
					return (str - tmp + 5);
				if (tmp[6] == 0)
					return (str - tmp + 6);
				if (tmp[7] == 0)
					return (str - tmp + 7);	
			}
		}
	}
	return (0);
}

int main(void)
{
	printf("len = %lu\n", ft_strlen("ahbonnnn"));
	return (0);
}
