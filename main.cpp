#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>

#include "usbcdc.h"
#include "strutils.h"

#define USAGE_MSG "Usage: ./arbgen-interface COM##"

#define ARBGEN_USAGE	"TX:\tT [UART bus as 2 bytes of ASCII hex] [data as ASCII hex]\n" \
						"\t\"T 00 AA55AA55AA55\"\n" \
						"RX:\tR [UART bus as 2 bytes of ASCII hex] [number of bytes to read as ASCII dec]\n" \
						"\t\"R 00 4\"\n" \
						"Baud:\tB [UART bus as 2 bytes of ASCII hex] [baud rate to change to as ASCII dec]\n" \
						"\t\"B 00 115200\"\n"

int main(int argc, char *argv[])
{
	const char *port_name;
	HANDLE port;
	char mcu_input[256];
	size_t mcu_input_len;

	if (argc != 2) {
		puts(USAGE_MSG);
		return 1;
	}

	port_name = argv[1];
	port = usbcdc_get_handle(port_name);
	if (port == INVALID_HANDLE_VALUE) {
		return 1;
	}

	puts(ARBGEN_USAGE);
	do {
		get_user_input(mcu_input, sizeof(mcu_input), NULL);
		mcu_input_len = strlen(mcu_input);

		if (mcu_input_len > 0) {
			usbcdc_write(port, (const uint8_t *)mcu_input, mcu_input_len);
		}
	} while (mcu_input_len > 0);

	return 0;
}