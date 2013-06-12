/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef LIBRINA_LOGS_H
#define LIBRINA_LOGS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifndef RINA_PREFIX
#error You must define RINA_PREFIX before including this file
#endif

/**
 * The log levels
 */
enum LOG_LEVEL{
	EMERG,
	ALERT,
	CRIT,
	ERR,
	WARN,
	NOTE,
	INFO,
	DBG
};

/**
 * Global log level, default is INFO
 */
extern LOG_LEVEL logLevel;

/**
 * The stream where to print the log. If none is provided,
 * it sill be printed to stdout
 */
extern FILE * logOutputStream;

/**
 * Set the log level
 *
 * @param newLogLevel the new log level
 */
void setLogLevel(LOG_LEVEL newLogLevel);

/**
 * Set the output stream.
 *
 * @param newOutputStream The output stream where to print the log statements
 * @returns 0 if successful, -1 if there is an error
 */
int setOutputStream(FILE * newOutputStream);

bool shouldLog(LOG_LEVEL level);

/**
 * Prints a log statement to the output stream, in case it can be done
 * according to the log level
 * @param level the log level
 * @param fmt a string with the print statement
 * @param ... multiple arguments for the string
 */
void LOG(LOG_LEVEL level, const char* fmt, va_list args);

void LOG_DBG(const char* fmt, ...);
void LOG_INFO(const char* fmt, ...);
void LOG_NOTE(const char* fmt, ...);
void LOG_WARN(const char* fmt, ...);
void LOG_ERR(const char* fmt, ...);
void LOG_CRIT(const char* fmt, ...);
void LOG_ALERT(const char* fmt, ...);
void LOG_EMERG(const char* fmt, ...);

/*
#define __LOG(PREFIX, LEVEL, FMT, ARGS...)                              \
        do { printf("librina-" PREFIX ": " FMT "\n", ##ARGS); } while (0)


#define _S(x) #x*/

#endif
