#pragma once

class Physics : public GameObject {
public:
	Physics();
	~Physics();
	int groundLevel;
	int groundLevelRelative;
	void SetGroundLevels(int x, int ph); //ph=player.height in ofApp
	void Move(int trgt, int x, int y, int ph, bool jmp, int t, int v0, int y0);
//	void Jump(bool jmp, int t, int y0, int v0, int y /*,bool key*/);
};