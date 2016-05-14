# cpoc2
C implementation of my Doom clone made for DLC course

# Description
This is my attempt to really learn C/C++ (since I'm a Java developer) and OpenGL. For that I chose to refactor a project that I wrote in Java a couple of years ago in which I made an FPS with a software rasterizer made in Java.
I'm still pretty new to C/C++ ecosystem, so I grabbed most of the dependencies and how to make the project work from two sources:
1. http://www.opengl-tutorial.org/ 
2. https://github.com/fogleman/Craft

So probably there is a lot of things that I don't need (heightmaps for example) that in one moment or the other will be dropped.

# Building and Installation
I'm still trying to figure out how this works, and how to make a clean install, but basically the process should be something like this (after cloning the repo):

## Linux (Ubuntu)
`sudo apt-get install cmake make g++ libx11-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxrandr-dev libxext-dev libxi-dev libglew-dev xorg-dev libcurl4-openssl-dev`
`sudo apt-get build-dep glfw`

## Windows
I still need to test if this is working fine.
