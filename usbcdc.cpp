#include <stdio.h>

#include "usbcdc.h"

bool usbcdc_write(HANDLE port, const uint8_t *data, size_t bytes_to_send)
{
	DWORD bytes_sent = 0;

	do {
		if (!WriteFile(port, data, bytes_to_send, &bytes_sent, NULL)) {
			printf("Err Sending data to USB CDC device.  Error %d\n", GetLastError());

			return false;
		}
	} while (bytes_sent < bytes_to_send);

	return true;
}

HANDLE usbcdc_get_handle(const char *port_name)
{
	HANDLE port;

	port = CreateFile(port_name, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (port == INVALID_HANDLE_VALUE) {
		printf("Error opening port %hs.  Error %d\n", port_name, GetLastError());
	}

	return port;
}