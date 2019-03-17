#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofNoFill();
	ofEnableDepthTest();
	ofSetLineWidth(3);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	int radius = 80;
	int len = 20;
	float deg_span = 4;
	int span = 240;
	for (int y = -span; y <= span; y += span) {

		for (int x = -span; x <= span; x += span) {

			ofPushMatrix();
			ofTranslate(x, y);

			for (int deg = 0; deg < 360; deg += deg_span) {

				ofBeginShape();

				auto location = glm::vec3(radius * cos((deg - deg_span * 0.5)  * DEG_TO_RAD), radius * sin((deg - deg_span * 0.5) * DEG_TO_RAD), 0);
				auto rotation_y = glm::rotate(glm::mat4(), ofMap(ofNoise(x + location.x * 0.005, y + location.y * 0.005, ofGetFrameNum() * 0.01), 0, 1, -PI, PI), glm::vec3(0, 1, 0));
				location = glm::vec4(location, 0) * rotation_y;
				ofVertex(location);

				location = glm::vec3(radius * cos((deg + deg_span * 0.5)  * DEG_TO_RAD), radius * sin((deg + deg_span * 0.5) * DEG_TO_RAD), 0);
				rotation_y = glm::rotate(glm::mat4(), ofMap(ofNoise(x + location.x * 0.005, y + location.y * 0.005, ofGetFrameNum() * 0.01), 0, 1, -PI, PI), glm::vec3(0, 1, 0));
				location = glm::vec4(location, 0) * rotation_y;
				ofVertex(location);

				location = glm::vec3((radius - len) * cos((deg + deg_span * 0.5)  * DEG_TO_RAD), (radius - len) * sin((deg + deg_span * 0.5) * DEG_TO_RAD), 0);
				rotation_y = glm::rotate(glm::mat4(), ofMap(ofNoise(x + location.x * 0.005, y + location.y * 0.005, ofGetFrameNum() * 0.01), 0, 1, -PI, PI), glm::vec3(0, 1, 0));
				location = glm::vec4(location, 0) * rotation_y;
				ofVertex(location);

				location = glm::vec3((radius - len) * cos((deg - deg_span * 0.5)  * DEG_TO_RAD), (radius - len) * sin((deg - deg_span * 0.5) * DEG_TO_RAD), 0);
				rotation_y = glm::rotate(glm::mat4(), ofMap(ofNoise(x + location.x * 0.005, y + location.y * 0.005, ofGetFrameNum() * 0.01), 0, 1, -PI, PI), glm::vec3(0, 1, 0));
				location = glm::vec4(location, 0) * rotation_y;
				ofVertex(location);

				ofEndShape();
			}

			ofPopMatrix();
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}