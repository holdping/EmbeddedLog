#include "log.h"
#include <stdarg.h>
static log_callback_t log_print_callback = NULL;

void log_init(log_callback_t log)
{
    log_print_callback = log;
}

void log_message(int level, const char *fmt, ...)
{
    char buffer[512];
    int len = 0;

    switch (level) {
        case LOG_DEBUG:
            len += snprintf(buffer + len, sizeof(buffer) - len, "\033[32m[DEBUG] "); // ??
            len += snprintf(buffer + len, sizeof(buffer) - len, "In File %s,Line %d",__FILE__,__LINE__); // ??
            break;
        case LOG_INFO:
            len += snprintf(buffer + len, sizeof(buffer) - len, "\033[32m[INFO] "); // ??
            break;
        case LOG_WARN:
            len += snprintf(buffer + len, sizeof(buffer) - len, "\033[33m[WARN] "); // ??
            break;
        case LOG_ERROR:
            len += snprintf(buffer + len, sizeof(buffer) - len, "\033[31m[ERROR] "); // ??
            len += snprintf(buffer + len, sizeof(buffer) - len, "In File %s,Line %d",__FILE__,__LINE__); // ??
            break;
        default:
            return;
    }


    va_list args;
    va_start(args, fmt);
    len += vsnprintf(buffer + len, sizeof(buffer) - len, fmt, args);
    va_end(args);

    if (len < sizeof(buffer) - 5) {
        buffer[len++] = '\r';
        buffer[len++] = '\n';
        len += snprintf(buffer + len, sizeof(buffer) - len, "\033[0m"); // ????
    }
    if (log_print_callback != NULL)
    {
        log_print_callback((uint8_t*)buffer, len);
    }
    
    
}
