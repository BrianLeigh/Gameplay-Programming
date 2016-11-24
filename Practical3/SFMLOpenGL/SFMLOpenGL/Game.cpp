#include "Game.h"

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

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
}

void Game::update()
{
	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	drawPoints();
	drawLines();
	drawLineStrip();
	drawLineLoop();
	drawTriangle();
	drawTriangleStrip();
	drawTriangleFan();
	drawQuads();
	drawQuadStrip();
	drawPolygon();
	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}
void Game::drawPoints()
{
	glPointSize(20);
	glBegin(GL_POINTS);
	{
		glColor3f(1, 4, 1);
		glVertex3d(-0.4, 0.3, -1.0);
		glVertex3d(-0.4, 0.4, -1.0);
	}
	glEnd();
}
void Game::drawLines()
{
	glLineWidth(10);
	glBegin(GL_LINES);
	{
		glColor3f(0.7f, 0.4f, 0.2f);
		glVertex3d(-0.35, 0.3, -1.0);
		glVertex3d(-0.35, 0.4, -1.0);
	}
	glEnd();
}
void Game::drawLineStrip()
{
	glLineWidth(20);
	glBegin(GL_LINE_STRIP);
	{
		glColor3f(0.1f, 0.4f, 0.7f);

		glVertex3d(-0.25, 0.3, -1.0);
		glVertex3d(-0.25, 0.4, -1.0);
		glVertex3d(-0.15, 0.4, -1.0);
	}
	glEnd();
}
void Game::drawLineLoop()
{
	glLineWidth(2.5);
	glBegin(GL_LINE_LOOP);
	{
		glColor3f(0.0f, 0.5f, 0.5f);

		glVertex3d(-0.14, 0.4, -1.0);
		glVertex3d(-0.14, 0.3, -1.0);
		glVertex3d(0.0, 0.3, -1.0);
		glVertex3d(0.0, 0.4, -1.0);

	}
	glEnd();
}
void Game::drawTriangle()
{
	glBegin(GL_TRIANGLES);
	{
		glColor3f(0.0f, 0.5f, 0.0f);
		glVertex3d(0.1, 0.4, -1.0);
		glVertex3d(0.05, 0.3, -1.0);
		glVertex3d(0.15, 0.3, -1.0);
	}
	glEnd();
}
void Game::drawTriangleStrip()
{
	glBegin(GL_TRIANGLE_STRIP);
	{
		glColor3f(0.1f, 0.8f, 0.5f);
		glVertex3d(0.2, 0.4, -1.0);
		glVertex3d(0.25, 0.3, -1.0);
		glVertex3d(0.3, 0.4, -1.0);
		glVertex3d(0.35, 0.3, -1.0);
	}
	glEnd();
}
void Game::drawTriangleFan()
{
	glBegin(GL_TRIANGLE_FAN);
	{
		glColor3f(0.1f, 0.8f, 0.5f);
		glVertex3d(-0.4, 0.1, -1.0);
		glVertex3d(-0.39, 0.15, -1.0);
		glVertex3d(-0.355, 0.135, -1.0);
		glVertex3d(-0.35, 0.1, -1.0);
		glVertex3d(-0.36, 0.07, -1.0);
		glVertex3d(-0.39, 0.06, -1.0);
	}
	glEnd();
}
void Game::drawQuads()
{
	// Render a cube
	glBegin(GL_QUADS);
	{
		glColor3f(0.3f, 0.3f, 0.9f);
		glVertex3d(-0.3, 0.05, -1.0);
		glVertex3d(-0.3, 0.15, -1.0);
		glVertex3d(-0.2, 0.15, -1.0);
		glVertex3d(-0.2, 0.05, -1.0);
	}
	glEnd();
}
void Game::drawQuadStrip()
{
	glBegin(GL_QUAD_STRIP);
	{
		glColor3f(0.8f, 0.0f, 0.9f);
		glVertex3d(-0.15, 0.1, -1.0);
		glVertex3d(-0.15, 0.15, -1.0);
		glVertex3d(0, 0.1, -1.0);
		glVertex3d(0, 0.15, -1.0);
		glVertex3d(0.005, 0.1, -1.0);
		glVertex3d(0.005, 0.15, -1.0);
	}
	glEnd();
}
void Game::drawPolygon()
{
	glBegin(GL_POLYGON);
	{
		glColor3f(0.6f, 0.15f, 0.9f);
		glVertex3d(0.1, 0.15, -1.0);
		glVertex3d(0.05, 0.1, -1.0);
		glVertex3d(0.05, 0, -1.0);
		glVertex3d(0.1, -0.05, -1.0);
		glVertex3d(0.15, 0, -1.0);
		glVertex3d(0.15, 0.1, -1.0);
	}
	glEnd();
}
