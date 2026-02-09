/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"

class Game
{
public:
	// member functions that make up the behavior of the object (or functions that describe the object)
	Game(class MainWindow& wnd); // constructor that tells us what code is it to be executed when the object is created
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go(); // this is the function that will be called in the while loop in win main, it will run forever until the user quits the program (60 times a second)
private:
	void ComposeFrame(); //drawl the game frame we show the user
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawBox(int x, int y, int r, int g, int b);
	void DrawCrosshair(int x, int y, int r, int g, int b);
	/********************************/
private:
	// these are data members that make up the object (or vairables that describe the object)
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */

	//For box in a set position
	int xFixed = 400;
	int yFixed = 400;
	bool colliding = false;

	//For user controlled shape
	int x = 400;
	int y = 300;
	int vx = 0; // velocity in x direction
	int vy = 0; // velocity in y direction
	int gb = 255; // green and blue
	bool controlIsPressed = false; // Color changer
	bool shapeIsChanged = false; // tells us whether it is a box or a crosshair
	bool inhitbitUp = false; // these variables will update the velocity once when the key is first pressed AND
	bool inhitbitDown = false; //Not update the velocity every single frame that the key is held down (LESSON 9)
	bool inhitbitLeft = false;
	bool inhitbitRight = false;
	///********************************/
};