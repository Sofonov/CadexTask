#pragma once
#include <iostream>

using namespace std;

class Curve
{
public:
	
	virtual void Point(double&) const = 0;
	virtual double GetRadii() const = 0;// 
};




class Circle : public Curve
{
private:
	
	double Rx;
	
public:
		
	Circle(double &Rx) : Rx(Rx) {}
	
	void Point(double& t) const override
	{
		cout << "r(t = " << t << ") = (" << Rx * cos(t) << ", " << Rx * sin(t) <<  ")" << endl;
		cout << "dr/dt (t = " << t << ") = (" << - Rx *sin(t) << ", " << Rx * cos(t)<< ")" << endl;
	}

	double GetRadii() const
	{
		return Rx;
	}
};



class Ellipse : public Curve
{
private:

	double Rx, Ry;


public:
	
	Ellipse(double &Rx, double &Ry) : Rx(Rx), Ry(Ry) {}
	
	void Point(double& t) const override
	{
		cout << "r(t = " << t << ") = (" << Rx * cos(t) << ", " << Ry * sin(t) << ")" << endl;
		cout << "dr/dt (t = " << t << ") = (" <<- Rx * sin(t) << ", " << Ry * cos(t)  << ")" << endl;
	}
	double GetRadii() const//
	{
		return 0;
	}
};



class  Helix : public Curve
{
private:

	double Rx, Ry, zStep;


public:
	
	Helix(double &Rx, double &Ry, double &zStep) :Rx(Rx), Ry(Ry), zStep(zStep) {}
	
	void Point(double& t) const override
	{
		cout << "r(t = " << t << ") = (" << Rx * cos(t) << ", " << Ry * sin(t) << ", " << zStep * t << ")" << endl;
		cout << "dr/dt (t = " << t << ") = (" <<-Rx * sin(t) << ", " << Ry * cos(t) << ", " << zStep << ")" << endl;
	}
	
	double GetRadii() const//
	{
		return 0;
	}
};



#pragma once
