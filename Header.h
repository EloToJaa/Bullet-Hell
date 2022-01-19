#pragma once

#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#define deb if(0)

#define MAX_STRING 512

#include<math.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

extern "C" {
	#include"./SDL2-2.0.10/include/SDL.h"
	#include"./SDL2-2.0.10/include/SDL_main.h"
}

struct Interface;
#include "Vector.h"
#include "Collider.h"
#include "Settings.h"
#include "Colors.h"
#include "Utils.h"
#include "Draw.h"
#include "Entity.h"
#include "Background.h"
#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Game.h"
#include "Queue.h"
#include "Interface.h"