Coding Ninjas basics in c++

//1.compile and run
linux:
g++ Filename.cpp
./a.out

windows
gcc Filename.cpp
Filename

//2.macros
#define  PI  3.1416		//no semicolon
#define  AREA(r)  (PI*(r)*(r))

	// Multi-line Macro definition
#define ELE 1, \
            2, \
            3

//3.rules for variable
cant start with number 
spaces and special character except underscore '_' are not allowed.
cant use keywords 
case sensitive -> int A and int a are different.

//4.size of datatypes
	cout<<sizeof(int)<<endl;4
	cout<<sizeof(float)<<endl;4
	cout<<sizeof(double)<<endl;8
	cout<<sizeof(char)<<endl;1
	cout<<sizeof(wchar_t)<<endl;2
	cout<<sizeof(short)<<endl;2
	cout<<sizeof(long)<<endl;4

auto keyword if datatype is not certain 

//5.types of variables
1 local
2 instance (for every object)
3 static (once per class , not different for every object)

-> local & global scope 
to access global use scope resolution ::a 


//6.Overflow & Underflow
	int x=INT_MAX;
	int y=INT_MIN;
	x++;//overflow
	y--;//underflow
	cout<<x<<" "<<y;//-2147483648 2147483647

//7.typecast
1 Implicit (done by compiler automatically)

bool -> char -> short int -> int -> 
unsigned int -> long -> unsigned -> 
long long -> float -> double -> long double

2 Explicit 
(type)expression
eg. int x=5;
(float)x;//typecasting

//8.ASCII
A 65
a 97

//9.Input 	cin>> 	extraction operator
			cout<<	insertion operator
string s;
getline(cin,s);

//10.string to int
int x=stoi(s);

//11.int to string
string s2=to_string(x);

//12.datatype name 
cout<<typeid(x).name()<<endl;//i -> int 

//13.pair
pair<int,int> p;
p.first;//first value
p.second;//second value

//14.swap without temp
a=a+b;
b=a-b;
a=a-b;

//15.decimal to binary string
string s = bitset<32> (-7).to_string();//11111111111111111111111111111001

//16.Comma operator and separator
//int x=3,4,5;//error
int x;
x=3,4,5;
cout<<x<<endl;//3 -> assignment

x=(3,4,5);
cout<<x<<endl;//5 -> execute 3 and 4 first and discard result and return last ie 5

//17.Pointer
int a=5,*b;//b is int pointer pointing to int a
b=&a;
cout<<b<<endl;
cout<<&b<<endl;
cout<<*b<<endl;//value at address b
cout<<&a<<endl;

//18.if
if is not executed for 0.
for all other values its true 
eg. if(-1)
    {
    	cout<<"yo";
    }
    else 
    {
    	cout<<"ops";
    }
o/p:yo

//19.switch
switch(expression)
{
	case constant1:
		line 1;
		line 2;
		break;
	default :
		lines;
}

//20.goto
goto label;

label:
	lines;

-> break statement should be inside switch or loop else compile time error


//21.round off
round()
lround()
llround()

float a=5.6;
//a=round(a);//6
cout<<int(a);//5

float var = 37.66466; 
// Directly print the number with .2f precision

// cout << fixed << setprecision(3) << var;//37.665
// cout<<endl<<var;//37.665

cout << setprecision(3) << var;//37.7
cout<<endl<<var;//37.7

//22.do while
do{

}
while(condition);

//23.Power function
pow(2,3) -> 2 raise to 3 = 8

//24.fibo
int m=(int)(1e9 + 7);
int a=0,b=1,c;
for(int i=2;i<=n;i++)
{
    c=(a+b)%m;
    a=b;
    b=c;
}
return b ;

//25.function prototype

int maximum (int ,int );
//int maximum (int n1,int n2);
//int maximum (int ,int n2);
//int maximum (int n1,int );
//all 4 will work

int main() {
	cout<<maximum(40,5);
    return 0;
}

int maximum(int n1,int n2)
{
	if(n1>n2) return n1;
	return n2;
}

//26.Pass by value & pass by reference
value (int x)
reference (int &x)

//27.function overloading during run time 
int add(int a,int b) 
{
	cout<<"f1 ";
	return a+b;
}

double add(double a,double b) 
{
	cout<<"f2 ";
	return a+b;
}

int main()
{
	cout<<add(2,3)<<endl;//f1 5
	cout<<add(2.1,3.4)<<endl;//f2 5.5
	return 0;
}

//28.default parameter
int add(int a,int b=5)
{
	return a+b;
}

int main()
{
	cout<<add(2);//7
	cout<<add(2,3);//5
	return 0;
}

-> all parameter must be default after one default parameter (rightmost)

