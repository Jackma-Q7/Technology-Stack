#include <iostream>
#include <memory>
#include <fstream>
class CFileDeleter
{
public:
    CFileDeleter(const std::string& strFile) :m_strFileName(strFile)
    {

    }

    void operator()(std::ofstream* fp)
    {
        fp->close();
        std::remove(m_strFileName.c_str());
    }

private:
    std::string m_strFileName;
};
int main()
{
    std::shared_ptr<int> p1(new int[10]);
    std::shared_ptr<int> p2(new int[10], [](int* p) {
        std::cout << "delete p" << std::endl;
        delete[] p;
    });

    p2.get()[0];

    std::unique_ptr<int[]> p3(new int[10]);

    p3[0];
    //std::shared_ptr<std::ofstream> fp(new std::ofstream("test.txt"), CFileDeleter("test.txt"));

    //std::unique_ptr<std::ofstream, CFileDeleter> ffp(new std::ofstream("test.txt"), CFileDeleter("test.txt"));



    std::system("pause");
}