/* Hi ?*/

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct BC26 BC26;

BC26 *construct(void);

void holder(uint8_t *feed, uintptr_t len);

void nothing(void);

void recv(BC26 *p, const uint8_t *cmd, uint16_t len);

void send_cmd(BC26 *p, const uint8_t *cmd, uint16_t len);

/* Bye */