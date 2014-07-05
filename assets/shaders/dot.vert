#version 120

void main() {
    vec4 pos        = gl_Vertex;
    
    gl_PointSize    = 15.0;
    gl_Position     = gl_ModelViewProjectionMatrix * pos;
}