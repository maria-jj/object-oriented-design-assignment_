#pragma once


class ofApp : public ofBaseApp{

	public:
		//v3
		ofImage hmapImage;
		ofImage bgImage;
		AnimatedObject player;
		GameObject enemy;
		Physics phys;

		/*int groundLevel;
		int groundLevelRelative;
		void SetGroundLevels(int x);*/


		bool keyDown[255]; //all keys 

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
