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
/************************************************************************************
 *  @brief      log callback function 
 *  @param      buffer  log message buffer
 *  @param      len     log message length
 *  @return     none
 *  @date       2024-08-13
 *  @details    The Log Callback Function Is Defined To Output Log Information To
 *              A Specified Device Such As A Serial Port Or File
 ************************************************************************************/
typedef void (*log_callback_t)(uint8_t* buffer, uint16_t len); 

/***********************************************************************************
 *  @brief      log initialization function 
 *  @param      log     log callback function
 *  @date       2024-08-13
 *  @details    The Log Initialization Function Is Used To Set The Log Callback
 *              Function That Will Be Used To Output Log Information To A Specified
 *              Device. The Log Callback Function Is Defined To Output Log Information
 *              To A Specified Device Such As A Serial Port Or File.
 ***********************************************************************************/
void log_init(log_callback_t log);

/**********************************************************************************
 *  @brief      log message function 
 *  @param      level   log level
 *  @param      fmt     log message format string
 *  @param     ...     variable argument list
 *  @date       2024-08-13
 *  @details    The Log Message Function Is Used To Output Log Information To A
 *              Specified Device. The Log Level Is Used To Determine The Log Level
 ***********************************************************************************/
void log_message(int level, const char *fmt, ...);

#define log_debug(fmt, ...) log_message(LOG_DEBUG, fmt, ##__VA_ARGS__)
#define log_info(fmt, ...) log_message(LOG_INFO, fmt, ##__VA_ARGS__)
#define log_warn(fmt, ...) log_message(LOG_WARN, fmt, ##__VA_ARGS__)
#define log_error(fmt, ...) log_message(LOG_ERROR, fmt, ##__VA_ARGS__)
#ifdef __cplusplus
}
#endif

#endif // LOG_H