//29.Pointer Arithmetic 
int val=5;
int* p=&val;
cout<<*p<<" "<<*p+1<<" "<<*(p+1)<<endl;//5 6 6422264
cout<<&p<<" "<<&p+1<<" "<<endl;//0x61fef8 0x61fefc 
//&(p+1) -> error

->its important to specify datatype to which pointer is pointing beacuse its useful while increment & decrement 
eg. int* p; p++ -> this will increment p by 4 bytes since next int will be at 4 bytes 

//30.types of pointer
1 null:
int val=5;
int* p;//pointing to garbage value
p=NULL;//pointing to null with 0 value
cout<<p;//0

2 double:
int val=7;
int* p=&val;
int** q=&p;

3 void: general pointer can point to any datatype . to dereference it needs to be typecasted 

4 wild: pointer pointing to unknown variable
int* p;//wild
int val=10;
p=&val;//not wild now

5 dangling: pointer pointing to variable which is freed or deleted


//31.Dynamic Memory Allocation 
1. Malloc

int* ptr=(int*) malloc(5*sizeof(int));

for(int i=0;i<5;i++) 
{
	ptr[i]=2*i;
}

if(ptr==NULL) cout<<"cannot assign";
//else it returns void ptr which we typecasted using (int*) before malloc
for(int i=0;i<5;i++)
{
	cout<<*(ptr+i)<<" ";//0 2 4 6 8 
}

free(ptr);

2. Calloc
int* ptr=(int*) calloc(5,sizeof(int));

for(int i=0;i<5;i++)
{
	cout<<*(ptr+i)<<" ";//0 0 0 0 0 
}

->calloc assign memory and initialise to 0 whereas malloc contains garbage value

3. Realloc
int* ptr=(int*) realloc(ptr,10*sizeof(int));
//changing size dynamically realloc(prev ptr,n * size);

4. Free
free(ptr);

heap-> dynamic memory allocation //global variable,static variables and program instrucions
stack->compile time //local

//32.new -> dynamic
int *arr=new int[10];//int a[10] static
int *var=new int ;

delete [] arr;
delete var;

//33.inline 
replace function call with definition

//34.const
const int a=5;
a++;//error

-> initialise during declaration else permanent garbage

//35.Array
int arr[10];

int n;cin>>n;
int arr[n];

//(a+1)[5] -> * (a+1+5) -> a[6]
a[2] means *(a+2) so a[2]=2[a]=*(a+2)

//36.matrix
swapping all a[i][j] with a[j][i] will give same matrix as swapping done twice

//37.2D array r & c
int a[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

	int r=sizeof(a)/sizeof(a[0]);
	int c=sizeof(a[0])/sizeof(int);
	cout<<r<<" "<<c;

//38.array initialised to garbage
int a;
cout<<a<<endl;//garbage

int arr[5];
for(int val:arr) cout<<val<<" ";//garbage
	
//39.swap & reverse
	// Function to reverse array
void reverseArray(int arr[], int start, int end, int size) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // Function calling
    reverseArray(arr, 0, n - 1, n);
    return 0;
}

//40.rotate
rot=rot%n;
    
    reversef(0,rot-1,a);
    reversef(rot,n-1,a);
    reversef(0,n-1,a);

//41.kth largest and smallest
void kthSmallestLargest(int arr[], int n, int k) {
    //Write your code here
    sort(arr,arr+n);
    
    //kth largest
    int idx=n-1;
    int m=INT_MAX;
    int c=0;
    bool f=1;
    
    while(idx>=0)
    {
        if(arr[idx]<m)
        {
            m=arr[idx];
            c++;
        }
        if(c==k)
        {
            f=0;
            cout<<arr[idx]<<" ";
            break;
        }
        idx--;
    }
    if(f) cout<<-1<<" ";
    
    //kth smallest
    idx=0;
    f=1;
    c=0;
    m=INT_MIN;
    while(idx<n)
    {
        if(arr[idx]>m)
        {
            m=arr[idx];
            c++;
        }
        if(c==k)
        {
            f=0;
            cout<<arr[idx]<<endl;
            break;
        }
        idx++;
    }
    if(f) cout<<-1<<endl;
    
}

//42.sort 012
//Dutch National Flag Algo or 3 way partition
void sort012(int arr[], int n) {
    //Write your code here
    int i=0,j=0,k=n-1;
    while(j<=k)
    {
        if(arr[j]==1) j++;
        else if(arr[j]==0) swap(arr[i++],arr[j++]);
        else swap(arr[j],arr[k--]);
    }
}

//sort even odd
vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        //even odd
        while(i<j)
        {
            if(nums[i]%2==0) i++;
            else if(nums[j]&1) j--;
            else swap(nums[i++],nums[j--]);

        }
        return nums;
    }

//43.char array
char str[]="Hi Kam\0al .";
cout<<str<<" "<<sizeof(str)<<endl;//Hi Kam 12

