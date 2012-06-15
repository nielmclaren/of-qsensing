#include "testApp.h"

void testApp::setup(){
	ofSetVerticalSync(true);
	
	int num = 500;
	p.assign(num, demoParticle());
	resetParticles();
}

void testApp::resetParticles(){
	for(int i = 0; i < p.size(); i++){
		p[i].reset();
	}	
}

void testApp::update(){
	for(int i = 0; i < p.size(); i++){
		p[i].update();
		
		for (int j = i + 1; j < p.size(); j++) {
			ofPoint delta = p[i].pos - p[j].pos;
			float dist = delta.length();
			if (dist < 20) {
				p[i].numSignallers += p[j].numSignallers;
				p[j].numSignallers += p[i].numSignallers;
			}
		}
		
		p[i].numSignallers *= 0.05;
	}
}

void testApp::draw(){
    ofBackgroundGradient(ofColor(60,60,60), ofColor(10,10,10));

	for(int i = 0; i < p.size(); i++){
		p[i].draw();
	}
}

void testApp::keyPressed(int key){
	if( key == ' ' ){
		resetParticles();
	}
}

void testApp::keyReleased(int key){

}

void testApp::mouseMoved(int x, int y ){

}

void testApp::mouseDragged(int x, int y, int button){

}

void testApp::mousePressed(int x, int y, int button){

}

void testApp::mouseReleased(int x, int y, int button){

}

void testApp::windowResized(int w, int h){

}

void testApp::gotMessage(ofMessage msg){

}

void testApp::dragEvent(ofDragInfo dragInfo){ 

}