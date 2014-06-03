//
//  ViewFish.cpp
//  EEtang
//
//  Created by Yiwen on 27/05/2014.
//
//

#include "ViewFish.h"
#include "MeshUtils.h"

ViewFish::ViewFish() : View("shaders/fish.vert", "shaders/fish.frag") {
    _init();
}

ViewFish::ViewFish(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewFish::_init() {
    mesh = bongiovi::MeshUtils::createPlane(.02, 1);
}


void ViewFish::render(gl::TextureRef texture, Vec3f pos) {
    shader->bind();
    shader->uniform("texture", 0);
    shader->uniform("position", pos);
    shader->uniform("ratio", float(getWindowWidth())/(float(getWindowHeight())) );
    texture->bind();
    gl::draw(mesh);
    texture->unbind();
    shader->unbind();
}