char s2[50];
cin.get(s2,50);//my nam\0e is
cout<<s2<<endl;//my nam\0e is

s2[1]='K';
cout<<s2<<endl;//mK nam\0e is

//44.concat
s1+s2;
s1.append(s2);

//45.strcmp(s1,s2) & s1.compare(s2)
char s1[50]="Kamal k";
char s2[50]="Kaathari .";

cout<<strcmp(s1,s2);//0 if equal , +ve if first greater , -ve else

string s1="Kamal k";
string s2="Kaathari .";
string s3="Kamal k";

cout<<s1.compare(s2)<<" "<<s1.compare(s3);//1 0

//46.size() reverse() sort()
string s1="Kamal k";
cout<<s1.size()<<endl;//7

reverse(s1.begin(), s1.end());
cout<<s1<<endl;//k lamaK

sort(s1.begin(), s1.end());
cout<<s1<<endl;// Kaaklm

cout<<(int)' '<<endl;//32 ascii of space

//47.max occuring char
//kbbamalab a answer in lexicographical order
string s;
getline(cin,s);
int arr[26]={0};//all 0

for(int i=0;i<s.size();i++)
{
	arr[s[i]-'a']++;
}
int max=0;
char ch;
for(int i=0;i<26;i++)
{
	if(arr[i]>max) {max=arr[i];ch='a'+i;}

}
cout<<ch;

//kbbamalab b answer in order of left to right
char maxch(string& s)
{
	//cout<<"y";
	int n=s.size();
	vector<int> v(26);
	for(int i=0;i<n;i++)
	{
		v[s[i]-'a']++;
	}
	char ch;
	int maxi=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(v[s[i]-'a']>maxi)
		{
			ch=s[i];
			maxi=v[s[i]-'a'];
		}
	}
	return ch;
}

//48.all substring

string s;
getline(cin,s);//kamal v ko
// cout<<s.substr(2)<<endl;//mal v ko
// cout<<s.substr(2,3)<<endl;//mal -> 3char starting from 2nd position


for(int i=0;i<s.size();i++)
{
	for(int j=i;j<s.size();j++)
	{
		cout<<s.substr(i,j-i+1)<<endl;
	}
}

for (int i = 0; i < n; i++)
    for (int len = 1; len <= n - i; len++)
        cout << s.substr(i, len) << endl;

//49.reverse string wordwise
#include <bits/stdc++.h>
using namespace std;

string trims(string s)
{
    string news;
    int siz=s.size();
    int i=0,j=siz-1;
    while(i<siz && s[i]==' ') i++;
    while(j>=0 && s[j]==' ') j--;
    
    while(i<=j)
    {
        if(s[i]==' ')
        {
            while(i<=j && s[i]==' ') i++;
            news.push_back(' ');
        }
        else 
        {
            news.push_back(s[i]);
            i++;
        }
    }
    
    return news;
}

void rev (string &str,int s,int e)
{
	while(s<e)
	{
		swap(str[s++],str[e--]);
	}
}

string reverseStringWordWise(string input)
{
    //Write your code here
    //clear leading trailing and inbetween 
    input=trims(input);
    reverse(input.begin(), input.end());
    int ss=input.size();
    int start=0;
    for(int i=0;i<=ss;i++)
    {
    	if(i==ss || input[i]==' ')
    	{
    		rev(input,start,i-1);
    		start=i+1;
    	}
    }
    return input;
}

int main()
{
    string s;
    getline(cin, s);
    string ans = reverseStringWordWise(s);
    cout << ans << endl;
}

//50.Ispermutation
bool isPermutation(char input1[], char input2[]) {
    // Write your code here
    int m=sizeof(input1)/sizeof(char);
    int n=sizeof(input2)/sizeof(char);
    if(m!=n) return 0;
    int arr[26]={0};
    for(int i=0;i<m;i++)
    {
        arr[input1[i]-'a']++;
    }
    for(int i=0;i<n;i++)
    {
        if(arr[input2[i]-'a']==0) return 0;
        arr[input2[i]-'a']--;
    }
    for(int val: arr)
    {
        if(val!=0) return 0;
    }
    return 1;
}

//51.traverse without knowing size
for (int i = 0; input1[i] != '\0'; ++i) {
        ++frequency[input1[i]];
    }

//52.remove consecutive duplicates
string removeConsecutiveDuplicates(string input)
{
    int ss=input.size();
    string ans;
    int j;
    for(int i=0;i<ss;)
    {
        ans.push_back(input[i]);
        j=i+1;
        while(j<ss && input[j]==input[i]) j++;
        i=j;
    }
    return ans;
}

//53.reverse each word 
if we reach end or we get space then reverse

