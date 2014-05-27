#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "GlobalSettings.h"
#include "SceneEtang.h"
#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class EEtangApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    
    void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseWheel( MouseEvent event );

    
private:
    SceneEtang*                 _scene;
    params::InterfaceGlRef      _params;
};

void EEtangApp::setup() {
    setWindowSize(1280, 720);
    setFrameRate(60);
    setWindowPos(0, 0);
    srand(time(NULL));
    
    gl::enable( GL_TEXTURE_2D );
    
    _scene = new SceneEtang();
    _params = params::InterfaceGl::create( "Etang", Vec2i( 300, getWindowHeight()-30 ) );
    _params->addText("Touch Position : ");
    _params->addParam( "Touch X", &GlobalSettings::getInstance().pos.x);
    _params->addParam( "Touch Y", &GlobalSettings::getInstance().pos.y);
}

void EEtangApp::update() {
}

void EEtangApp::draw() {
	gl::clear( Color( 0, 0, 0 ) );
    
    _scene->render();
    _params->draw();
}



void EEtangApp::mouseWheel( MouseEvent event ){
}

void EEtangApp::mouseDown( MouseEvent event ){
    GlobalSettings::getInstance().pos.set(event.getPos());
    GlobalSettings::getInstance().isMouseDown = true;
}

void EEtangApp::mouseUp( MouseEvent event ){
    GlobalSettings::getInstance().pos.set(event.getPos());
    GlobalSettings::getInstance().isMouseDown = false;
}

void EEtangApp::mouseDrag( MouseEvent event ){
    GlobalSettings::getInstance().pos.set(event.getPos());
}

void EEtangApp::mouseMove( MouseEvent event ){
}

CINDER_APP_NATIVE( EEtangApp, RendererGl )
