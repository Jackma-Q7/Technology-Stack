#include <iostream>
//网络库中提供的处理事件的接口类
class NetEvent
{
public:
    virtual void OnMessage(const std::string& strMsg) = 0;
    virtual void OnDisconnet(int i) = 0;
    virtual void Connect(int i) = 0;
};

//上层应用继承NetEvent实现各个接口
class MyEvent :public NetEvent
{
public:
    virtual void OnMessage(const std::string& strMsg)
    {
        ...
    }

    virtual void OnDisconnect(int i)
    {
        ...
    }

    virtual void Connect(int i)
    {
        ...
    }

};

int main()
{
    //网络库对象
    Netlib lib;
    //产生MyEvent对象
    MyEvent* pEvent = new MyEvent;

    lib.registerHandler(pEvent);
    lib.run();
}