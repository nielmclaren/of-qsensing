#pragma once
#include "ofMain.h"

class demoParticle{

	public:
		demoParticle();

		void reset();
		void update();
		void draw();		
		
		ofPoint pos;
		ofPoint vel;
		ofPoint frc;
		
		float drag; 
		float uniqueVal;
		float scale;
	
		float numSignallers;
};