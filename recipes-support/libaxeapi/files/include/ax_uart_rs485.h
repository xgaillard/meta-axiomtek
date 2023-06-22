#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C"
{
#endif

bool rs_485_enable(char *device);
bool rs_485_disable(char *device);
bool setting_uart(char *device,u_int32_t type);

#ifdef __cplusplus
}
#endif