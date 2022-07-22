#pragma once
#ifndef _ship_H_
#define _ship_H_

#include <SDL.h>
#include "Bullet.h"

class ship
{
private:
	SDL_Rect m_src, m_dst; // Set x and y of m_dst to/from XML.
	SDL_Point m_startPos; // Don't need this actually.
	
	// Firing properties.
	bool m_hasTarget;
	int m_fireCtr;
	static int s_coolDown;
	int m_speed = 3;
public:
	double m_angle;
	ship(SDL_Rect dst);
	void Update();
	void Render();
	SDL_Point GetPos() const { return { m_dst.x + m_dst.w / 2, m_dst.y + m_dst.h / 2 }; }

	bool TdeletME = false;
};

#endif