//54.access modifiers in oops
private : 
can be accessed only in function 
protected :
can be accessed in function as well as inherited class but not via main or other class 
public :
can be accessed from anywhere 

//55 Class and object
#include <bits/stdc++.h> 
using namespace std;

class house{
	//bydefault private 
	int len,bre;//member variable
public:
	void setData(int x,int y)//member function 
	{
		cout<<"set\n";
		len=x;
		bre=y;
	}

	void area()
	{
		cout<<"area\n";
		cout<<len*bre<<endl;
	}
};

int main() {

    house h1;//memory allocated when object is created
    h1.area();//garbage 
	h1.setData(2,3);
	h1.area();//6

    return 0;
}

//56
member variable will get seperate space for every object but member function can be 
used comman for all objects of same class 

Encapsulation: wraping up variables and functions together
Abstraction: Hiding complicated things from user 


//57 Constructors 
//without
class A{
private:
	int a;
public:
	void setD(int x=0)
	{
		a=x;
	}
	int getD()
	{
		return a;
	}
	
};

int main() {

	A obj;
	cout<<obj.getD()<<endl;//garbage
	obj.setD(3);//we need to set data 
	cout<<obj.getD()<<endl;//3

//with 
class A{
private:
	int a;
public:
	// void setD(int x=0)
	// {
	// 	a=x;
	// }
	A(int x)
	{
		//cout<<"c\n";
		a=x;
	}
	int getD()
	{
		return a;
	}
	
};

int main() {

	// A obj;
	// cout<<obj.getD()<<endl;//garbage
	// obj.setD(3);
	// cout<<obj.getD()<<endl;//3

	A obj(4);
	cout<<obj.getD()<<endl;//4

//-> rules for constructor 
		same name, no return type,public .

//58 default constructor
class A{
private:
	int a;
public:
	// void setD(int x=0)
	// {
	// 	a=x;
	// }
	A()
	{
		cout<<"default/non parameterised"<<endl;
		a=0;//this is optional. A(){} this is also valid 
		//optional to initialise else it will contain garbage
	}

	int getD()
	{
		return a;
	}
	
};

int main() {

	// A obj;
	// cout<<obj.getD()<<endl;//garbage
	// obj.setD(3);
	// cout<<obj.getD()<<endl;//3

	A obj;
	cout<<obj.getD()<<endl;//0

//59 Parameterised Constructor
//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class Person{
private:
	string name;int age;float height;
public:
	Person()
	{
		name="NULL";
		age=0;
		height=0.0f;
	}
	Person(string name_a,int age_a,float height_a)
	{
		name=name_a;
		age=age_a;
		height=height_a;
	}
	void getD()
	{
		cout<<name<<" "<<age<<" "<<height<<endl;
	}
};

int main() {

	Person obj1,obj2("kamal",22,5.2);
	obj1.getD();
	obj2.getD();
    return 0;
}

//60 copy constructor
//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class Person{
private:
	string name;int age;float height;
public:
	Person()
	{
		name="NULL";
		age=0;
		height=0.0f;
	}

	Person(string name_a,int age_a,float height_a)
	{
		name=name_a;
		age=age_a;
		height=height_a;
	}

	Person(Person &obj2)//copy
	{
		name=obj2.name;
		age=obj2.age;
		height=obj2.height;
	}

	void getD()
	{
		cout<<name<<" "<<age<<" "<<height<<endl;
	}
};

int main() {

	Person obj1,obj2("kamal",22,5.2);
	Person obj3(obj2);
	obj1.getD();
	obj2.getD();
	obj3.getD();

    return 0;
}

//61 constructor overloading 
same constructor for different use 
A()//default
{
	a=0;
}
A(int x)//parameterised
{
	a=x;
}

overloading
A(int x=0)//default + parameter
{
	a=x;
}

//62 program
//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class Mob
{
private:
	string name;
	int Ram;
	string processor;
	int battery;
public:
	Mob(string name_a="NULL",int Ram_a=0,string processor_a="NULL",int battery_a=0)
	{
		name=name_a;
		Ram=Ram_a;
		processor=processor_a;
		battery=battery_a;
	}

	Mob(Mob &mob)
	{
		name=mob.name;
		Ram=mob.Ram;
		processor=mob.processor;
		battery=mob.battery;
	}

	void getD();
};

void Mob::getD() //return_type class_name :: function 
{
	cout<<name<<endl;
	cout<<Ram<<endl;
	cout<<processor<<endl;
	cout<<battery<<endl;

}

int main() {

	Mob o1("MI",8,"SnapD",5000),o2,o3(o1);

	o1.getD();
	o2.getD();
	o3.getD();
	
    return 0;
}

//63 Operator Overloading
-> when operator can work for user defined datatype its called overloaded

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class Person
{
	int weight;

public:
	Person(int x=0)
	{
		weight=x;
	}
	void getD()
	{
		cout<<"Weight is "<<weight<<endl;
	}
	Person operator + (Person w)// return_type operator +/-/*// (operand after operator)
	{
		Person temp;
		temp.weight = weight + w.weight;
		return temp;
	}
};

int main() {

	Person p1(30),p2(40),p3;
	p3=p1+p2;
	p1.getD();//30
	p2.getD();//40
	p3.getD();//70

	p1=p1+p2;
	p1.getD();//70
	p2.getD();//40
	p3.getD();//70
	
    return 0;
}

//64 Traditional method 

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class Person
{
	int weight;

public:
	Person(int x=0)
	{
		weight=x;
	}
	void getD()
	{
		cout<<"Weight is "<<weight<<endl;
	}
	// Person operator + (Person w)// return_type operator +/-/*// (operand after operator)
	// {
	// 	Person temp;
	// 	temp.weight = weight + w.weight;
	// 	return temp;
	// }
	Person addWeight (Person other)
	{
		Person temp;
		temp.weight=weight + other.weight;
		return temp;
	}
};

int main() {

	Person p1(30),p2(40),p3;
	p3=p1.addWeight(p2);
	p1.getD();//30
	p2.getD();//40
	p3.getD();//70

	p1=p1.addWeight(p2);
	p1.getD();//70
	p2.getD();//40
	p3.getD();//70
	
    return 0;
}

//65 pre and post

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class Person
{
	int weight;
public:
	Person(int x=0)
	{
		weight=x;
	}
	void getD()
	{
		cout<<"W "<<weight<<endl;
	}
	void operator++()
	{
		++weight;
	}
	void operator++(int)
	{
		weight++;
	}
};

int main() {

	Person o1(20);
	o1.getD();

	++o1;
	o1.getD();//21

	o1++;
	o1.getD();//22


    return 0;
}

//a2 
#include <bits/stdc++.h>
using namespace std;

class Val
{
	int v;
public:
	Val(int x=0)
	{
		v=x;
	}
	Val  operator ++ ()
	{
		v++;
		return *this;
	}
	Val operator++ (int dummy)
	{
		Val temp=*this;
		++(*this);
		return temp;
	}
	void getD()
	{
		cout<<v<<endl;
	}
};

int main() {

	Val o1(100);
	o1.getD();
	o1++.getD();//no bracket needed
	o1.getD();

	(++o1).getD();
	o1.getD();
    return 0;
}

//66 pre and post with object return type

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class Person
{
	int weight;
public:
	Person(int x=0)
	{
		weight=x;
	}
	void getD()
	{
		cout<<"W "<<weight<<endl;
	}
	Person operator++()
	{
		Person temp;
		temp.weight=++weight;
		return temp;
	}
	Person operator++(int)
	{
		Person temp;
		temp.weight=weight++;
		return temp;
	}
};

int main() {

	Person o1(20),o2;
	o2=++o1;
	o1.getD();//21
	o2.getD();//21

	o2=o1++;
	o1.getD();//22
	o2.getD();//21

	(++o1).getD();//23
	o1.getD();//23

	(o1++).getD();//23
	o1.getD();//24


    return 0;
}



//67 Inheritance

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class Rectangle
{
public:
	int length,breadth;

	void area()
	{
		cout<<"area is "<<length*breadth<<endl;
	}
};

class Cuboid : public Rectangle//Inheritance 
//class child : public parent 
{
public:
	int height;

	void volume()
	{
		cout<<"volume is "<<length*breadth*height<<endl;
	}
};

int main() {

	Rectangle r;
	r.length=10;
	r.breadth=5;
	r.area();//50

	Cuboid c;
	c.length=20;
	c.breadth=10;
	c.height=5;
	c.volume();//1000
	//c.area();//200


    return 0;
}

//68 Inheritance and constructor part1

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class B
{
public:
	B()
	{
		cout<<"Default of Base\n";
	}
	B(int x)
	{
		cout<<"Parameterised of Base "<<x<<endl;
	}
};

class D : public B
{
public:
	// D()
	// {
	// 	cout<<"Default of Derived\n";
	// }
	// D(int x)
	// {
	// 	cout<<"Parameterised of Derived "<<x<<endl;
	// }
};

int main() {

	D obj1;//Default of Base
	//D obj2(10);//error 

	//-> derived class has option to have default constructor ,
		//if its present then B default- D default  , if absent only B default
	
    return 0;
}

//69 part2

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class B
{
public:
	B()
	{
		cout<<"Default of Base\n";
	}
	B(int x)
	{
		cout<<"Parameterised of Base "<<x<<endl;
	}
};

class D : public B
{
public:
	D()
	{
		cout<<"Default of Derived\n";
	}
	D(int x)
	{
		cout<<"Parameterised of Derived "<<x<<endl;
	}
};

int main() {

	D obj1;

	cout<<endl;
	
	D obj2(10);

	
/*
Default of Base
Default of Derived

Default of Base
Parameterised of Derived 10

*/
    return 0;
}

//70 part 3

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class B
{
public:
	B()
	{
		cout<<"Default of Base\n";
	}
	B(int x)
	{
		cout<<"Parameterised of Base "<<x<<endl;
	}
};

class D : public B
{
public:
	D():B()
	{
		cout<<"Default of Derived\n";
	}
	D(int y):B(y)
	{
		cout<<"Parameterised of Derived "<<y<<endl;
	}
};

int main() {

	D obj1;

	cout<<endl;

	D obj2(10);

	
/*
Default of Base
Default of Derived

Parameterised of Base 10
Parameterised of Derived 10

*/
    return 0;
}

//71 Overriding 

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class B
{
public:
	void Msg()
	{
		cout<<"In Base\n";
	}
};

class D : public B
{
public:
	void Msg()
	{
		cout<<"In derived\n";
		//B::Msg();//if we want to execute base function from derived object
	}

};

int main() {

	B ob1;
	ob1.Msg();//in base

	D ob2;
	ob2.Msg();//in derived

    return 0;
}

//72 isA (inheritance full exposure ) vs hasA (object limited exposure)

class vehicle{//vehicle hasA engine
	//vehicle hasA tire 
	//Car isA vehicle
	engine e;
	tire t;
};

class engine{};

class tire{};

class car{};

//73 Polymorphism 

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class B{

public:
	virtual void show()
	{
		cout<<"B\n";
	}

};

class D1 : public B
{
public:
	void show()
	{
		cout<<"D1\n";
	}
};

class D2 : public B
{
public:
	void show()
	{
		cout<<"D2\n";
	}
};

int main() {

	D1 o1;
	B *ptr= &o1;
	ptr->show();//D1 //if virtual is removed o/p B 

	//to access object of D1 make B as virtual

    return 0;
}

//74 Why VF

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class Person{

public:
	virtual void show()
	{
		cout<<"Bun\n";
	}

};

class boy : public Person
{
public:
	void show()
	{
		cout<<"Brown bun\n";
	}
};

class girl : public Person
{
public:
	void show()
	{
		cout<<"Pink bun\n";
	}
};

int main() {

	boy o1;
	girl o2;

	Person *ptr=&o1;
	ptr->show();//Brown bun

	ptr=&o2;
	ptr->show();//Pink bun

    return 0;
}

//75 Abstract Class
class Person{//class containing pure virtual function becomes
// Abstract class because no object of this class can be created 
	

public:
	virtual void show() = 0;//pure virtual function
	
	//no body else error
};

//76 Types of Polymorphism 
1 Compile time -> operator overloading, function overloading
2 Run time -> virtual function, function overriding

//77 Virtual Destructor

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class B{
public:
	virtual~B()
	{
		cout<<"Base Class Destructor\n";
	}
};

class D:public B{
public:
	~D()
	{
		cout<<"Derived Class Destructor\n";
	}
};

int main() {

	B *ptr=new D;
	delete ptr;//Base Class Destructor

	//to delete derived and base both give virtual ~B()
		//o/p 	Derived Class Destructor
		//		Base Class Destructor
    return 0;
}

//78 Friend

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class A{
private:
	int a;
public:
	A(int x=0)
	{
		a=x;
	}

	friend void fun();
};

class B{
private:
	int b;
public:
	B(int y=0)
	{
		b=y;
	}

	friend void fun();
};

void fun()
{
	A o1(3);
	B o2(4);

	int s= o1.a + o2.b;
	cout<<"sum "<<s<<endl;
}

int main() {

	fun();//sum 7


    return 0;
}

//79 > < 

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class Person{
private:
	int wt;
public:
	Person(int x=0)
	{
		wt=x;
	}

	friend bool operator > (Person a,Person b);
	friend bool operator < (Person a,Person b);
};

bool operator > (Person a,Person b)
{
	return a.wt>b.wt;
}

bool operator < (Person a,Person b)
{
	return a.wt<b.wt;
}

int main() {

	
	Person Jon(50);
	Person Ron(60);

	if(Jon > Ron) cout<<"Jon is heavy\n";
	else if(Jon < Ron) cout<<"Ron is heavy\n";

	//o/p:Ron is heavy
    return 0;
}

//80 Friend class

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class A{

int a1;
public:
	A(int x=0)
	{
		a1=x;
	}
	friend class B;
};

class B{
private:
	int b1;
public:
	B(int y=0)
	{
		b1=y;
	}

	int S()
	{
		A obj(8);

		int sum=obj.a1 + b1;

		return sum;
	}
};

int main() {

	B ob2(10);

	cout<<ob2.S();//18
	
    return 0;
}

//81 static -> belong to class , one for class comman for objectF

//#include <bits/stdc++.h> 
#include <iostream>
#include <string>
using namespace std;

class A{

int a1;
public:
	A(int x=0)
	{
		a1=x;
		stat++;
	}

	static int stat ;
	
};

int A:: stat=0;

int main() {

	A o1(3);
	A o2(4);
	cout<<o1.stat<<endl;//2 
	cout<<o2.stat<<endl;//2
	cout<<A::stat<<endl;//2
    return 0;
}

//82 Complex numbers plus & multiply
#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

class ComplexNumbers {
    // Complete this class
private:
	int re,im;
public:
	ComplexNumbers(int r=0,int i=0)
	{
		re=r;
		im=i;
	}

	void print()
	{
		cout<<re<<" + i"<<im<<endl;
	}

	void plus(ComplexNumbers com2)
	{
		re+=com2.re;
		im+=com2.im;
	}

	void multiply(ComplexNumbers com2)
	{
		// ComplexNumbers temp;
		// temp.re=((re)*(com2.re)) - ((im)*(com2.im));
		// temp.im=((re)*(com2.im)) + ((im)*(com2.re));

		// re=temp.re;
		// im=temp.im;

		int a=re*com2.re - im*com2.im;
		int b=re*com2.im + im*com2.re;
		re=a;
		im=b;
	}

};

int main() {
    int real1, imaginary1, real2, imaginary2;

    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;

    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);

    int choice;
    cin >> choice;

    if (choice == 1) {
        c1.plus(c2);
        c1.print();
    } else if (choice == 2) {
        c1.multiply(c2);
        c1.print();
    } else {
        return 0;
    }

}

