#include <Windows.h>
#include <stdint.h>

bool usbcdc_write(HANDLE port, const uint8_t *data, size_t bytes_to_send);
HANDLE usbcdc_get_handle(const char *port_name);