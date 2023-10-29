#ifndef EMP3_H_INCLUDED
#define EMP3_H_INCLUDED
#include <string>
#include<iostream>
#include <vector>


class FIO{
protected:
    std::string lastname;
    std::string firstname;
    std::string middlename;
public:
    FIO();
    virtual void set_ln(const std::string& ln)=0;
    virtual void set_fn(const std::string& fn)=0;
    virtual void set_mn(const std::string& mn)=0;
    virtual void set_fio(const std::string& ln,const std::string& fn,const std::string& mn)=0;

    virtual std::string get_ln()=0;
    virtual std::string get_fn()=0;
    virtual std::string get_mn()=0;
};


class salary{

protected:
    int sal;
public:
    salary();
    virtual void set_salary(int sal1)=0;
    virtual int get_salary()=0;

};


class employee:public FIO,public salary{
public:

    employee();
    employee(const std::string& ln,const std::string& fn,const std::string& mn,int sal1);

    virtual void set_ln(const std::string& ln) override;
    void set_fn(const std::string& fn)override;
    void set_mn(const std::string& mn)override;
    void set_fio(const std::string& ln,const std::string& fn,const std::string& mn)override;

    virtual std::string get_ln()override;
    virtual std::string get_fn()override;
    virtual std::string get_mn()override;

    virtual void set_salary(int sal1) override;
    virtual int get_salary() override;


};



class programmer:public employee{

    private:
        std::string level;
        std::vector<std::string>* technology;
    public:
        programmer();
        programmer(const std::string& lev, const std::string& ln, const std::string& fn,  const std::string& mn, int sal1);

        void add_technology(std::string tech);
        void set_level(std::string lev);

        std::string get_level();
        std::vector<std::string>& get_vec_techn();

};


class driver:public employee{

    private:
        std::vector<std::string> * categories;
        std::vector<std::string> * transport;
    public:
        driver(){};
        driver(const std::string& ln, const std::string& fn,  const std::string& mn, int sal1);

        void add_categories(const std::string& cat);
        void add_transport(const std::string& tr);

        std::vector<std::string>& get_categories();
        std::vector<std::string>& get_transport();
};

class director:public employee{

    private:
        std::vector<employee>* empl_vec;
        std::vector<programmer>* prog_vec;
        std::vector<driver>* driver_vec;
    public:
        director(){};
        director(const std::string& ln, const std::string& fn,  const std::string& mn, int sal1);

        void add_empl(const std::string& ln, const std::string& fn, const std::string& mn, int sal1);
        void add_empl(employee& em);
        void add_prog(programmer& pr);
        void add_driver(driver& dr);
        void del_empl(int index);

        std::vector<employee>& get_emp_vec();
        std::vector<programmer>& get_prog_vec();
        std::vector<driver>& get_driver_vec();
};


class secretary:public employee{
    public:
        secretary(){};
        secretary(const std::string& ln, const std::string& fn,  const std::string& mn, int sal1);

        void show_employee(director& dir);
        void show_programmer(std::vector<programmer>& pr);
        void show_driver(std::vector<driver>& dr);

};

#endif // EMP3_H_INCLUDED
