/*
 * team.h
 *
 *  Created on: Nov 9, 2009
 *      Author: rotunda
 */

#pragma once

#include <cstdint>

#include "map.h"
// #include "player.h"

struct base;
struct player;

typedef struct team
{
	int32_t Num; /* Number of team */

	int32_t NumMembers; /* Number of current members */
	int32_t NumRobots;	/* Number of robot players */

	int32_t NumBases;			/* Number of bases owned */
	int32_t NumTreasures;		/* Number of treasures owned */
	int32_t TreasuresDestroyed; /* Number of destroyed treasures */
	int32_t TreasuresLeft;		/* Number of treasures left */
	struct player *Swapper;		/* Player swapping to this full team */
	int32_t Properties;			/* Properties of the team */
} team_t;

extern int32_t Team_count_players(team_t *team, int32_t state);
extern team_t *Team_get_by_id(int32_t team_id);
extern bool Team_is_dead(team_t *team);
extern int32_t Team_count_active_players(team_t *team);

extern void Teams_reset(void);
extern void Team_game_over(team_t *winning_team, const char *reason);
extern struct base *Team_pick_free_base(team_t *team);
extern team_t *Team_find_available(int32_t pl_type);

void Rounds_count(void);
