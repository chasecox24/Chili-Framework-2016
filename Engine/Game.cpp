/******************************************************************************************
 *	Chili DirectX Framework Version 16.07.20											  *
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd)
{
}

void Game::Go()
{
	gfx.BeginFrame();
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
}

// THIS IS IN A WHILE LOOP INSIDE WIN MAIN SO IT WILL RUN FOREVER UNTIL THE USER QUITS THE PROGRAM (60 TIMES A SECOND)

void Game::ComposeFrame()
//  SHIFT+ CTR + SPACE // GIVE TOOLTIPS
//  SHIFT+ CTR + SPACE // GIVE TOOLTIPS
//  CTRL + K THEN CTRL + D // FORMATS CODE

{				//800x, 600y    RGB      
	//gfx.PutPixel(695, 500, 255,gb,gb); // put a pixel on the screen

	// Set variables have a lifespan called scope (LESSON 7)
	int x = 400;
	int y = 300;
	const int boxWidth = 10;
	const int boxHeight = 10;
	int gb = 255; // green and blue

	// MOVE THE PIXELS ON THE SCREEN
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		x = x + 10; // 2nd level of scope
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		x = x - 10;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		y = y - 10;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		y = y + 10;
	}
	// CHANGE THE COLOR OF THE PIXELS
	if (wnd.kbd.KeyIsPressed(VK_CONTROL))
	{
		gb = 0;
	}

	//object.member.function(parameter)
//const bool condition = wnd.kbd.KeyIsPressed( VK_UP); // this will stay true as long as the up arrow key is pressed

	if (wnd.kbd.KeyIsPressed(VK_SHIFT)) // this is a branch that will execute depending on the value of the condition
	{
		// Draw the box outline using a for loop // I was lazy to not put the pixels one by one
		for (int i = 0; i < boxWidth; i++) {
			gfx.PutPixel(x + i, y, 255, gb, gb);           // top edge
			gfx.PutPixel(x + i, y + boxHeight - 1, 255, gb, gb); // bottom edge
		}

		for (int j = 0; j < boxHeight; j++) {
			gfx.PutPixel(x, y + j, 255, gb, gb);           // left edge
			gfx.PutPixel(x + boxWidth - 1, y + j, 255, gb, gb); // right edge
		}
	}
	else // default is to draw a crosshair
	{
		// left and right
		gfx.PutPixel(-5 + x, y, 255, gb, gb);
		gfx.PutPixel(-4 + x, y, 255, gb, gb);
		gfx.PutPixel(-3 + x, y, 255, gb, gb);
		gfx.PutPixel(3 + x, y, 255, gb, gb);
		gfx.PutPixel(4 + x, y, 255, gb, gb);
		gfx.PutPixel(5 + x, y, 255, gb, gb);

		//// top and bottom
		gfx.PutPixel(x, -5 + y, 255, gb, gb);
		gfx.PutPixel(x, -4 + y, 255, gb, gb);
		gfx.PutPixel(x, -3 + y, 255, gb, gb);
		gfx.PutPixel(x, 3 + y, 255, gb, gb);
		gfx.PutPixel(x, 4 + y, 255, gb, gb);
		gfx.PutPixel(x, 5 + y, 255, gb, gb); // 3D graphics transfer vertices in order to move graphics
		//  SHIFT+ CTR + SPACE // GIVE TOOLTIPS
	}
}
