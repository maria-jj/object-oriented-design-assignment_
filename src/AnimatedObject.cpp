#include "Main.h"


AnimatedObject::AnimatedObject()
{
	numFrames = 0;
	currentFrame = -1; //no valid frame
}


AnimatedObject::~AnimatedObject()
{
}

void AnimatedObject::Advance()
{
	if (numFrames > 0)
	{
		currentFrame++;
		if (currentFrame >= numFrames)
			currentFrame = 0;
	}
}

void AnimatedObject::SetNumFrames(int n)
{
	if (n >= 0)
	{
		numFrames = n;
		if (n > 0)
			currentFrame = 0;
		else
			currentFrame = -1;
	}
}

void AnimatedObject::Draw()
{
	if(currentFrame >= 0)
		frames[currentFrame].draw(x, y);
}