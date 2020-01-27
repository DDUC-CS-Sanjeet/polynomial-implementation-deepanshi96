#include<iostream>
using namespace std;
class Polynomial
{
	int array[10];
	int degree;
	 // Variables to store information about polynomial
	public:
	 	 	Polynomial()
	 	    {
	 		degree=0;
		    }
		    Polynomial(int deg)
		    {
			   // Behavior of constructor with arguments
			   degree=deg;
			   degree++;	
		    }
		~Polynomial()
        {
            degree=0; // Behavior of destructor
        }
         //  Overload copy constructor, +, - and = operators
        Polynomial operator +(Polynomial x)
		{
			Polynomial p;
			p.degree=this->degree>=x.degree? this->degree:x.degree;
			for(int i=0;i<p.degree;i++)
			{
				if(i>=this->degree)
				  this->array[i]=0;
				if(i>=x.degree)
				  x.array[i]=0;
				  p.array[i]=x.array[i]+this->array[i];  
			}
			return p;
		}
		Polynomial operator -(Polynomial x)
		{
			Polynomial p;
			p.degree=this->degree>=x.degree? this->degree:x.degree;
			for(int i=0;i<p.degree;i++)
			{
				if(i>=this->degree)
				  this->array[i]=0;
				if (i>=x.degree)
				  x.array[i]=0;
				  p.array[i]=this->array[i]-x.array[i];  
			} 
		    return p;	
	    }
	    Polynomial operator =(Polynomial x)
		{
			Polynomial p;
			this->degree=x.degree;
			for(int i=0;i<this->degree;i++)
			  this->array[i]=x.array[i];
	    }
	    void storePolynomial()
        {
            //  Code to enter and store polynomial	
            cout<<"\n enter the cofficient in ascending order of power ie.starting from constant to highest power:"<<endl;
			for(int i=0;i<degree;i++)
			cin>>array[i];
 	    }
 	    void display()
        {
            //  Code to print the polynomial in readable format
            cout<<"\n";
            for(int i=0;i<degree;i++)
            {
            	cout<<array[i]<<"X^"<<i;
            	if(i<degree-1)
            	  cout<<" + ";
			}
	    }
};
int main()
{
	int degFirst, degSecond;
	cout<<"enter the degree for first polynomial:";
    cin>>degFirst;
	cout<<"\n enter value of degree of second polynomial:";
	cin>>degSecond;
    // Ask user to input the values of degFirst and degSecond 
    Polynomial firstPolynomial(degFirst);
    Polynomial secondPolynomial(degSecond);
    Polynomial thirdPolynomial;
  
    firstPolynomial.storePolynomial();
    secondPolynomial.storePolynomial();
   
    thirdPolynomial=firstPolynomial+secondPolynomial;
    Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
    cout<<"\n the first polynomial is :";
    firstPolynomial.display();
    cout<<endl;
    cout<<"\n the second polynomial is : ";
    secondPolynomial.display();
    cout<<endl;
    cout<<"\n the third polynomial obtained after adding is :";
    thirdPolynomial.display();
    cout<<endl;
    cout<<"\n the first polynomial obtained after subtracting is :";
    fourthPolynomial.display();
    return 0;
}
