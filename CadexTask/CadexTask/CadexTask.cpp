#include "pch.h"
#include <vector>
#include <iostream>
#include "MyCurves.h"
# define M_PI           3.14159265358979323846  

int main()
{
	double Rx, Ry, zStep, t = M_PI / 4;
	setlocale(LC_ALL, "ru");
	vector<Curves*> v;
	vector<Curves **>  v2;


	while (!(Helix::count > 0 && Circle::count > 2 && Ellipse::count > 2))
	{
		Rx = (int)(1 + rand() % 3);
		Ry = (int)(1 + rand() % 3);
		zStep = (int)(abs(-1 + rand() % 2));

		if (zStep == 0)
		{
			if (Rx == Ry)
			{
				v.push_back(new Circle());
			}
			else
			{
				v.push_back(new Ellipse());
			}
		}
		else
		{
			v.push_back(new Helix());
		}

		v.back()->Create(Rx, Ry, zStep);
		v.back()->Point(t);
	}


	int i = 0;
	bool swaps = false;
	Curves* ptr;
	double sum = 0;
	for (i; i < v.size(); i++) {
		if (v[i]->GetRadii() > 0)
		{
			v2.push_back(&v[i]);
			sum += v[i]->GetRadii();
		}
	}


	i = 0;
	while (i < Circle::count)
	{
		if (i + 1 != Circle::count && ((*v2[i])->GetRadii() > (*v2[i + 1])->GetRadii()))
		{
			ptr = (*v2[i]);
			(*v2[i]) = (*v2[i + 1]);
			(*v2[i + 1]) = ptr;
			swaps = true;
		}
		i++;
		if (i == Circle::count && swaps)
		{
			swaps = false;
			i = 0;
		}
	}

	cout << Helix::count <<"\t" <<Circle::count << "\t" << Ellipse::count << endl;
	system("pause");

}