//83 Fraction
#include <bits/stdc++.h> 
using namespace std;
#define ll long long

int gcdf(int a,int b)
{
	if(b==0) return a;
	else return gcdf(b,a%b);
}

class Fraction{

	int num,den;
public:
	Fraction(int x=0,int y=0)
	{
		num=x;
		den=y;
	}

	void add (Fraction two)
	{
		int n= num * two.den + den * two.num;
		int d= den * two.den;
		num=n;
		den=d;
	}

	void multiply (Fraction two)
	{
		int n= num * two.num ;
		int d= den * two.den ;
		num=n;
		den=d;
	}

	void simplify()
	{
		int gcdval = gcdf(num,den);//__gcd(num,den)
		num/=gcdval;
		den/=gcdval;
	}

	void update(int x=0,int y=0)
	{
		num=x;
		den=y;
	}

	void print()
	{
		cout<<num<<"/"<<den<<endl;
	}
};

int main()
{
	int n1,n2,d1,d2,q,n;

	cin>>n1>>d1;
	Fraction o1(n1,d1),o2;

	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>n>>n2>>d2;
		o2.update(n2,d2);

		switch (n)
		{
			case 1: o1.add(o2);
					o1.simplify();
					o1.print();
					break;

			case 2: o1.multiply(o2);
					o1.simplify();
					o1.print();
					break;

			default: cout<<"Incorrect\n";
		}
	}


	return 0;
}
//a2 
#include <iostream>

