#include<iostream>
using namespace std;
class Complex
{
private:
    int real;
    int image;
public:
    Complex():real(0),image(0){}
    void readdata()
    {
        cout <<"Enter real and imaginary number: "<< endl;
        cin >>real>>image;
    }
    Complex Function1(Complex C1)
    {
        Complex temp;
        temp.real=real+C1.real;
        temp.image=image+C1.image;
        return temp;
    }
    void displayData()
        {
            cout << "Sum = " << real << "+" << image << "i";
        }
};
int main()
{
    Complex A1,A2,A3;
    A1.readdata();
    A2.readdata();
    A3=A1.Function1(A2);
    A3.displayData();
}
