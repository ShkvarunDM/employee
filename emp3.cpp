#include<iostream>
#include <string>
#include <vector>
#include "emp3.h"


using std::string;
using std::vector;

//àáñòðàêòíûå êëàññû

FIO::FIO(){
    lastname="";
    firstname="";
    middlename = "";
};

salary::salary(){
    sal = 0;
}


//êëàññ ñîòðóäíèê
employee::employee():FIO(), salary(){     //êîíñòðóêòîð ïî óìîë÷àíèþ

};


void employee::set_ln(const string& ln){
    this->lastname = ln;
}
void employee::set_fn(const string& fn){
    this->firstname = fn;
}
void employee::set_mn(const string& mn){
    this->middlename = mn;
}
void employee::set_fio(const string& ln,const string& fn,const string& mn){
    this->lastname = ln;
    this->firstname = fn;
    this->middlename = mn;
}

void employee::set_salary(int sal1){
    this->sal = sal1;
}

employee::employee(const string& ln,const string& fn,const string& mn,int sal1){
    set_fio(ln,fn,mn);
    set_salary(sal1);
}

string employee::get_ln(){
    return this->lastname;
}

string employee::get_fn(){
    return firstname;
}

string employee::get_mn(){
    return middlename;
}

int employee::get_salary(){
    return sal;
}



//ÏÐÎÃÐÀÌÌÈÑÒ//

programmer::programmer():employee(){
    technology = new vector<string>;
}

 programmer::programmer(const string& lev, const string& ln, const string& fn,  const string& mn, int sal1):
    employee(ln,fn,mn,sal1){
    technology = new vector<string>;
 }

 void  programmer::set_level(string lev){
     level = lev;
 }

 void programmer::add_technology(string tech){
     this->technology->push_back(tech);
 }

string programmer::get_level(){
    return this->level;
}

vector<string>& programmer::get_vec_techn(){
    return *this->technology;
}



//Âîäèòåëü
driver::driver(const string& ln, const string& fn,  const string& mn, int sal1):
    employee(ln,fn,mn,sal1){
    this->categories = new vector<string>;
    this->transport = new vector<string>;
}

void driver::add_categories(const string& cat){
    this->categories->push_back(cat);
}

void driver::add_transport(const string& tr){
     this->transport->push_back(tr);
}

vector<string>& driver::get_categories(){
    return *this->categories;
}
vector<string>& driver::get_transport(){
    return *this->transport;
}




//äèðåêòîð

director::director( const string& ln, const string& fn,  const string& mn, int sal1):
    employee(ln,fn,mn,sal1){
    empl_vec = new vector<employee>;
    prog_vec = new vector<programmer>;
    driver_vec = new vector<driver>;
}


void director::add_empl(const string& ln, const string& fn, const string& mn, int sal1){
    employee em(ln,fn,mn,sal1);
    empl_vec->push_back(em);
}

void director::add_empl(employee& em){
    empl_vec->push_back(em);
}



 void director::add_prog(programmer & pr){
     prog_vec->push_back(pr);
 }

void director::add_driver(driver & dr){
    driver_vec->push_back(dr);
}

vector<employee>& director::get_emp_vec(){
    return *empl_vec;
}

vector<programmer>& director::get_prog_vec(){
    return *prog_vec;
}

vector<driver>& director::get_driver_vec(){
    return *driver_vec;
}


void director::del_empl(int index){
    empl_vec->erase(empl_vec->begin()+index);
}











secretary::secretary(const string& ln, const string& fn,  const string& mn, int sal1):
    employee(ln,fn,mn,sal1){
}

void secretary::show_employee(director& dir){

    using std::left;
    using std::setw;

    std::cout<<"=======================EMPLOYEE==========================="<<std::endl;

    std::cout << left << setw(6) <<"Num"<< left << setw(15) << "Lastname" << left << setw(15) << "Firstname"<< left
         << setw(15)<< "Middlename" << left << setw(15) << " Salary "<< std::endl;

    for(int i=0; i< dir.get_emp_vec().size();i++){

            std::cout<< std::left << std::setw(6)<< i;
            std::cout<< std::left << std::setw(15)<< dir.get_emp_vec()[i].get_ln();
            std::cout<< std::left << std::setw(15)<< dir.get_emp_vec()[i].get_fn();
            std::cout<< std::left << std::setw(15)<< dir.get_emp_vec()[i].get_mn();
            std::cout<< std::left << std::setw(15)<< dir.get_emp_vec()[i].get_salary()<<std::endl;
    }
     std::cout<<"=========================================================="<<std::endl;
}


void secretary::show_programmer(std::vector<programmer>& pr){
    using std::left;
    using std::setw;

    std::cout<<"=======================PROGRAMMERS==========================="<<std::endl;

    std::cout << left << setw(6) <<"Num"<< left << setw(15) << "Lastname" << left << setw(15) << "Firstname"<< left
         << setw(15)<< "Middlename" << left << setw(15) << " Salary "<< setw(15) << " Level " << setw(30) << "Technology" << std::endl;

    for(int i=0; i< pr.size();i++){

            std::cout<< std::left << std::setw(6)<< i;
            std::cout<< std::left << std::setw(15)<< pr[i].get_ln();
            std::cout<< std::left << std::setw(15)<< pr[i].get_fn();
            std::cout<< std::left << std::setw(15)<< pr[i].get_mn();
            std::cout<< std::left << std::setw(15)<< pr[i].get_salary();
            std::cout<< std::left << std::setw(15)<< pr[i].get_level();


            for(int j=0;j < pr[i].get_vec_techn().size();j++){
                std::cout<<pr[i].get_vec_techn()[j]<<" ";
            }

            std::cout<<std::endl;
    }
     std::cout<<"=========================================================="<<std::endl;
}


void secretary::show_driver(std::vector<driver>& dr){
    using std::left;
    using std::setw;

    std::cout<<"==========================================DRIVERS==================================================="<<std::endl;

    std::cout << left << setw(6) <<"Num"<< left << setw(15) << "Lastname" << left << setw(15) << "Firstname"<< left
         << setw(15)<< "Middlename" << left << setw(15) << " Salary "<< setw(20) << " Categories " << setw(20) << "Transport" << std::endl;

         for(int i=0;i<dr.size();i++){
            std::cout<< std::left << std::setw(6)<< i;
            std::cout<< std::left << std::setw(15)<< dr[i].get_ln();
            std::cout<< std::left << std::setw(15)<< dr[i].get_fn();
            std::cout<< std::left << std::setw(15)<< dr[i].get_mn();
            std::cout<< std::left << std::setw(15)<< dr[i].get_salary();


         for(int j=0; j < dr[i].get_categories().size();j++){
             std::cout<< dr[i].get_categories()[j]<<" ";
         }

        std::cout<<"\t\t";

         for(int j=0; j < dr[i].get_transport().size();j++){
             std::cout<< dr[i].get_transport()[j]<<" ";
         }

         std::cout<<std::endl;
        }

        std::cout<<"===================================================================================================="<<std::endl;

}
