/*
 * ship.h
 *
 *  Created on: Nov 15, 2009
 *      Author: rotunda
 */

#pragma once

#include "types.h"
#include "objpos.h"

void Make_debris(objposition_t *pos, double velx, double vely, player_t *pl, team_t *team, int32_t type, double mass,
				 int32_t status, int32_t color, int32_t radius, int32_t min_debris, int32_t max_debris, int32_t min_dir, int32_t max_dir,
				 double min_speed, double max_speed, int32_t min_life, int32_t max_life);
void Make_wreckage(objposition_t *pos, double velx, double vely, player_t *pl, team_t *team, double min_mass, double max_mass,
				   double total_mass, int32_t status, int32_t color, int32_t max_wreckage, int32_t min_dir, int32_t max_dir,
				   double min_speed, double max_speed, int32_t min_life, int32_t max_life);
void Player_explode(player_t *pl);
void Player_thrust(player_t *pl);
// void Recoil(object_t *ship, object_t *shot);
void Delta_mv(object_t *ship, object_t *obj);
void Ship_object_repel(object_t *ship, object_t *obj2, int32_t repel_dist);
void Record_shove(player_t *pl, player_t *pusher, int32_t time);
