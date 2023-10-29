#include <iostream>
#include <Windows.h>
#include "emp3.cpp"


using namespace std;

string get_str(){
    string s;
    getline(cin,s);
   if (cin.fail() || string::npos != s.find_first_of("0123456789")){
        cin.clear();
        cout << "INPUT ERROR! Enter a new string!"<< endl;
        getline(cin,s);
    }
    return s;
}

void Create_Director(director& dir){

     int sal;
     fflush(stdin);

     cout<<"Enter lastname "<<endl;
     dir.set_ln(get_str());
     cout << endl;

     cout<<"Enter firstname "<<endl;
     dir.set_fn(get_str());
     cout << endl;

     cout<<"Enter middlename "<<endl;
     dir.set_mn(get_str());
     cout << endl;

     cout<<"Enter salary "<<endl;
     cin>>sal;
     dir.set_salary(sal);
     cout << endl;

     cout<<"Директор создан"<<endl;

 }


void Create_Employee(director& dir){

    int salary;
    employee em;

	fflush(stdin);


	cout << "Enter lastname "<<endl;
	em.set_ln(get_str());
	cout << endl;

	cout << "Enter firstname "<<endl;
	em.set_fn(get_str());
	cout << endl;

	cout << "Enter middlename " <<endl;
	em.set_mn(get_str());
	cout << endl;

    cout<<"Enter salary "<<endl;
    cin>>salary;
    em.set_salary(salary);
    cout << endl;

	dir.add_empl(em);

 }



int main()
{
    setlocale(LC_ALL,"Russian");
    director dir;
    secretary  s1("fds","yyy","fds",340);

    Create_Director(dir);


    Create_Employee(dir);
    cout << "==============Работники==============" << endl;
	for (int i = 0; i < dir.get_emp_vec().size(); i++) {

		cout << "Номер: " << i << " " << dir.get_emp_vec()[i].get_ln()<< endl;
	}
	cout << "=====================================" << endl;

    s1.show_employee(dir);



    return 0;
}








/*cout << "==============Работники==============" << endl;
	for (int i = 0; i < dr1.get_emp_vec().size(); i++) {

		cout << "Номер: " << i << " " << dr1.get_emp_vec()[i].get_ln()<< endl;
	}
	cout << "=====================================" << endl;*/
