#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        ofPolyline lineWZasWidth;    // store the width in the "z" value of the line;
        ofPolyline line;             // no z in the width, 

    
        void drawPolyineThickWZ( ofPolyline & line);
        void drawPolyineThick( ofPolyline & line, int thickness);
    


};
