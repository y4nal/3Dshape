#include<iostream>
#include<math.h>
#include <stdio.h>
#include <Windows.h>

using namespace std;
const double PI = 3.14;
const float Three = 3;
const float Tow = 2;
class DShape
{
private:
	float Slen;
public:
	DShape(float S = 3)
	{
		Setlen(S);
	}
	void Setlen(float i = 3) { Slen = i; }
	float getLen() { return Slen; }
	~DShape() {}
	virtual float getArea() = 0;
	virtual float getSurfaceArea() = 0;
	virtual float getValume() = 0;
	virtual const char * IsA() { return "Shape"; }
	virtual void print()  = 0;
	virtual void read() = 0;
};



class Cuboid :public DShape
{
private:
	float hight;
	float width;
public:
	Cuboid(float l = 3, float h = 3, float w = 3) :DShape(l) { setHight(h); setWidth(w); }
	void setWidth(float i = 3) { width = i; }
	void setHight(float i = 3) { hight = i; }
	virtual float getSurfaceArea()  { return 2 * (getLen() * getWidth() + getHight() * getLen() + getHight() * getWidth()); }
	virtual float getArea() { return(getLen() * getWidth()); }
	virtual float getValume() { return getLen() * getWidth() * getHight(); }
	float getWidth() { return width; }
	float getHight() { return hight; }
	virtual ~Cuboid() { }
	virtual void print() { cout << IsA() << "SurfaceArea " << getSurfaceArea() << " Area " << getArea() << " The Valume " << getValume() << endl; }
	virtual void read() { float h, w, s; cout<<IsA();cout << " Enter Width";cin >> w;cout << "Enter Hight";cin >> h;cout << "Enter Slen";cin >> s;setHight(h);setWidth(w);Setlen(s); }
	virtual const char * IsA() { return "Cuboid "; }
};
class cube :public Cuboid
{
	public:
	cube(float l = 3) :Cuboid(l, l, l) {};
	float getValume() { return getLen() * getWidth() * getHight(); }
	float getSurfaceArea() { return 6 * getHight() * getWidth(); }
	float getArea() {return (getHight() * getWidth()); }
	void read() { float l;cout<<IsA(); cout << "Enter side "; cin >> l;setHight(l);setWidth(l);Setlen(l); }
	void print() { cout << IsA() << "SurfaceArea " << getSurfaceArea() << " Area " << getArea() << " The Valume " << getValume() << endl; }
	const char * IsA()const { return "cube "; }
	virtual ~cube() { }
};
class a_regular_tetrahedron :public DShape
{
	public:
	a_regular_tetrahedron(float l = 3) :DShape(l) {};
	float getSurfaceArea() { return (sqrt(Three) * (getLen())); }
	float getArea() {return ((getLen()* getLen()))/2;}
	float getValume() { return (pow(getLen(), Three) / (6 * sqrt(Tow))); }
	void read() { float l;cout << "Enter " << IsA() << " Len "; cin >> l;Setlen(l); }
	const char * IsA() { return "a_regular_tetrahedron"; }
	void print() { cout << IsA() << "SurfaceArea " << getSurfaceArea() << " Area " << getArea() << " The Valume " << getValume() << endl; }
	virtual ~a_regular_tetrahedron() { }
};
class Sphere :public DShape
{
private:
	float radii;
public:
	Sphere(float r = 0) { setRadius(r); }
	float getSurfaceArea() { return 4 * PI * pow(getRadius(), 2); }
	float getArea() { return (pow(getRadius(), 2) * PI); }
	float getValume() { return (4 * PI / 3) * pow(getRadius(), 3); }
	void setRadius(float r = 3) { radii = r; }
	float getRadius() { return radii; }
	float getHeight() { }
	virtual ~Sphere() { }
	void read() { float r;cout<<IsA();cout << " Enter The radius ";cin >> r;setRadius(r); }
	void print() { cout << IsA() << " SurfaceArea " << getSurfaceArea() << " Area " << getArea() << " The Valume " << getValume() << endl; }
	const char * IsA() { return "Sphere "; }
};
class cylinder :public Sphere
{
	float height;
public:
	cylinder(float r = 0, float h = 0) :Sphere(r) { setheight(h); }
	float getSurfaceArea() { return 2 * PI * getRadius() * (getRadius() + getHeight()); }
	float getArea() { return (pow(getRadius(), 2) * PI); }
	float getValume() { return PI * pow(getRadius(), 2) * getHeight(); }
	void setheight(float r = 3) { height = r; }
	float getHeight() { return height; }
	virtual ~cylinder() { }
	void read() { float r, h; cout << "Enter the " << IsA() << " radius and height " << endl; cin>>r>>h; setRadius(r);setheight(h); }
	void print() { cout << IsA() << "SurfaceArea " << getSurfaceArea() << " Area " << getArea() << " The Valume " << getValume() << endl; }
	const char * IsA() { return "cylinder "; }
};
class pyramid :public cylinder
{
private:
	float length;
public:
	public:
	pyramid(float b = 3, float s = 3, float h = 3) { setheight(h);setLength(b); Setlen(s); }
	void setLength(float b = 3) { length = b; }
	float getLength() { return length; }
	float getSurfaceArea() { return 2 * getLength() * getLen() + pow(getLength(), 2); }
	float getValume() { return 1 / 3 * getHeight() * pow(getLength(), 2); }
	float getArea() { return (getLength() * getLength()) + (2 * getLength() * sqrt(pow(getLength(), 2) + pow(getHeight(), 2) / 4)); }
	void read() { float h, l, s;cout << IsA(); cout << " Enter Length";cin >> l;cout << "Enter Hight";cin >> h;cout << "Enter len";cin >> s;setheight(h);setLength(l);Setlen(s); }
	void print() { cout << IsA() << "SurfaceArea " << getSurfaceArea() << " Area " << getArea() << " The Valume " << getValume() << endl; }
	const char * IsA() { return "pyramid "; }
};

