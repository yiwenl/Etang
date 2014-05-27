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
    _initTextures();
    _initViews();
}


void SceneEtang::_initTextures() {
    _texBg = Utils::createTexture("common/etangBg.jpg");
}


void SceneEtang::_initViews() {
    _vBg            = new ViewBg();
}


void SceneEtang::render() {
    gl::clear( Color( 0, 0, 0 ) );
    
    gl::setMatrices(*_cameraOrtho);
    _vBg->render(_texBg);
}