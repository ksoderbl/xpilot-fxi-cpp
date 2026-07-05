/*
 * update.h
 *
 *  Created on: May 21, 2009
 *      Author: rotunda
 */

#pragma once

#include "team.h"

#include "player.h"

void Update_player_turn(player_t *pl);
void Update_player_thrust(player_t *pl);
void Update_players(void);
void Update_robots(void);
void Update_fuel_stations(void);
void Update_mobile_objects(void);

void Update_game_status(void);
void Game_compute_team_stats(team_game_stats_t *tstats);
