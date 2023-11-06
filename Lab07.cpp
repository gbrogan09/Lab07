// Lab07.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>
using namespace std;
using namespace sf;
using namespace sfp;
int main()
{
	// Create our window and world with gravity 0,1
	RenderWindow window(VideoMode(800, 600), "Bounce");
	World world(Vector2f(0, 1));
	// Create the ball
	PhysicsCircle ball;
	ball.setCenter(Vector2f(400, 150));
	ball.setRadius(20);
	ball.setVelocity(Vector2f(0.25,0));
	world.AddPhysicsBody(ball);
	// Create the floor
	PhysicsRectangle floor;
	floor.setSize(Vector2f(800, 20));
	floor.setCenter(Vector2f(400, 590));
	floor.setStatic(true);
	world.AddPhysicsBody(floor);
	// Create the left wall
	PhysicsRectangle leftWall;
	leftWall.setSize(Vector2f(20, 580));
	leftWall.setCenter(Vector2f(10, 300));
	leftWall.setStatic(true);
	world.AddPhysicsBody(leftWall);
	// Create the left wall
	PhysicsRectangle rightWall;
	rightWall.setSize(Vector2f(20, 580));
	rightWall.setCenter(Vector2f(790, 300));
	rightWall.setStatic(true);
	world.AddPhysicsBody(rightWall);
	// Create the ceiling
	PhysicsRectangle ceiling;
	ceiling.setSize(Vector2f(800, 20));
	ceiling.setCenter(Vector2f(400, 10));
	ceiling.setStatic(true);
	world.AddPhysicsBody(ceiling);
	// Create the center block
	PhysicsRectangle centerBlock;
	centerBlock.setSize(Vector2f(40, 30));
	centerBlock.setCenter(Vector2f(400, 300));
	centerBlock.setStatic(true);
	world.AddPhysicsBody(centerBlock);

	int thudCount(0);
	int bangCount(0);
	floor.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "thud " << thudCount << endl;
		thudCount++;
		};
	leftWall.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "thud " << thudCount << endl;
		thudCount++;
		};
	rightWall.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "thud " << thudCount << endl;
		thudCount++;
		};
	ceiling.onCollision = [&thudCount](PhysicsBodyCollisionResult result) {
		cout << "thud " << thudCount << endl;
		thudCount++;
		};
	centerBlock.onCollision = [&bangCount](PhysicsBodyCollisionResult result) {
		cout << "bang " << bangCount << endl;
		bangCount++;
		};
	Clock clock;
	Time lastTime(clock.getElapsedTime());
	while (bangCount < 3) {
		// calculate MS since last frame
		Time currentTime(clock.getElapsedTime());
		Time deltaTime(currentTime - lastTime);
		int deltaTimeMS(deltaTime.asMilliseconds());
		if (deltaTimeMS > 30) {
			world.UpdatePhysics(deltaTimeMS,1);
			lastTime = currentTime;
		}
		//if bangCount == 3
		//{
		//	exit(0);
		//}
		window.clear(Color(0, 0, 0));
		window.draw(ball);
		window.draw(floor);
		window.draw(leftWall);
		window.draw(rightWall);
		window.draw(ceiling);
		window.draw(centerBlock);
		window.display();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
