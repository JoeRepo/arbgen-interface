#include <stdio.h>
#include <string.h>

#include "strutils.h"

void get_user_input(char *str, size_t max_len, const char *opt_output)
{
	char *p_str;

	if (opt_output) {
		puts(opt_output);
	}

	fgets(str, max_len, stdin);

	p_str = strchr(str, '\n');
	if (p_str != NULL) {
		*p_str = '\0';
	}
}