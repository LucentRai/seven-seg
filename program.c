#include "7seg.h"

#ifndef DEBUG
	#define DEBUG
#endif

int main(int argc, char *argv[])
{
	int i;

	if(argc == 1)
	{
		print7seg("abcdef");
		print7seg("ghijkl");
		print7seg("mnopqr");
		print7seg("stuvwx");
		print7seg("yz");
		print7seg("01234");
		print7seg("56789");
		exit(EXIT_SUCCESS);
	}
	else
	{
		print7seg(argv[1]);
	}

	exit(EXIT_SUCCESS);
}