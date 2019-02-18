#pragma once
#include <iostream>

using namespace std;

class Curves
{
public:

	virtual void Create(double&, double&, double&) = 0;
	virtual void Point(double&) = 0;
	virtual double GetRadii() = 0;
};


class Circle : public Curves
{
private:

	double Rx;

public:
	static int count;
	void Create(double &Rx, double &Ry, double &zStep) override
	{
		this->Rx = Rx;
		count++;
	}

	void Point(double& t) override
	{
		cout << "r(t = " << t << ") = (" << Rx * sin(t) << ", " << Rx * cos(t) << ", " << 0 << ")" << endl;
		cout << "dr/dt (t = " << t << ") = (" << Rx * cos(t) << ", " << -Rx * sin(t) << ", " << 0 << ")" << endl;
	}

	double GetRadii()
	{
		return Rx;
	}
};

int Circle::count = 0;

class Ellipse : public Curves
{
private:

	double Rx, Ry;


public:
	static int count;
	void Create(double &Rx, double &Ry, double &zStep) override
	{
		this->Rx = Rx;
		this->Ry = Ry;
		count++;
	}
	void Point(double& t) override
	{
		cout << "r(t = " << t << ") = (" << Rx * sin(t) << ", " << Ry * cos(t) << ", " << 0 << ")" << endl;
		cout << "dr/dt (t = " << t << ") = (" << Rx * cos(t) << ", " << -Ry * sin(t) << ", " << 0 << ")" << endl;
	}
	double GetRadii()
	{
		return 0;
	}
};

int Ellipse::count = 0;

class  Helix : public Curves
{
private:

	double Rx, Ry, zStep;


public:
	static int count;
	void Create(double &Rx, double &Ry, double &zStep) override
	{
		this->Rx = Rx;
		this->Ry = Ry;
		this->zStep = zStep;
		count++;
	}
	void Point(double& t) override
	{
		cout << "r(t = " << t << ") = (" << Rx * sin(t) << ", " << Ry * cos(t) << ", " << zStep * t << ")" << endl;
		cout << "dr/dt (t = " << t << ") = (" << Rx * cos(t) << ", " << -Ry * sin(t) << ", " << zStep << ")" << endl;
	}
	double GetRadii()
	{
		return 0;
	}
};

int Helix::count = 0;

#pragma once
