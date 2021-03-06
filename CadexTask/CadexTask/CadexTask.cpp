#include "pch.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>
#include <typeinfo>
#include "MyCurves.h"
# define M_PI           3.14159265358979323846  

using namespace std; 

int main()
{
	double Rx, Ry, zStep;
	double t = 0;
	double sum = 0;
	setlocale(LC_ALL,"ru");
	vector<shared_ptr<Curve>> v;
	enum {circle, ellipse, helix};
	int countCircle = 0, countHelix = 0, countEllipse = 0;
	
	
	while (!(countHelix > 5 && countCircle > 6 && countEllipse > 6))/// можно получать c argv[]
	{
		int type = rand() % 3;

		if (type == circle)
		{
				Rx = rand() % 3 + 1; 
				v.push_back(make_shared<Circle>(Rx));
				countCircle++;
		}
		
		if ( type == ellipse )
		{
			while (Rx == Ry) 
			{
				Rx = rand() % 3 + 1;
				Ry = rand() % 3 + 1;
			}
				v.push_back(make_shared<Ellipse>(Rx,Ry));
				countEllipse++;
		}
		
		if ( type == helix )
		{
			Rx = rand() % 3 + 1;
			Ry = rand() % 3 + 1;
			zStep = rand() % 3 + 1;

			v.push_back(make_shared<Helix>(Rx,Ry,zStep));
			countHelix++;
		}

			
		v.back()->Point(t);
		
	}

	//vector<Circle*>  v2;
	vector<shared_ptr<Curve>> v2;

	for (shared_ptr<Curve> c : v)
	{
		//const auto& ti = typeid(*c);
		//cout << ti.name()<< " hash " << ti.hash_code() << endl;
		if (typeid(*c) == typeid(Circle))			
			//v2.emplace_back((Circle*) c.get());
			v2.emplace_back(c);
	}
	
	
	//sort(v2.begin(), v2.end(), [](const Circle* c1, const Circle* c2){return c1->GetRadii() < c2->GetRadii(); });
	sort(v2.begin(), v2.end(), [](const shared_ptr<Curve> c1, const shared_ptr<Curve> c2)
	{return c1->GetRadii() < c2->GetRadii(); });


	for (shared_ptr<Curve> c : v2)//for (const Circle* c : v2)
	{
		cout << "R=" << c->GetRadii() << '\n';
		sum += c->GetRadii();
	}
	
	cout << sum << endl;

	
	system("pause");

}

