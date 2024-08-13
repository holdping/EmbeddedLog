#include "log.h"
#include <stdarg.h>
static log_callback_t log_print_callback = NULL;

// Initialize the log module with a log callback function
void log_init(log_callback_t log)
{
    log_print_callback = log;
}

// Log a message with a given level
void log_message(int level, const char *fmt, ...)
{
    char buffer[512]; // Create a buffer to store the log message
    uint16_t len = 0; // Initialize the length of the log message

    // Check the level of the message and set the color accordingly
    switch (level) {
        case LOG_DEBUG:
            len += snprintf(buffer + len, sizeof(buffer) - len, "\033[32m[DEBUG] "); // Set the color to green
            len += snprintf(buffer + len, sizeof(buffer) - len, "In File %s,Line %d",__FILE__,__LINE__); // Add the file and line number
            break;
        case LOG_INFO:
            len += snprintf(buffer + len, sizeof(buffer) - len, "\033[32m[INFO] "); // Set the color to green
            break;
        case LOG_WARN:
            len += snprintf(buffer + len, sizeof(buffer) - len, "\033[33m[WARN] "); // Set the color to yellow
            break;
        case LOG_ERROR:
            len += snprintf(buffer + len, sizeof(buffer) - len, "\033[31m[ERROR] "); // Set the color to red
            len += snprintf(buffer + len, sizeof(buffer) - len, "In File %s,Line %d",__FILE__,__LINE__); // Add the file and line number
            break;
        default:
            return;
    }

    // Add the message format and arguments to the buffer
    va_list args;
    va_start(args, fmt);
    len += vsnprintf(buffer + len, sizeof(buffer) - len, fmt, args);
    va_end(args);

    // Add a newline and reset the color to the buffer
    if (len < sizeof(buffer) - 5) {
        buffer[len++] = '\r';
        buffer[len++] = '\n';
        len += snprintf(buffer + len, sizeof(buffer) - len, "\033[0m"); // Reset the color
    }

    // If a log callback is set, print the buffer
    if (log_print_callback != NULL)
    {
        log_print_callback((uint8_t*)buffer, len);
    }
    
    
}

void __assert(const char *expr) {
    log_message(LOG_ERROR,"Assertion failed: %s, file %s, line %d\n", expr, __FILE__, __LINE__);
}
