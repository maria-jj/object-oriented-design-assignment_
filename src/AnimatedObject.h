#pragma once

#define MAX_FRAMES 10

class AnimatedObject : 	public GameObject
{
private:  //these canot be changed directly
	int currentFrame;
	int numFrames;

public:
	ofImage frames[MAX_FRAMES];

	AnimatedObject();
	~AnimatedObject();

	void Advance();
	void SetNumFrames(int n);
	void Draw();
};

