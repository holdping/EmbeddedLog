#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>
#include <stdint.h>
#define LOG_DEBUG 0
#define LOG_INFO  1
#define LOG_WARN  2
#define LOG_ERROR 3
#ifdef __cplusplus
extern "C" {
#endif
typedef void (*log_callback_t)(uint8_t* buffer, uint16_t len); 
void log_init(log_callback_t log);
void log_message(int level, const char *fmt, ...);
#define log_debug(fmt, ...) log_message(LOG_DEBUG, fmt, ##__VA_ARGS__)
#define log_info(fmt, ...) log_message(LOG_INFO, fmt, ##__VA_ARGS__)
#define log_warn(fmt, ...) log_message(LOG_WARN, fmt, ##__VA_ARGS__)
#define log_error(fmt, ...) log_message(LOG_ERROR, fmt, ##__VA_ARGS__)
#ifdef __cplusplus
}
#endif

#endif // LOG_H