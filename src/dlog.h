/*
 *  Module: Debug Logger
 *
 *  Author: Alex Dale @superoxigen
 *
 *  Copyright (c) 2018 Alex Dale
 *  See LICENSE for information.
 */

#ifndef _DLOG_H_
#define _DLOG_H_

#include "utils.h"

#ifdef DEBUG_LOGS

START_C_SECTION

extern kstring_t kDLogInfo;
extern kstring_t kDLogError;

#define DLOG_INIT() _dlog_init();
/* Logging Macros */
#define DLOG(message) _dlog(__FILE__, "__LINE__", kDLogInfo, message, NULL)
#define DLOG_ERR(message) _dlog(__FILE__, "__LINE__", kDLogError, message, NULL)
#define DLOG_ERR2(message, sample) _dlog2(__FILE__, "__LINE__", kDLogWarn, message, sample)

void _dlog(kstring_t file, kstring_t line, kstring_t level, kstring_t message, kstring_t sample);

END_C_SECTION

#else /* not defined(DEBUG_LOGS) */

#define DLOG_INIT()

#define DLOG(message)
#define DLOG_ERR(message)
#define DLOG_ERR2(message, sample)

#endif

#endif /* _DLOG_H_ */