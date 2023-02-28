#include <stdio.h>
#include <limits.h>
#include "parser.h"

int main(int argc, char *argv[])
{
	if(check_args(argc, argv))
		printf("succes");
	else	
		printf("ERROR");

	return (0);
}