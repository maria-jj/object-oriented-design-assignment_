#include "Main.h"

//this function updates the ground level variable based on a given X
//note that player.y is the top-left of the player (its head) and can't be compared to the ground level 
//so we define a groundLevelRelative that is higher then ground by player height
//void ofApp::SetGroundLevels(int x)
//{
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
//	groundLevelRelative = groundLevel - player.height;  
//}

//--------------------------------------------------------------
void ofApp::setup(){
	bgImage.load("images/map.png");

	enemy.x = 310;
	enemy.y = 250;
	enemy.GetImage()->load("images/l0.gif");

	player.x = 10;
	player.y = 660 - 152; // ground level minus character height 
	player.GetImage()->load("images/r0.gif");
	player.SetNumFrames(3);
	player.frames[0].load("images/r0.gif"); //right
	player.frames[1].load("images/r1.gif");
	player.frames[2].load("images/r2.gif");
	player.frames[3].load("images/l0.gif"); //left
	player.frames[4].load("images/l1.gif");
	player.frames[5].load("images/l2.gif");

	//SetGroundLevels(player.x);
	//phys.SetGroundLevels(player.x,player.height);  

	for (int i = 0; i < 255; i++)
		keyDown[i] = false;

	ofSetFrameRate(40);
}

//--------------------------------------------------------------
void ofApp::update(){

	int targetX = player.x;
	if (keyDown[OF_KEY_RIGHT] == true)
	{
		player.Advance();//animation
		//player.x++;
		//A3
		targetX+=2;
	}
	if (keyDown[OF_KEY_LEFT] == true)
	{
		player.Advance(); //animation
		//player.x--;
		//A3
		targetX-=2;
	}

	//A3
	//move the player
	//phys.SetGroundLevels(targetX, player.height);
	//int dy = phys.groundLevelRelative - player.y;
	//if (dy > -5) //we can move if groundlevel is not more than 5 higher
	//{
	//	player.x = targetX;
	//	if (dy < 5)
	//		player.y += dy;
	//}
	//else										//stay where we are
	//	phys.SetGroundLevels(player.x, player.height);
	//*********************phys.Move(targetX, player.x, player.y, player.height);
	

	//jump command
	if (keyDown[' '] == true && player.jump == false)
	{
		player.jump = true;
		player.t = 0;
		player.y0 = player.y;
		player.v0 = JUMP_SPEED;
	}
	phys.Move(targetX, player.x, player.y, player.height, player.jump, player.t, player.v0, player.y0 );
	//*******************phys.Jump(player.jump, player.t, player.y0, player.v0, player.y/*, keyDown*/);
	////jump and fall
	//if (player.jump == true)
	//{
	//	//move
	//	player.y = player.y0 - player.v0 * player.t
	//		+ 0.5 * GRAVITY * player.t*player.t;
	//	//advance time
	//	player.t++;  // or +=0.2 if you want slower movement
	//	//reached the ground?
	//	if (player.y > phys.groundLevelRelative)
	//	{
	//		player.y = phys.groundLevelRelative;
	//		player.jump = false;
	//	}
	//}
	//else //see if we have walked off a cliff and have to fall
	//{
	//	if (player.y < phys.groundLevelRelative)
	//	{
	//		player.jump = true;
	//		player.t = 0;
	//		player.y0 = player.y;
	//		player.v0 = 0;
	//	}
	//}


	///////////////////////////////////////////////////////////
}

//--------------------------------------------------------------
void ofApp::draw(){
	bgImage.draw(0, 0);

	player.Draw();
	enemy.Draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	keyDown[key] = true;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	keyDown[key] = false;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
