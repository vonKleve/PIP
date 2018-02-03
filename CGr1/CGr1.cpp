#include "stdafx.h"
#include <iostream>
#include <vector>
#include "Polygon.h"

using namespace std;

bool BelongsTo(Polygon pol, Point *point)
{
	bool c = false;
	for (auto i = pol.begin(), j = pol.end() - 1; i != pol.end(); j = i++)
	{
		if (((point->y >= (*j)->y) && (point->y < (*i)->y)) || ((point->y < (*j)->y) && (point->y >= (*i)->y))
			&&
			(point->x > ((*j)->x - (*i)->x) * (point->y - (*i)->y) / ((*j)->y - (*i)->y) + (*i)->x))
		{
			c = !c;
		}
	}
	return c;
}

int main()
{
	vector<Point *> pp = { new Point(1,1), new Point(2,2), new Point(4,4), new Point(4,1) };
	Polygon pol(pp);
	//for (auto it = pol.begin(); it != pol.end(); it++)
	//{
	//	cout << (*it)->x << " " << (*it)->y << endl;
	//}
	//for (auto it : pol)
	//{
	//	cout << it->x << " " << it->y << endl;
	//}
	Point *point = new Point(4,2);
	cout << BelongsTo(pol, point) << endl;
	system("pause");
    return 0;
}

