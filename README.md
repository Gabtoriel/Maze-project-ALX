# alx-portfolio_project : MAZE Project

## A portfolio project for ALX Software Engineering program.
The goal of this project is to create a game in 3D using raycasting! The maze game is like a maze where you try to exit the maze by overcoming obstacles.

## Technologies in use
* SDL2 Technologies: Simple Direct Layer(SDL2): is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playback software, emulators, and popular games including Valve’s award winning catalog and many Humble Bundle games. SDL officially supports Windows, mac 0S X, Linux, ios, and Android.
SDL is written in C, works natively with C++, and there are bindings available for several other languages, it gives an api(Application Programmer's Interface) for processing videos and audios.
* Ray-Casting: Ray-casting is a technique that transform a limited form of data (a very simplified map or floor plan) into a 3D projection by tracing rays from the view point into the viewing volume (LaMothe 942). The important point to remember is that ray-casting “traces rays backward from viewer’s eye to objects.”
 
## Installation
* Clone the repo
[Github](https://github.com/Gabtoriel/Maze-project-ALX.git)

## Usage
* Compile using make
* Execute make run
* Use up and down arrow keys to move forward and backward (keys w and s serve the same function)
* Use right and left arrow keys to turn the camera arround (keys d and a serve the same function)
* On exit press (Esc key)

## Compliation
* $ gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm -o maze `sdl2-config --cflags` `sdl2-config --libs`;

## Contributions
Contributions are highly welcomed.

## Authors
Chibuike Victor Gabriel(gabtorielvix@gmail.com)
