#ifndef INC_14_3_QUEUETP_H
#define INC_14_3_QUEUETP_H

template<class T>
class QueueTP {
private:
    const int size=10;
    T * data;
    int top;
public:
    QueueTP(){data=new T[size];top=0;};
    QueueTP(int s){data=new T[2*s];top=0;};
    ~QueueTP(){delete[] data;}
    bool isEmpty(){return top==0;}
    bool isFull(){return top==size;};
    bool Push(T item);
    bool Pop();
    T& front()const;
    T& rear() const;
};
//有些编译器不支持分离实现
template <class T>
bool QueueTP<T>::Pop() {
    if(isEmpty())return false;
    --top;                      //data[top-1] is top data
    return true;
}
template<class T>
bool QueueTP<T>::Push(T item) {
    if(isFull())return false;
    for(int i=top;i>0;--i){
        data[i]=data[i-1];
    }
    data[0]=item;
    ++top;
    return true;
}
template<class T>
T& QueueTP<T>::front() const {
    return data[top-1];
}
template<class T>
T& QueueTP<T>::rear() const {
    return data[0];
}

#endif //INC_14_3_QUEUETP_H
