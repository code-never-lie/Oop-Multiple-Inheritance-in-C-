Multiple Inheritance
subclass can extend more than one super classes

Example
class Calculator{
public :
 Calculator() { cout<<"Calculator Created\n";}
 void add() { cout<<" Add function \n";}

};

class Clock {
public:
Clock() { cout<<"Clock Created\n";}
void getTime() { cout<<" view Time \n";}
};

class CasioCalculator:public Calculator,public Clock{
public :
CasioCalculator() { cout<<"CasioCalculator Created\n";}
void memory() { cout<<"calculator memory \n"<<endl;}
};
void main() {
CasioCalculator ob;
ob.add();
ob.getTime();
ob.memory();
}

........................................................\
Diamond Problem
- A major Problem in inheritance 
- Due to diamond problem most of languages remove this feature e.g java
In object-oriented programming languages with multiple inheritance, the diamond problem (sometimes referred to as the "deadly diamond of death") is an ambiguity that arises when two classes B and C inherit from A, and class D inherits from both B and C. If D calls a method defined in A (and does not override the method), and B and C have overridden that method differently, then from which class does it inherit: B, or C?

See diagram on board
class A {
public:
 A() { cout<<"A created \n";}
 void m() { cout<<"M Method \n";}

};
class B:public A {
public:
 B() { cout<<"B created \n";}
};
class C:public A{
public:
 C() { cout<<"C created \n";}
};
class D : public B, public C {
public:
 D() { cout<<"D created \n";}
};

void main () {
D d;

}
Output 
A Created
B Created
A Created
C Created
D Created
.................................
void main () {
D d;
d.m() ;//D::m is ambiguous
}
.............................................
Soloution
void main () {
D d;
d.C::m();
//OR
d.B::m();
}
..................................................
Discussion
C++ by default follows each inheritance path separately, so a D object would actually contain two separate A objects, and uses of A's members have to be properly qualified. 
If the inheritance from A to B and the inheritance from A to C are both marked "virtual" (for example, "class B : virtual public A"), C++ takes special care to only create one A object, and uses of A's members work correctly. If virtual inheritance and nonvirtual inheritance are mixed, there is a single virtual A and a nonvirtual A for each nonvirtual inheritance path to A. Please note that nonvirtual derivation of A in this case will be useless as direct access to any part of class A from class D will practically always end up with compile error.
.....................................................

Virtual Inheritance
- Solution of Diamond Problem in C++
-

class A {
public:
 A() { cout<<"A created \n";}
 void m() { cout<<"M Method \n";}

};
class B:virtual public A {
public:
 B() { cout<<"B created \n";}
};
class C:virtual public A{
public:
 C() { cout<<"C created \n";}
};
class D : public B, public C {
public:
 D() { cout<<"D created \n";}
};

void main () {
D d;
d.m();

}
Output 
A Created
B Created
C Created
D Created

......................................................
Assignment    due date 21 april lab (hard form)
- A is super most class with m method
- B and C inherits A
- F and E inherits C
- G inherits F and E
- H inherits B and G
- i inherits H
implement with two techniques
1- Simple Inheritance
2- Virtual Inheritance

..............................................

                  Quiz
- A is super most class with m method
- B and C inherits A
- F and E inherits C
- G inherits F and E
- H inherits B and G
- i inherits H
   implement with one techniques

    i.e Virtual Inheritance















