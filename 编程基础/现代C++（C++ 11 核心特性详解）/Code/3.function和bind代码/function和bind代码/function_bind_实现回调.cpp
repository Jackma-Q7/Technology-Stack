#include <iostream>
#include <functional>

typedef std::function<void(const std::string&)> OnMessage;
typedef std::function<void(int)> onConnect;
typedef std::function<void(int)> onDisConnect;

class Netlib
{
public:
    void Init(const OnMessage& Msg, const onConnect& Connect, const onDisConnect &Disconnect)
    {
        m_fOnMesage = Msg;
        m_fOnConnect = Connect;
        m_fOnDisConnect = Disconnect;
    }

    void Process()
    {
        if (m_fOnMesage)
        {
            m_fOnMesage("this is message");
        }

        if (m_fOnConnect)
        {
            m_fOnConnect(18);
        }

        if (m_fOnDisConnect)
        {
            m_fOnDisConnect(-1);
        }
    }
private:
    OnMessage m_fOnMesage;
    onConnect m_fOnConnect;
    onDisConnect m_fOnDisConnect;
};

void OMsg(const std::string& msg)
{
    std::cout << msg.c_str() << std::endl;
}

void OnConnect(int v)
{
    std::cout << v << std::endl;
}

void OnDisConnect(int v)
{
    std::cout << v << std::endl;
}

struct sConnect
{
    void operator()(int i)
    {
        std::cout << i << std::endl;
    }
};

void MyMessag(const std::string& name, const std::string& Msg)
{
    std::cout << name.c_str() << "," << Msg.c_str() << std::endl;
}

class CConnect
{
public:
    void DisConnect(int i)
    {
        std::cout << i << std::endl;
    }
};

int main()
{
    Netlib lib;
    CConnect disConnect;
    lib.Init(std::bind(MyMessag,"MyMessage",std::placeholders::_1), sConnect(), std::bind(&CConnect::DisConnect,&disConnect,std::placeholders::_1));
    lib.Process();
}