#include<algorithm>

using namespace std;

class Fraction {
    private:

    int numerator;
    int denominator;

    public:

        Fraction(int numerator, int denominator) {
            this -> numerator = numerator;
            this -> denominator = denominator;
        }

    void print() {
        cout << this -> numerator << "/" << denominator << endl;
    }

    void simplify() {
        int gcd = __gcd(this -> numerator, this -> denominator);
        this -> numerator = this -> numerator / gcd;
        this -> denominator = this -> denominator / gcd;
    }

    void add(Fraction
        const & f2) {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        numerator = num;
        denominator = lcm;
        simplify();
    }

    void multiply(Fraction
        const & f2) {
        numerator = numerator * f2.numerator;
        denominator = denominator * f2.denominator;

        simplify();
    }

};

int main() {
    int num1, den1;
    cin >> num1 >> den1;
    Fraction f(num1, den1);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int num2, den2;
            cin >> num2 >> den2;
            Fraction f2(num2, den2);
            f.add(f2);
            f.print();
        } else if (type == 2) {
            int num2, den2;
            cin >> num2 >> den2;
            Fraction f2(num2, den2);
            f.multiply(f2);
            f.print();
        }
    }

    return 0;
}

//84 deep copy -> different memory

//85 Multiple inheritance 
 	//C is inheriting from A and B 
