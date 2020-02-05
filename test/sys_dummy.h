/* BC26-Rust C Library ?*/

#ifndef BC26_CAPI_H
#define BC26_CAPI_H

/* Warning, this file is autogenerated by cbindgen. Don't modify this manually. */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum
{
  Ok,
  ErrStateMismatch,
  ErrLocked,
  ErrResponseTypeMismatch,
  ErrResponseParsedLengthMismatch,
  ErrUnexpectedError,
  ErrMutexError,
  ErrOSError,
  Timeout,
} BC26Status;

typedef enum
{
  dummyOk
} osStatus_t;

typedef struct Arc_Mutex_BC26 Arc_Mutex_BC26;

typedef struct MQTT MQTT;

typedef struct MQTTFlags MQTTFlags;

typedef struct osMessageQueueAttr_t osMessageQueueAttr_t;

typedef const void *osMessageQueueId_t;

typedef struct osMutexAttr_t osMutexAttr_t;

typedef Arc_Mutex_BC26 MutexedBC26;

typedef const void *osMutexId_t;

BC26Status Init(MutexedBC26 *ptr);

BC26Status checkConnect(MutexedBC26 *ptr);

MutexedBC26 *construct(uint8_t *_begin, uintptr_t _size);

BC26Status feed(osMessageQueueId_t qid, uint8_t *begin, uintptr_t size);

osMessageQueueId_t get_bc26_qid(MutexedBC26 *ptr);

BC26Status mqtt_conn(MQTT *ptr, uint16_t conn_id, const uint8_t *client_id);

MQTT *mqtt_construct(MutexedBC26 *ptr);

BC26Status mqtt_open(MQTT *ptr, uint16_t conn_id, const uint8_t *host_name, uint16_t port);

extern void osDelay(uintptr_t tick);

extern osStatus_t osMessageQueueGet(osMessageQueueId_t id,
                                    void *msg_ptr,
                                    uint8_t msg_prio,
                                    uint32_t timeout);

extern osMessageQueueId_t osMessageQueueNew(uint32_t msg_count,
                                            uint32_t msg_size,
                                            const osMessageQueueAttr_t *attr_t);

extern osStatus_t osMessageQueuePut(osMessageQueueId_t id,
                                    const void *msg_ptr,
                                    uint8_t msg_prio,
                                    uint32_t timeout);

extern osStatus_t osMutexAcquire(osMutexId_t id, uintptr_t timeout);

extern osStatus_t osMutexDelete(osMutexId_t id);

extern const uint8_t *osMutexGetName(osMutexId_t mutex_id);

extern osMutexId_t osMutexNew(const osMutexAttr_t *attr);

extern osMutexId_t osMutexRecursive(const osMutexId_t *attr);

extern osStatus_t osMutexRelease(osMutexId_t id);

#endif /* BC26_CAPI_H */

/* Bye */
