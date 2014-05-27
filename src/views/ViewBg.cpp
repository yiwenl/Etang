//
//  ViewBg.cpp
//  EEtang
//
//  Created by Yiwen on 27/05/2014.
//
//

#include "ViewBg.h"
#include "MeshUtils.h"


ViewBg::ViewBg() : View("shaders/copy.vert", "shaders/copy.frag") {
    _init();
}

ViewBg::ViewBg(string vsPath, string fsPath) : View(vsPath, fsPath) {
    _init();
}


void ViewBg::_init() {
    mesh = bongiovi::MeshUtils::createPlane(2, 1);
}


void ViewBg::render(gl::TextureRef texture) {
    shader->bind();
    shader->uniform("texture", 0);
    texture->bind();
    gl::draw(mesh);
    texture->unbind();
    shader->unbind();
}


void ViewBg::render(gl::Texture texture) {
    shader->bind();
    shader->uniform("texture", 0);
    texture.bind();
    gl::draw(mesh);
    texture.unbind();
    shader->unbind();
}