#include "Game.h"

bool flip = false;
int current = 1;

Game::Game() : window(VideoMode(800, 600), "OpenGL"), primatives(2)
{
	index = glGenLists(primatives);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);


	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0, 2.0, -5.0);
		glVertex3f(-2.0, -2.0, -5.0);
		glVertex3f(2.0, -2.0, -5.0);
	}
	glEnd();
	glEndList();

	glNewList(index + 1, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.2, 0.0, -2.0);
		glVertex3f(-2.0, -2.0, -2.0);
		glVertex3f(2.0, -2.0, -2.0);
	}
	glEnd();
	glEndList();
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!flip)
		{
			flip = true;
			current++;
			if (current > primatives)
			{
				current = 1;
			}
		}
		else
			flip = false;
	}

	if (flip)
	{
		rotationAngle += 0.005f;

		if (rotationAngle > 360.0f)
		{
			rotationAngle -= 360.0f;
		}
	}
	
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Resets the matrix for each primitive to prevent the scale, translate and rotate multiplications from becoming cumulative, ie creates an identity matrix.
	glLoadIdentity();
	//Used to rotate the camera about a primitive, first parameter is the angle of rotation you wish for it to rotate, the next 3 parameters are used to set which axis (X,Y,Z) you wish to rotate the camera around.
	glRotatef(rotationAngle, 0, 0, 1);
	//Used to set where in the cameras view the primitive is drawn, takes parameters for each axis(X,Y,Z), setting the z axis to a negative number makes it seem as if the primitive is further away from the camera.
	glTranslatef(0, 0, -10);
	//Used to scale the view of the camera about each axis, where 1 is the default size. 
	glScalef(1, 1, 6);
	cout << "Drawing Primative " << current << endl;
	glCallList(current);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

