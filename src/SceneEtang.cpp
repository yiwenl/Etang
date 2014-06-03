//
//  SceneEtang.cpp
//  EEtang
//
//  Created by Yiwen on 27/05/2014.
//
//

#include "SceneEtang.h"

#include "Utils.h"

using namespace bongiovi::utils;

SceneEtang::SceneEtang() {
    _fishes = new FishController();
    _initTextures();
    _initViews();
}


void SceneEtang::_initTextures() {
    _texBg      = Utils::createTexture("common/etangBg.jpg");
    _texDot     = Utils::createTexture("common/dot.png");
}


void SceneEtang::_initViews() {
    _vBg            = new ViewBg();
    _vFish          = new ViewFish();
}


void SceneEtang::render() {
    _fishes->update();
    
    gl::clear( Color( 0, 0, 0 ) );
    gl::setMatrices(*_cameraOrtho);
    
    _vBg->render(_texBg);
    
    vector<Fish*> fishes = _fishes->getFishes();
    vector<Fish*>::iterator it;
    Vec3f loc;
    for( it = fishes.begin(); it!= fishes.end(); it++) {
        loc.set((*it)->location);
        loc.x = (loc.x / (float)getWindowWidth() - .5) * 2.0;
        loc.y = (loc.y / (float)getWindowHeight() - .5) * 2.0;
        _vFish->render(_texDot, loc);
    }
}