#include <iostream>
#include <math.h>
#include <stdlib.h>
#include "graphics.h"

using namespace std;

class Triangle
{
public:
	int x1, y1, x2, y2, x3, y3;

	Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
		this->x3 = x3;
		this->y3 = y3;
	}

	void MoveX(int n)
	{
		this->x1 += n;
		this->x2 += n;
		this->x3 += n;
	}

	void MoveY(int n)
	{
		this->y1 += n;
		this->y2 += n;
		this->y3 += n;
	}

	void Rotate0()
	{
		int mid = x1 + x2 + x3 + y1 + y2 + y3;
		mid /= 6;

		this->x1 -= mid;
		this->x2 -= mid;
		this->x3 -= mid;
		this->y1 -= mid;
		this->y2 -= mid;
		this->y3 -= mid;

		x1 = x1 * cos(0.0176) - y1 * sin(0.0176);
		y1 = x1 * sin(0.0176) - y1 * cos(0.0176);
		x2 = x2 * cos(0.0176) - y2 * sin(0.0176);
		y2 = x2 * sin(0.0176) - y2 * cos(0.0176);
		x2 = x2 * cos(0.0176) - y2 * sin(0.0176);
		y2 = x2 * sin(0.0176) - y2 * cos(0.0176);

		this->x1 += mid;
		this->x2 += mid;
		this->x3 += mid;
		this->y1 += mid;
		this->y2 += mid;
		this->y3 += mid;
	}

	void Rotate9()
	{
		int mid = x1 + x2 + x3 + y1 + y2 + y3;
		mid /= 6;

		this->x1 -= mid;
		this->x2 -= mid;
		this->x3 -= mid;
		this->y1 -= mid;
		this->y2 -= mid;
		this->y3 -= mid;

		x1 = x1 * cos(-0.0176) - y1 * sin(-0.0176);
		y1 = x1 * sin(-0.0176) - y1 * cos(-0.0176);
		x2 = x2 * cos(-0.0176) - y2 * sin(-0.0176);
		y2 = x2 * sin(-0.0176) - y2 * cos(-0.0176);
		x2 = x2 * cos(-0.0176) - y2 * sin(-0.0176);
		y2 = x2 * sin(-0.0176) - y2 * cos(-0.0176);

		this->x1 += mid;
		this->x2 += mid;
		this->x3 += mid;
		this->y1 += mid;
		this->y2 += mid;
		this->y3 += mid;
	}

	void scale(float k)
	{
		int mid = x1 + x2 + x3 + y1 + y2 + y3;
		mid /= 6;

		this->x1 -= mid;
		this->x2 -= mid;
		this->x3 -= mid;
		this->y1 -= mid;
		this->y2 -= mid;
		this->y3 -= mid;

		x1 *= k;
		x2 *= k;
		x3 *= k;
		y1 *= k;
		y2 *= k;
		y3 *= k;

		this->x1 += mid;
		this->x2 += mid;
		this->x3 += mid;
		this->y1 += mid;
		this->y2 += mid;
		this->y3 += mid;
	}

	void lines()
	{
		moveto(x1, y1);
		lineto(x2, y2);
		moveto(x2, y2);
		lineto(x3, y3);
		moveto(x3, y3);
		lineto(x1, y1);
	}

private:

};

Triangle triangle(150.0, 113.39746, 100.0, 200.0, 200.0, 200.0);

void input()
{
	char c = toupper(getch());

	if (c == '9')
		triangle.Rotate9();

	else if (c == '0')
		triangle.Rotate0();

	else if (c == 72)
		triangle.MoveY(-10);

	else if (c == 80)
		triangle.MoveY(10);

	else if (c == 75)
		triangle.MoveX(-10);

	else if (c == 77)
		triangle.MoveX(10);

	else if (c == '-')
		triangle.scale(0.5);

	else if (c == '+')
		triangle.scale(2);

	setactivepage(0);
	clearviewport();
	triangle.lines();
	setvisualpage(0);
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	initwindow(1000, 500);
	triangle.lines();
	while (1)
		input();
}