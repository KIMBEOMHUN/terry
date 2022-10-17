#include <iostream>
#include <string>
using namespace std;

//연산자 중복 []
//class Complex{
//private:
//    int real, image;
//public:
//    Complex(int r=0, int i = 0):real(r),image(i){};
//    ~Complex();
//    void show(Complex& b){
//    cout << b.real <<"+"<<b.image<<"j"<<endl;}
//};
//Complex operator -(const Complex& C) const{
//    return Complex(real-C.real,image-C.image);
//}

//Complex operator-()const{
//    return Complex(-real,-image);
//}

//int operator[](const int& idx) const{
//    return(idx==0?real:image);
//}
//int& operator[](const int& idx){
//    return(idx==0?real:image);
//}
//int main()
//{
//    Complex a(10,10),b;
//    b[0] = 1.0;b[1]=2.0;
//    show(b);

//    b=-a;b[0]=a[0];
//    show(b);
//}

//파생클래스에서 함수 재정의
//class Base{
//public:
//    void f(){cout <<"Base::f() called"<<endl;}
//};

//class Derived : public Base{
//public:
//    void f(){cout << "Derived::f() called"<<endl;}
//};

//int main(){
//    Derived d, *pDer; //d 객체 생성, pder 포인터 생성
//    pDer = &d;  //pDer은 객체 d의 주소를 가리킨다.
//    pDer->f(); //Derived::f() 호출

//    Base* pBase; //pBase 포인터 생성
//    pBase = pDer;   //업캐스팅
//    pBase ->f(); //Base::f() 호출
//}

//예제 - 오버라이딩과 가상함수 호출
//class Base{
//public:
//    virtual void f(){cout <<"Base::f() called"<<endl;}
//};

//class Derived:public Base{
//public:
//    virtual void f(){cout <<"Derived::f() called"<<endl;}
//};

//int main(){
//    Derived d,*pDer;
//    pDer = &d;
//    pDer ->f();//Derived::f() 호출

//    Base *pBase;
//    pBase = pDer; //업캐스팅
//    pBase ->f(); //동적 바인딩 실행!!!! Derived::f() 실행
//}

//class Shape{
//public:
//    void paint(){
//        draw();
//    }
//    virtual void draw(){
//        cout << "Shape::draw() called"<<endl;
//    }
//};

//int main(){
//    Shape *pShape = new Shape();
//    pShape -> paint();
//    delete pShape;
//}

//예제
//class Shape{
//public:
//    void paint(){
//        draw();
//    }
//    virtual void draw(){
//        cout << "Shape::draw() called"<<endl;
//    }
//};

//class Circle:public Shape{
//public:
//    virtual void draw(){
//        cout <<"Circle::draw() called"<<endl;
//    }
//};
//int main(){
//    Shape *pShape = new Circle(); //업캐스팅
//    pShape -> paint();
//    delete pShape;
//}

//예제
//class Base{
//public:
//    virtual void f(){cout << "Base::f() called"<<endl;}
//};

//class Derived:public Base{
//public:
//    void f() {cout <<"Derived::f() called"<<endl;}
//};

//class GrandDerived:public Derived{
//public:
//    void f() {cout <<"GrandDerived::f() called"<<endl;}
//};

//int main(){
//    GrandDerived g;
//    Base *bp;
//    Derived *dp;
//    GrandDerived *gp;

//    bp = dp = gp = &g; //업캐스팅

//    bp->f();
//    dp->f();
//    gp->f();
//}

//범위 지정 연산자
//class Shape{
//public:
//    virtual void draw(){
//        cout << "--shape--";
//    }
//};

//class Circle:public Shape{
//public:
//    virtual void draw(){
////        Shape::draw();//기본클래스의 draw()호출
//        cout << "circle"<<endl;
//    }
//};

//int main(){
//    Circle circle;
//    Shape *pShape = &circle;

//    pShape ->draw();
//    pShape ->Shape::draw();
//}


//가상 소멸자
//class Base{
//public:
//    virtual ~Base(){cout << "~Base()"<<endl;}
//};

//class Derived:public Base{
//public:
//    virtual ~Derived(){cout<<"~Derived()"<<endl;}
//};

//int main(){
//    Derived *dp= new Derived();
//    Base *bp = new Derived();

//    delete dp;  //Derived의 포인터로 소멸
//    delete bp;  //Base의 포인터로 소멸

//}


//순수 가상 함수
//class Shape{
//public:
//    virtual void draw() = 0;
//};

//class Circle:public Shape{
//public:
//    virtual void draw(){
//        cout << "Circle";
//    }
//    string toString(){return "Circle instance";}
//};
//int main(){Circle waffle;}

//실습1
//class Calculator{
//public:
//    virtual int add(int a,int b)=0;
//    virtual int subtract(int a,int b)=0;
//    virtual double average(int a[],int size)=0;
//};

//class GoodCalc:public Calculator{
//public:
//    int add(int a,int b){
//        return a+b;
//    }
//    int subtract(int a,int b){
//        return a-b;
//    }
//    double average(int a[],int size){
//        double sum = 0;
//        for(int i=0;i<size;i++)
//            sum+=a[i];
//        return sum/size;
//    }
//};

//int main(){
//    int a[] ={1,2,3,4,5};
//    Calculator *p = new GoodCalc();
//    cout << p->add(2,3)<<endl;
//    cout << p->subtract(2,3)<<endl;
//    cout << p->average(a,5)<<endl;
//    delete p;
//}


////실습2
//class Shape{
//protected:
//    string name;
//    int width,height;
//public:
//    Shape(string n=" ",int w=0,int h=0){name = n;width=w;height=h;}
//    virtual double getArea()=0;
//    string getName(){return name;}
//};

//class Oval:public Shape{
//public:
//    Oval(string name,int width,int height):Shape(name,width,height){}
//    virtual double getArea(){return 3.14*width/2*height/2;}
//};

//class Rect:public Shape{
//public:
//    Rect(string name,int width,int height):Shape(name,width,height){}
//    virtual double getArea(){return width*height;}
//};

//int main(){
//    Shape *p[2];
//    p[0]=new Oval("Rice cake1",10,20);
//    p[1]=new Rect("Rice cake2",30,40);

//    for(int i=0;i<2;i++)
//        cout <<p[i]->getName()<<' area is '<< p[i]->getArea()<<endl;
//    for(int i =0; i<2;i++) delete p[i];
//}
