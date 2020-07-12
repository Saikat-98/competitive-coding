/*
	1. custom hash function
	2. == operator overloading
*/

#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

class Student{
public:
	string firstname;
	string lastname;
	int rollno;

	Student(string f, string l, int n){
		firstname=f;
		lastname=l;
		rollno=n;
	}

	bool operator==(const Student &s) const{
		return rollno==s.rollno?true:false;
	}
};

class HashFn{
public:
	size_t operator()(const Student &s) const{
		return s.firstname.length()+s.lastname.length();
	}
};

int main(){

	unordered_map<Student,int, HashFn> m;

	Student s1("Saikat","Choudhury",123);
	Student s2("Rahul","Kumar",34);
	Student s3("Prateek","Narang",30);
	Student s4("Saikat","Choudhury",120);

	m[s1]=100;
	m[s2]=120;
	m[s3]=11;
	m[s4]=44;

	for(auto s:m)
		cout<<s.first.firstname<<" "<<s.first.rollno<<" "<<s.second<<" "<<m[s2]<<endl;
	
	return 0;
}