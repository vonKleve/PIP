#include "stdafx.h"
#include <iostream>
#include <vector>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "Polygon.h"

using namespace std;

bool BelongsTo(UPolygon &pol, UPoint *point)
{
	bool c = false;
	for (auto i = pol.begin(), j = pol.end() - 1; i != pol.end(); j = i++)
	{
		if ((((point->y >= (*j)->y) && (point->y < (*i)->y)) || ((point->y < (*j)->y) && (point->y >= (*i)->y)))
			&&
			(point->x > (((*j)->x - (*i)->x) * (point->y - (*i)->y) / ((*j)->y - (*i)->y) + (*i)->x)))
		{
			c = !c;
		}
	}
	return c;
}

UPolygon *ppol;
UPoint *ppoint;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINE_LOOP);
	for (auto it : *ppol)
	{
		glColor3f(1, 1, 1);
		glVertex2d(it->x * 100, it->y * 100);
	}
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 0);
	glVertex2d(0, ppoint->y * 100);
	glVertex2d(ppoint->x * 100, ppoint->y * 100);
	glVertex2d(ppoint->x * 100, 0);
	glVertex2d(0, 0);
	glEnd();

	glutSwapBuffers();
}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char *argv[])
{
	size_t n;
	cout << "Enter quantity of vertices: ";
	cin >> n;
	vector<UPoint *> pp; //= { new Point(1,1), new Point(2,3), new Point(3,3), new Point(4,1) };
	cout << "Enter vertices\n";
	for (int i = 0; i < n; i++)
	{
		UPoint *point = new UPoint(1, 1);
		cin >> point->x >> point->y;
		pp.push_back(point);
	}
	UPolygon pol(pp);
	ppol = &pol;
	UPoint *point = new UPoint(2,2);
	ppoint = point;
	cout << "Enter tested point\n";
	cin >> point->x >> point->y;
	cout << "1 indicates that point is in polygon, 0 - vice versa\n";
	cout << BelongsTo(pol, point) << endl;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("Task 1");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	glutMainLoop();

	system("pause");
    return 0;
}

