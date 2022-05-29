#include<iostream>
#include<stdexcept>
#include<cmath>

class Equation{
    private:
        //var
        double * a;
        double * b;
        double * c;
        double * solutions;
        std::size_t solutions_size;
        
        //private method
        void update_solutions();
    public:
        //Constructors and Destructors
        Equation();
        Equation(double a, double b, double c);
        Equation(const Equation &e2);
        ~Equation();
        
        //get  
        double getA() const;
        double getB() const;
        double getC() const;
        std::size_t get_solutions_size();
        double const* const get_solutions();
        //set
        void setA(double a );
        void setB( double b );
        void setC( double c );
        
        
        //operator 
        Equation& operator=(const Equation& e);
    	friend std::ostream& operator <<(std::ostream& out, const Equation& e);
        friend Equation operator + (int num ,const Equation& e);
        friend Equation operator + (const Equation& e,int num);
        friend Equation operator + (const Equation& e1 ,const Equation& e2);
};
Equation::Equation()
    :a(new double),b(new double),c(new double),solutions(new double[2]),solutions_size(2){
}

Equation::Equation(double a, double b, double c)
    :a(new double),b(new double),c(new double),solutions(new double[2]),solutions_size(2)
{
    setA(a);
    setB(b);
    setC(c);
    update_solutions();
}
Equation::Equation(const Equation& e)
    :a(new double(*e.a)),b(new double(*e.b)),c(new double(*e.c)),solutions(new double[2]),solutions_size(2){
    update_solutions();
}
Equation::~Equation()
{
    delete a;
    a=nullptr;

    delete b;
    b=nullptr;

    delete c;
    c=nullptr;

    delete  []solutions;
    solutions=nullptr; 
}

double Equation::getA() const{
    return *a;
}
double Equation::getB() const{
    return *b;
}
double Equation::getC() const{
    return *c;
}
std::size_t Equation::get_solutions_size(){
    return solutions_size;
}


void Equation::setA(double a ){
    if(a == 0){
        throw std::invalid_argument("A Should never be zero!");
    }
    else
    {
        *(this->a) = a;
        update_solutions();
    }
}
void Equation::setB( double b ){
    *(this->b) =b;
    update_solutions();
}
void Equation::setC( double c ){
    *(this->c)=c;
    update_solutions();
}
double const* const Equation::get_solutions(){
    return solutions;
}

std::ostream& operator<<(std::ostream& out, const Equation& e){
    out.precision(2); 
    out<< std::fixed<<e.getA()<<"X^2 + "<<e.getB()<<"X + "<<e.getC()<<" = 0";
    return out;
}
Equation& Equation::operator=(const Equation& e){
    this->setA(e.getA());
    this->setB(e.getB());
    this->setC(e.getC());
    this->update_solutions();
    return *this;
}

Equation operator+(int num ,const Equation& e){ 
    return e+num;
}
Equation operator+(const Equation& e,int num){ 
    return Equation(e.getA(),e.getB(),e.getC()+(double)num);
}
Equation operator + (const Equation& e1 ,const Equation& e2){ 
    return Equation(e1.getA()+e2.getA(),e1.getB()+e2.getB(),e1.getC()+e2.getC());
}

void Equation::update_solutions(){
    int sum = pow(getB(),2)-4*(getA()*getC()); 
    sum=sqrt(sum);
    if(sum>0){
        this->solutions_size=2;
        double index_0=getB()*(-1);
        index_0+=sum;
        index_0 = index_0/(2*getA());

        double index_1=getB()*(-1);
        index_1-=sum;
        index_1 = index_1/(2*getA());
        solutions[0]=index_0;
        solutions[1]=index_1;
    }
    else if(sum == 0){
        this->solutions_size=1;
        solutions = new double(get_solutions_size());
        solutions[0] = (getB()*(-1))/(2*getA());
    }
    else{
        this->solutions_size=0;
    }            
}