class C : public A, public B {

};

//86 Types of Inheritance
single
multilevel
multiple
hierarchical->one base class has more than 1 child //one class parent for many child
hybrid
 
//87 car racecar
class RaceCar: public Car {
    public: int maxSpeed;

    RaceCar(int noOfGear, string color, int maxSpeed): Car(noOfGear, color) {

        this -> maxSpeed = maxSpeed;
    }

    void printRaceCarInfo() {
        printCarInfo();
        cout << "maxSpeed: " << this -> maxSpeed;
    }
};

//88 Shape square rectangle
#include<iostream>

using namespace std;

class Shape {
    public:
    string shapeType;

    Shape(string shapeType) {
        this -> shapeType = shapeType;
    }

    void printMyType() {
        cout << this -> shapeType << endl;
    }
};

class Square: public Shape {
    public:
    int length;

    Square(string shapeType, int length): Shape(shapeType) {
        this -> length = length;
    }

    void printMyType() {
        cout << this -> shapeType << endl;
    }

    int calculateArea() {
        return this -> length * this -> length;
    }
};

class Rectangle: public Shape {
    public:
    int length;
    int breadth;

    Rectangle(string shapeType, int length, int breadth): Shape(shapeType) {
        this -> length = length;
        this -> breadth = breadth;
    }

