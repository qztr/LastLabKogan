/*
 
 class point(x,y):
 set,get
 distance( между точками)
 норма(расстояние до 0,0)
 turn(поворот на угол)
 
 class triangle (point A, point B, point C)
 turn
 площадь
 
 подавать в turn объект Point M с его методами.
 в Triangle в конструктор подавать 3 поинта. без координат.
*/

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

class Angle_45
{
public:
    double x, y;
    Angle_45(double x, double y) : x(x), y(y){};
};

class Point2
{
private:
    double x;
    double y;

public:
    void set_x1(double x) { this->x = x; }
    double get_x1() const { return x; }
    void set_y1(double y) { this->y = y; }
    double get_y1() const { return y; }

    Point2(double x1, double y1) : x(x1), y(y1){};
    Point2(){};

    double get_dist(Point2 M)
    {
        double dist = 0;
        dist = sqrt((M.x - x) * (M.x - x) + (M.y - y) * (M.y) - y);
        return dist;
    }

    template <typename Iter_T>
    // реализация из : "C++. Сборник рецептов"  - Диггинс Кристофер
    long double vectorNorm(Iter_T x, Iter_T y)
    {
        return sqrt(inner_product(x, y, x, 0.0L));
    }

    void turner1(Angle_45 a)
    {
        double cs = a.x;
        double sn = a.y;
        //cout << "cos = " << cs << "sin = "<< sn << endl;
        double rx = x * cs - y * sn;
        double ry = x * sn + y * cs;

        set_x1(rx);
        set_y1(ry);
        // немного не точноые рез-таты, возможно что-то с радианами и градумами не то. вместо х = 1.37, у = 0.366, выдает другое
    }
};

class Triangle2
{
protected:
    Point2 dot1;
    Point2 dot2;
    Point2 dot3;

public:
    Triangle2(Point2 d1, Point2 d2, Point2 d3) : dot1(d1), dot2(d2), dot3(d3){};
    Triangle2(){};

    virtual double TriangleArea()
    {
        double area_triangle;
        double a, b, c, s;

        a = std::sqrt((dot1.get_x1() - dot2.get_x1()) * (dot1.get_x1() - dot2.get_x1()) +
                      (dot1.get_y1() - dot2.get_y1()) * (dot1.get_y1() - dot2.get_y1()));
        //cout << "a = " << a << endl;

        b = std::sqrt((dot2.get_x1() - dot3.get_x1()) * (dot2.get_x1() - dot3.get_x1()) +
                      (dot2.get_y1() - dot3.get_y1()) * (dot2.get_y1() - dot3.get_y1()));
        //cout << "b = " << b << endl;
        c = std::sqrt((dot1.get_x1() - dot3.get_x1()) * (dot1.get_x1() - dot3.get_x1()) +
                      (dot1.get_y1() - dot3.get_y1()) * (dot1.get_y1() - dot3.get_y1()));
        //cout << "c = " << c << endl;
        s = (a + b + c) / 2;

        area_triangle = std::sqrt((s * (s - a) * (s - b) * (s - c)));

        return area_triangle;
    }
    

    void turner_tr1(Angle_45 a)
    {
        double cs = a.x;
        double sn = a.y;

        double rx1 = dot1.get_x1() * cs - dot1.get_y1() * sn;
        double ry1 = dot1.get_x1() * sn + dot1.get_y1() * cs;
        dot1.set_x1(rx1);
        dot1.set_y1(ry1);

        double rx2 = dot2.get_x1() * cs - dot2.get_y1() * sn;
        double ry2 = dot2.get_x1() * sn + dot2.get_y1() * cs;
        dot2.set_x1(rx2);
        dot2.set_y1(ry2);

        double rx3 = dot3.get_x1() * cs - dot3.get_y1() * sn;
        double ry3 = dot3.get_x1() * sn + dot3.get_y1() * cs;
        dot3.set_x1(rx3);
        dot3.set_y1(ry3);
    }
};

class TriParall : public Triangle2
{
private:
	Point2 corn;
	double lencath1;
	double lencath2;
public:
    /*TriParall(Point2 p1, Point2 p2, Point2 p3) : Triangle2(p1, p2, p3)
    {
        cout << "created TriParall" << endl;
    }*/
	//TriParall(double c1,double c2) : Triangle2(){};
	TriParall(double c1,double c2) : lencath1(c1),lencath2(c2){};
	//Point2(double x1, double y1) : x(x1), y(y1){};
	double TriangleArea(){
		double x=0;
		x = ((lencath1*lencath2)/2);
		return x;
	}
	double hypo(){
		return (lencath1*lencath1 + lencath2*lencath2);
	}

    
};

template <typename T>
class Stack
{
private:
    T *stackPtr; // указатель на стек
    int size; // размер стека
    T top; // вершина стека
public:
    Stack(int = 10);// по умолчанию размер стека равен 10 элементам
    ~Stack(); // деструктор
    bool push(const T  ); // поместить элемент в стек
    bool pop(); // удалить из стека элемент
    void printStack();
};

int main()
{

    Point2 p1(1, 1);
    Point2 p2(4, 1);
    Point2 p3(1, 5);
    double xcor = (sqrt(3.0) / 2.0);
    double ycor = (1.0 / 2.0);
    cout << "xcor = " << xcor << " ycor = " << ycor << endl;
    Angle_45 an(xcor, ycor);

    double distancia = p1.get_dist(p2);
    cout << "distancia between Point 1 and Point2 =  " << distancia << endl;

    double v1[] = {p1.get_x1(), p1.get_y1()};
    double k = p1.vectorNorm(v1, v1 + 2);
    cout << "\nnorma of Point 1 is " << k << endl;

    cout << "\ncoordiantes of Point 1 before turn: "
         << " \nx = " << p1.get_x1() << "\ny = " << p1.get_y1() << endl;
    cout << "\nCoordiantes of Point 1 after turn on 30':\n";
    p1.turner1(an);
    cout << "x = " << p1.get_x1() << " \ny = " << p1.get_y1() << endl;

    Triangle2 tri(p1, p2, p3);
    cout << "\ntriangle with 3 Points :\n"
         << "Point 1  coordinates: \nx = " << p1.get_x1() << "\ny = " << p1.get_y1() << "\nPoint 2  coordinates: \nx = " << p2.get_x1() << "\ny = " << p2.get_y1() << "\nPoint 3  coordinates: \nx = " << p3.get_x1() << "\ny = " << p3.get_y1() << endl;
    //double area1 = tri.TriangleArea();
    cout << "\nTriangle rurned on 30'" << endl;
    tri.turner_tr1(an);
    cout << "\n";

    //cout << "Triangle area = " << area1 << endl;

    cout <<" ============================================"<<endl;


	TriParall triug(1,1);
	double ae1  = triug.TriangleArea();
	cout << "area of right triangle is = "<< ae1 << endl;

	system("pause");
}
