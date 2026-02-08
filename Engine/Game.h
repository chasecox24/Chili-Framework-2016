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
	/********************************/
private:
	// these are data members that make up the object (or vairables that describe the object)
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
	int x = 400;
	int y = 300;
	///********************************/
};