/*
 * XPilot, a multiplayer gravity war game.  Copyright (C) 1991-2001 by
 *
 *      Bjørn Stabell
 *      Ken Ronny Schouten
 *      Bert Gijsbers
 *      Dick Balaska
 *
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
 * along with this program; if not, see
 * <https://www.gnu.org/licenses/>.
 */

#pragma once

#include <cstdarg>
#include <cstdint>

#define MIN_SOCKBUF_SIZE 1024
#define MAX_SOCKBUF_SIZE (50 * 1024)

#define SERVER_RECV_SIZE MIN_SOCKBUF_SIZE
#define SERVER_SEND_SIZE (4 * 1024)

#define CLIENT_SEND_SIZE SERVER_RECV_SIZE
#define CLIENT_RECV_SIZE SERVER_SEND_SIZE

/*
 * Definitions for the states a socket buffer can be in.
 */
#define SOCKBUF_READ 0x01  /* if readable */
#define SOCKBUF_WRITE 0x02 /* if writeable */
#define SOCKBUF_LOCK 0x04  /* if locked against kernel i/o */
#define SOCKBUF_ERROR 0x08 /* if i/o error occurred */
#define SOCKBUF_DGRAM 0x10 /* if datagram socket */

/*
 * Hack: leave some spare room for the last terminating packet
 * of a frame update.
 */
#define SOCKBUF_WRITE_SPARE 8

/*
 * Maximum number of socket i/o retries if datagram socket.
 */
#define MAX_SOCKBUF_RETRIES 2

/*
 * A buffer to reduce the number of system calls made and to reduce
 * the number of network packets.
 */
typedef struct
{
	int32_t sock;  /* socket filedescriptor */
	char *buf;	   /* i/o data buffer */
	int32_t size;  /* size of buffer */
	int32_t len;   /* amount of data in buffer (writing/reading) */
	char *ptr;	   /* current position in buffer (reading) */
	int32_t state; /* read/write/locked/error status flags */
} sockbuf_t;

int32_t Sockbuf_init(sockbuf_t *sbuf, int32_t sock, int32_t size, int32_t state);
int32_t Sockbuf_cleanup(sockbuf_t *sbuf);
int32_t Sockbuf_clear(sockbuf_t *sbuf);
int32_t Sockbuf_advance(sockbuf_t *sbuf, int32_t len);
int32_t Sockbuf_flush(sockbuf_t *sbuf);
int32_t Sockbuf_write(sockbuf_t *sbuf, char *buf, int32_t len);
int32_t Sockbuf_read(sockbuf_t *sbuf);
int32_t Sockbuf_copy(sockbuf_t *dest, sockbuf_t *src, int32_t len);

int32_t Packet_printf(sockbuf_t *, const char *fmt, ...);
int32_t Packet_scanf(sockbuf_t *, const char *fmt, ...);
