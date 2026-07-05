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

#include "click.h"

/*
 * Object position
 *
 * NB: position in pixels used to be a float.
 */
typedef struct
{
	int32_t x, y;	/* object position in pixels. */
	int32_t cx, cy; /* object position in clicks. */
	int32_t bx, by; /* object position in blocks. */
} objposition_t;

#define OBJ_X_IN_CLICKS(obj) ((obj)->pos.cx)
#define OBJ_Y_IN_CLICKS(obj) ((obj)->pos.cy)
#define OBJ_X_IN_PIXELS(obj) ((obj)->pos.x)
#define OBJ_Y_IN_PIXELS(obj) ((obj)->pos.y)
#define OBJ_X_IN_BLOCKS(obj) ((obj)->pos.bx)
#define OBJ_Y_IN_BLOCKS(obj) ((obj)->pos.by)

#define Object_position_remember(o_) \
	((o_)->prevpos.x = (o_)->pos.x,  \
	 (o_)->prevpos.y = (o_)->pos.y)
#define Player_position_remember(p_) Object_position_remember(p_)

/** \brief Sets position in clicks
 *
 * NOTE: After execution the position can be outside map boundaries
 *
 * \param clpos		position in clicks
 * \param cx		X coordinate in clicks
 * \param cy		Y coordinate in clicks
 */
static inline void Position_simple_set(clpos_t *clpos, int32_t cx, int32_t cy)
{
	clpos->cx = cx;
	clpos->cy = cy;
}

/** \brief Adds the offsets to position
 *
 * NOTE: After execution the position can be outside map boundaries
 *
 * \param clpos		position in clicks
 * \param delta_cx	X coordinate in clicks
 * \param delta_cy	Y coordinate in clicks
 */
static inline void Position_simple_add(clpos_t *clpos, int32_t delta_cx, int32_t delta_cy)
{
	clpos->cx += delta_cx;
	clpos->cy += delta_cy;
}

// void Player_position_debug(player_t *pl, const char *msg);
// void Player_position_restore(player_t *pl);

void Position_copy(objposition_t *dstpos, objposition_t *srcpos);
void Position_set(objposition_t *pos, clpos_t *clpos);
