//
//  SceneEtang.cpp
//  Etang
//
//  Created by Yiwen on 05/07/2014.
//
//

#include "SceneEtang.h"
#include "Utils.h"


using namespace etang;
using namespace bongiovi::utils;

SceneEtang::SceneEtang(ci::app::WindowRef window) : Scene(window) {
    _initTextures();
    _initViews();
}


void SceneEtang::_initTextures() {
    _texDot = Utils::createTexture("common/dot.png");
}


void SceneEtang::_initViews() {
    _viewDot            = new ViewDots();
}


void SceneEtang::render() {
    _viewDot->render();
}