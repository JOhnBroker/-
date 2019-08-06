#ifndef INC_14_3_WORKER_H
#define INC_14_3_WORKER_H
#include <iostream>
#include <string>

class Worker {
private:
    std::string fullname;
    long id;
protected:
    virtual void Data()const;
    virtual void Get();
public:
    Worker():fullname("no one"),id(0){};
    Worker(const std::string &s,long n):fullname(s),id(n){};
    virtual ~Worker() =0;               //TODO：关于纯虚函数被调用问题还未解决
    virtual void Set() =0;
    virtual void Show() const =0;
};

class Waiter:virtual public Worker{
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter():Worker(),panache(0){};
    Waiter(const std::string &s,long n,int p=0):Worker(s,n),panache(p){};
    Waiter(const Worker& wk,int p=0):Worker(wk),panache(p){};
    ~Waiter(){};
    void Set();
    void Show()const;
};

class Singer:virtual public Worker{
protected:
    enum{other,alto,contralto,soprano,bass,baritone,tenor};
    enum{Vtypes=7};
    void Data()const ;
    void Get();
private:
    static char *pv[Vtypes];
    int voice;
public:
    Singer():Worker(){};
    Singer(const std::string &s,long n,int v=other):Worker(s,n),voice(v){};
    Singer(const Worker &wk,int v=other):Worker(wk),voice(v){};
    ~Singer(){};
    void Set();
    void Show() const;
};

class SingingWaiter:public Waiter ,public Singer{
protected:
    void Data()const;
    void Get();
public:
    SingingWaiter(){};
    SingingWaiter(const std::string &s,long n,int p,int v=other)
    :Worker(s,n),Singer(s,n,v),Waiter(s,n,p){};
    SingingWaiter(const Worker & wk,int p=0,int v=other)
            :Worker(wk),Waiter(wk,p),Singer(wk,v){};
    SingingWaiter(const Waiter & wt,int v=other)
    :Worker(wt),Waiter(wt),Singer(wt,v){};
    SingingWaiter(const Singer & s,int p=0)
    :Worker(s),Singer(s),Waiter(s,p){};
    ~SingingWaiter(){};
    void Set();
    void Show()const;

};
#endif //INC_14_3_WORKER_H
