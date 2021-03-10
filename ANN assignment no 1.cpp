/*
Assignment bt Talha Khalid 70064933
refrence 

w1=4
b1=3
x y  yc  err
1 3  7    4
2 4  11   7
3 5  15   10
4 6  19   13
5 7  23   16
error1 = 50

w2=	6		
b2=	7		
			
w2=	6		
b2=	7		
			
x	y	yc	err
1	2	13	11
3	4	25	21
5	6	37	31
7	8	49	41
9	10	61	51
 			
Error2= 	155		

			
 


error by weight

e2-e1/w2-w1  
155-50/6-4=13.5
error by bias

e2-e1/b2-b1 
155-50/7-3=12

*/


#include<iostream>
#include<dos.h>
#include<windows.h>


using namespace std;


class ini {
protected:

int x[5],y[5],ycap[5],error[5];
int weight,bias,calerr;

public:

 
int  rw() {
return weight;	
}
int  rb() {
return bias;	
}
int  re() {
return calerr;	
}
	
ini() {
 
weight=0;
bias=0;
calerr=0;	
}

ini operator-(const ini& b)   {
         ini gs;
        gs.  calerr =    b. calerr-this->calerr;
  gs. weight =b. weight-this-> weight;
   gs. bias =b. bias- this-> bias ;
         return gs ;
}

void getValues(string  title) { //input all values and caluclate y cap anc calculate average error
cout<<title<<endl;
cout<<"Enter Weight: ";
cin>>weight;	
cout<<"Enter Bias: ";
cin>>bias;

for(int i=0;i<=4;i++) {

cout<<"\nEnter values of x: ";
cin>>x[i];
	
}

for(int i=0;i<=4;i++) {

cout<<"\nEnter values of y: ";
cin>>y[i];
	
}

for(int i=0;i<=4;i++) { //get values of y cap
ycap[i]=x[i]*weight;
ycap[i]=ycap[i]+bias;

}

for(int i=0;i<=4;i++) { // get error raw values
 error[i]=ycap[i]-y[i];

}


for(int i=0;i<=4;i++) { //sum up error values
calerr=calerr+error[i];

}

}

void show(string t2) {
cout<<t2<<endl;
cout<<"Weight= "<<weight<<endl;
cout<<"Bias= "<<bias<<endl<<endl;	
cout<<"x"<<"\t"<<"y"<<"\t"<<"Y cap"<<"\t"<<"Error"<<endl;
for(int i=0;i<=4;i++) {

cout<<x[i]<<"\t"<<y[i]<<"\t"<<ycap[i]<<"\t"<<error[i]<<endl;
	
}

cout<<"Calculated error= "<<calerr<<endl;

}
	
};

class Main:public ini {
private:
int slope,cte,ctw,ctb;
float learning_rate;
public:
ini m1[2],m2;	

void geta() {
m1[0].getValues("\t\t\t\tError slope and bias no 1\n");
m1[0].show("\t\t\t\tError slope and bias output no 1\n");
m1[1].getValues("\t\t\t\tError slope and bias no 2\n");
m1[1].show("\t\t\t\tError slope and bias output no 2\n");
cout<<endl;
 m2=m1[0]-m1[1];

cte=m2.re();
ctw=m2.rw();
ctb=m2.rb();
/*
cout<<"Error= "<<cte<<endl;
cout<<"Weight= "<<ctw<<endl;
cout<<"Bias= "<<ctb<<endl;
*/
}

void cslope() {
cout<<"Slope by Bias\n"	;
slope=cte/ctb;
cout<<slope<<endl;
cout<<"Slope by Weight\n"	;
slope=cte/ctw;
cout<<slope<<endl;

}

void fixWeight() {
do {
cout<<endl;	
cout<<"Enter learning rate: ";
cin>>learning_rate;
ctw=ctw-slope;
ctw=ctw*learning_rate;
cout<<"After adjusting Weight= "<<ctw<<endl;		
}while(ctw!=0);
}

};

int main() {
Main m1;
m1.geta();
m1.cslope();
m1.fixWeight();
return 0;	
}
