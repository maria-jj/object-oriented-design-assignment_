#include "Main.h"
Physics::Physics()
{
}

Physics::~Physics()
{
}

void Physics::SetGroundLevels(int x, int ph) {
	if (x < 130)
		groundLevel = 660;
	else if (x < 370)
		groundLevel = 500;
	else if (x < 600)
		groundLevel = 340;
	else if (x < 920)
		groundLevel = 340 + (x - 600);
	else
		groundLevel = 660;
		
	groundLevelRelative = groundLevel - ph;  
}

void Physics::Move(int trgt, int x, int y,int ph, bool jmp, int t, int v0, int y0) {
	SetGroundLevels(trgt, ph);
	int dy = groundLevelRelative - y;
	if (dy > -5) //we can move if groundlevel is not more than 5 higher
	{
		x = trgt;
		if (dy < 5)
			y += dy;
	}
	else										//stay where we are
		SetGroundLevels(x, ph);
	if (jmp == true)
	{
		//move
		y = y0 - v0 * t
			+ 0.5 * GRAVITY * t*t;
		//advance time
		t++;  // or +=0.2 if you want slower movement
		//reached the ground?
		if (y > groundLevelRelative)
		{
			y = groundLevelRelative;
			jmp = false;
		}
	}
	else //see if we have walked off a cliff and have to fall
	{
		if (y < groundLevelRelative)
		{
			jmp = true;
			t = 0;
			y0 = y;
			v0 = 0;
		}
	}
}

//void Physics::Jump(bool jmp, int t, int y0, int v0, int y/*, bool key*/) {
//	/*if (keyDown[' '] == true && jmp == false)
//	{
//		jmp = true;
//		t = 0;
//		y0 =y;
//		v0 = JUMP_SPEED;
//	}*/
//	//jump and fall
//	if (jmp == true)
//	{
//		//move
//		y = y0 - v0 * t
//			+ 0.5 * GRAVITY * t*t;
//		//advance time
//		t++;  // or +=0.2 if you want slower movement
//		//reached the ground?
//		if (y >groundLevelRelative)
//		{
//			y = groundLevelRelative;
//			jmp = false;
//		}
//	}
//	else //see if we have walked off a cliff and have to fall
//	{
//		if (y <groundLevelRelative)
//		{
//			jmp = true;
//			t = 0;
//			y0 = y;
//			v0 = 0;
//		}
//	}
//}




//void Physics::SetGroundLevels(int x, int ph) {
//	if (x < 130)
//		groundLevel = 660;
//	else if (x < 370)
//		groundLevel = 500;
//	else if (x < 600)
//		groundLevel = 340;
//	else if (x < 920)
//		groundLevel = 340 + (x - 600);
//	else
//		groundLevel = 660;
//
//	groundLevelRelative = groundLevel - ph;
//}
//
//void Physics::Move(int trgt, int x, int y, int ph) {
//	//SetGroundLevels(trgt, ph);
//	int dy = groundLevelRelative - y;
//	if (dy > -5) //we can move if groundlevel is not more than 5 higher
//	{
//		x = trgt;
//		if (dy < 5)
//			y += dy;
//	}
//	else										//stay where we are
//		SetGroundLevels(x, ph);
//}