class cone :public cylinder
{
	public:
	cone(float r = 0, float h = 0) : cylinder(r, h) { }
	virtual ~cone() { }
	float getSurfaceArea() { return PI * getRadius() * (sqrt(pow(getRadius(), 2) + pow(getHeight(), 2)) + getRadius()); }
	float getValume() { return (PI / 3.0) * pow(getRadius(), 2) * getHeight(); }
	void read() { float r, h;cout << "Enter the " << IsA() << " radius " << endl; cin >> r; cout << "And the height " << endl; cin >> h; setheight(h);setRadius(r); }
	void print() { cout << IsA() << "SurfaceArea " << getSurfaceArea() << " Area " << getArea() << " The Valume " << getValume() << endl; }
	const char * IsA() { return "cone "; }
};

int main()
{
	DShape*h[8];
	h[0]=new cone ();
	h[1]=new pyramid ();
	h[2]=new cylinder ();
	h[3]=new Sphere ();
	h[4]=new a_regular_tetrahedron ();
	h[5]=new cube ();
	h[6]=new Cuboid	();	
	for (int i = 0;i < 7;i++)
	{
		h[i]->read();
   }

		for (int i = 0; i < 7; i++)
			for (int j = i + 1; j < 7; j++)
				if (h[i]->getSurfaceArea() > h[j]->getSurfaceArea())
				{
					DShape* G = h[i];
					h[i] = h[j];
					h[j] = G;
				}
	
		DShape* a;
		a = h[0];
		for (int i = 0; i < 7; i++)
		{

			if (a->getValume() < h[i]->getValume()) a = h[i];
		}
		cout<<"The max Valume ";a->print();
	for (int i = 0;i < 7;i++)
	{
		h[i]->print();
	}


	for (int i = 0;i < 7;i++)
	{
		delete h[i];
	}

}	

