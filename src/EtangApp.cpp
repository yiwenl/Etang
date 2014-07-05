#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "SceneEtang.h"
#include "Model.h"
#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace etang;

class EtangApp : public AppNative {
  public:
	void setup();
	void update();
	void draw();
    void mouseDown( MouseEvent event );
    void mouseUp( MouseEvent event );
    void mouseDrag( MouseEvent event );
    void mouseMove( MouseEvent event );
    void mouseWheel( MouseEvent event );
    
    private :
    SceneEtang*                 _scene;
    params::InterfaceGlRef      _params;
    
};

void EtangApp::setup()
{
    setWindowSize(1280, 720);
    setFrameRate(30);
    setWindowPos(0, 0);
    srand(time(NULL));
    
    gl::enable( GL_TEXTURE_2D );
    gl::enable( GL_TEXTURE_RECTANGLE_ARB );
    
    gl::enable( GL_VERTEX_PROGRAM_POINT_SIZE );
    gl::enable( GL_DEPTH_TEST );
    gl::enable( GL_CULL_FACE );
    gl::enable( GL_POINT_SMOOTH );
    gl::enableAlphaBlending();

    
    _scene          = new SceneEtang();
    _params         = params::InterfaceGl::create( "Etang", Vec2i( 300, getWindowHeight()-30 ) );
    Model::getInstance();
}

void EtangApp::update()
{
    _scene->update();
}

void EtangApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) );
    
    _scene->render();
    _params->draw();
}





void EtangApp::mouseWheel( MouseEvent event ){
    _scene->cameraDistance -= event.getWheelIncrement() * 2.0f;
}

void EtangApp::mouseDown( MouseEvent event ){
    _scene->sceneQuat->mouseDown(event.getPos());
}

void EtangApp::mouseUp( MouseEvent event ){
    _scene->sceneQuat->mouseUp(event.getPos());
}

void EtangApp::mouseDrag( MouseEvent event ){
    _scene->sceneQuat->mouseDrag(event.getPos());
}

void EtangApp::mouseMove( MouseEvent event ){
    _scene->sceneQuat->mouseMove(event.getPos());
}


CINDER_APP_NATIVE( EtangApp, RendererGl )
