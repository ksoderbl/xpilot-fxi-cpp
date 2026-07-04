/*
 *
 * Adapted from 'The UNIX Programming Environment' by Kernighan & Pike
 * and an example from the manualpage for vprintf by
 * Gaute Nessan, University of Tromsoe (gaute@staff.cs.uit.no).
 *
 * Modified by Bjoern Stabell <bjoern@xpilot.org>.
 * Windows mods and memory leak detection by Dick Balaska <dick@xpilot.org>.
 */

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cerrno>

#include "version.h"
#include "config.h"
#include "const.h"
#include "xperror.h"
#include "portability.h"
#include "commonproto.h"

#undef HAVE_STDARG
#undef HAVE_VARARG
#ifndef _WINDOWS
#if (defined(__STDC__) && !defined(__sun__) || defined(__cplusplus))
#define HAVE_STDARG 1
#else
#define HAVE_VARARG 1
#endif
#endif

/*
 * This file defines two entry points:
 *
 * init_error()		- Initialize the error routine, accepts program name
 *			  as input.
 * error()		- perror() with printf functionality.
 */

/*
 * File local static data.
 */
#define MAX_PROG_LENGTH 32
static char progname[MAX_PROG_LENGTH];

static const char *prog_basename(const char *prog)
{
    const char *p;

    p = strrchr(prog, '/');

    return (p != NULL) ? (p + 1) : prog;
}

/*
 * Functions.
 */
void init_error(const char *prog)
{
    const char *p = prog_basename(prog); /* Beautify arv[0] */

    strlcpy(progname, p, MAX_PROG_LENGTH);
}

/*
 * Ok, let's do it the ANSI C way.
 */
void error(const char *fmt, ...)
{
    va_list ap;
    int32_t e = errno;

    va_start(ap, fmt);

    if (progname[0] != '\0')
    {
        fprintf(stderr, "%s: ", progname);
    }

    vfprintf(stderr, fmt, ap);

    if (e != 0)
    {
        fprintf(stderr, ": (%s)", strerror(e));
    }
    fprintf(stderr, "\n");

    va_end(ap);
}

void warn(const char *fmt, ...)
{
    int32_t len;
    va_list ap;

    va_start(ap, fmt);

    if (progname[0] != '\0')
    {
        fprintf(stderr, "%s: ", progname);
    }

    vfprintf(stderr, fmt, ap);

    len = strlen(fmt);
    if (len == 0 || fmt[len - 1] != '\n')
    {
        fprintf(stderr, "\n");
    }

    va_end(ap);
}

void fatal(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    if (progname[0] != '\0')
    {
        fprintf(stderr, "%s: ", progname);
    }

    vfprintf(stderr, fmt, ap);

    fprintf(stderr, "\n");

    va_end(ap);

    exit(1);
}

void dumpcore(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);

    if (progname[0] != '\0')
    {
        fprintf(stderr, "%s: ", progname);
    }

    vfprintf(stderr, fmt, ap);

    fprintf(stderr, "\n");

    va_end(ap);

    abort();
}
