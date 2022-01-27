// rayLibrary_Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//Add the raylibrary file.
#include <raylib.h>
int main()
{
	//Update cycle
	int posX = 100;
	int posY = 300;
	InitWindow(800, 600, "New Window");
	while (!WindowShouldClose())
	{
		//Draw cycle
		//Controls to move the circle.
		if (IsKeyDown(KEY_LEFT))
			posX--;
		if (IsKeyDown(KEY_RIGHT))
			posX++;
		if (IsKeyDown(KEY_UP))
			posY--;
		if (IsKeyDown(KEY_DOWN))
			posY++;
		//Draw the background and circle object.
		BeginDrawing();
		ClearBackground(ORANGE);
		DrawCircle(posX, posY, 60, WHITE);
		EndDrawing();
		
	}
	CloseWindow();
}


