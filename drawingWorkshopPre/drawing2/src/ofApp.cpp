#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

    
    for (int i = 0; i < pts.size(); i++){
        //pts[i].x += ofRandom(-1,1);
        //pts[i].y += ofRandom(-1,1);
    }
    
}



//--------------------------------------------------------------
void ofApp::draw(){

    ofSetLineWidth(1);
    
//    ofNoFill();
//    ofBeginShape();
//    for (int i = 0; i < pts.size(); i++){
//        ofVertex( pts[i] );
//    }
//    ofEndShape();
    
    
    ofNoFill();
//    for (int i = 0; i+1 < pts.size(); i++){
//        
//        ofPoint offset;
//        offset.set( ofRandom(-10, 10),
//                   ofRandom(-10, 10));
//        
//        ofLine( pts[i] + offset, pts[i+1] + offset);
//    }
    
//    for (int i = 0; i+10 < pts.size(); i++){
//        ofLine( pts[i], pts[i + 10]);
//    }

      for (int i = 0; i < pts.size(); i++){
          for (int j = 0; j < pts.size(); j++){
              if( i != j){
                  float dist = (pts[i] - pts[j]).length();
                  if (dist < 40){
                      ofLine(pts[i], pts[j]);
                  }
              }
          }
      }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

    ofPoint pt;
    pt.set(x,y);
    pts.push_back(pt);
    
    // printf RUN DMC
    // cout KANYE WEST
    // cout << pts.size() << endl;
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    
    pts.clear();
    ofPoint pt;
    pt.set(x,y);
    pts.push_back(pt);
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

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