    void printMyType() {
        cout << this -> shapeType << endl;
    }

    int calculateArea() {
        return this -> length * this -> breadth;
    }
};

int main() {

    Square square("square", 5);
    square.printMyType();
    cout << square.calculateArea() << endl;

    Rectangle rectangle("rectangle", 5, 4);
    rectangle.printMyType();
    cout << rectangle.calculateArea() << endl;

}

//a2
#include <bits/stdc++.h> 
#include<iostream>

using namespace std;

// Create the classes here
class Shape{
public:
	string shapeType;

	void printMyType()
	{
		cout<<shapeType<<endl;
	}
};

class Square:public Shape{
public:
	int length;
	Square(int x=0) 
	{
		length=x;
	}
	void printMyType()
	{
		cout<<"square"<<endl;
	}

	int calculateArea()
	{
		return length*length;
	}
};

class Rectangle:public Shape{
public:
	int length,breadth;
	Rectangle(int x=0,int y=0)
	{
		length=x;
		breadth=y;
	}
	void printMyType()
	{
		cout<<"rectangle"<<endl;
	}

	int calculateArea()
	{
		return length*breadth;
	}
};



int main() {

    //Write your code here
	Square s(5);
	s.printMyType();
	cout<<s.calculateArea()<<endl;

	Rectangle r(5,4);
	r.printMyType();
	cout<<r.calculateArea()<<endl;

    return 0;
}

//89 Exception handling (try throw catch)
#include <bits/stdc++.h> 
using namespace std;

int main() {

	try
	{
		int age=12;
		if(age>=18) cout<<"Voting allowed\n";
		else throw(age);
	}
	catch(int age)
	{
		cout<<"cant vote below 18 "<<age<<endl;
	}
	  
    return 0;
}
//catch(...) //handle all exception but declare it last
//catch all

//90 stl algo & math
sort(arr,arr+n);
sort(arr,arr+n,greater <int>());//descending
sort(v.begin(), v.end());
sort(v.begin(), v.end(),greater<int>());
binary_search(v.begin(), v.end(),6);
reverse(v.begin(), v.end());
*max_element(v.begin(), v.end());
*min_element(v.begin(), v.end());
accumulate(v.begin(), v.end(),0);//sum all elements , initial value =0 
count(v.begin(), v.end(),2)//count occurence of 2

if(find(v.begin(), v.end(),3) != v.end())
    {
    	cout<<"f"<<endl;
    }
    else cout<<"nf"<<endl;

lower_bound(v.begin(), v.end(),5)-v.begin()//index of first element not less than 5
upper_bound(v.begin(), v.end(),5)-v.begin()//index of first element greater than 5

sqrt(5)//2.23607
abs(-10)//10
pow(2,3)//8
cout<<floor(2.3)<<endl;//2
cout<<floor(-2.3)<<endl;//-3
cout<<ceil(2.3)<<endl;//3
cout<<ceil(-2.3)<<endl;//-2

//91 ways to initialise vector
vector<int> vect;
vector<int> vect(n, 10);//vector of size n with all values 10
vector<int> vect{ 10, 20, 30 };

int arr[] = { 10, 20, 30 };
int n = sizeof(arr) / sizeof(arr[0]);
	vector<int> vect(arr, arr + n);

vector<int> vect1{ 10, 20, 30 }; 
vector<int> vect2(vect1.begin(), vect1.end());

vector<int> vect1(10);//bydefault all 10 values 0
int value = 5;
fill(vect1.begin(), vect1.end(), value);

//92 ways to initialise array
int arr[5];//garbage
int arr[5]={};//all 0
int arr[5]={2,3};//2 3 0 0 0
int arr[5]={};
 fill_n(arr,3,10);//10 10 10 0 0 

