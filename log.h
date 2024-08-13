#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdint.h>
#define LOG_DEBUG 0
#define LOG_INFO  1
#define LOG_WARN  2
#define LOG_ERROR 3
typedef void (*log_callback_t)(uint8_t* buffer, uint8_t len); 
void log_init(log_callback_t log);
void log_message(int level, const char *fmt, ...);

#endif // LOG_H
