#include<fstream>
#include<iostream>
#include<string>
using namespace std;

int main()
{
    fstream file;
    file.open("lab11_2.txt",ios::in|ios::out|ios::binary);
    string a;
    if(file)
    {
        int i = 1;
        while(!file.eof())//判断文件是否操作结束
        {
            file << "[" << i++ << "]";
            getline(file, a);
        }
    }
    file.close();
    return 0;
}