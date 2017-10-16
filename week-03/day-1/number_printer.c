#include <stdio.h>
#include <stdint.h>

void printf_numbers(uint32_t from, uint32_t to)
{
   	int maxim = to - from;
	for (int i = 0; i < maxim; i++) {
        double out = from + i;
	printf("%.f,", out);
	}
}

int main()
{
	printf_numbers(2147483600, 2147484600);
	return 0;
}

