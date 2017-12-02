#include <iostream>

#include <fstream>

#include <cstring>

#include <sstream>

#include <stdlib.h>



#include <vector>



// Project San

class San

{

public:

    San(int num, int age, const char* name)

    :m_num(num), m_age(age)

    {

        int len = strlen(name);

        m_name = new char[len+1];

        strcpy(m_name, name);

    }

    ~San()

    {

        delete [] m_name;

    }

    

public:

    int get_number() { return m_num; }

    int get_age() { return m_age; }

    char* get_name() { return m_name; }

    

private:

    int m_num;

    int m_age;

    char* m_name;

};



void print(std::ostream& os, San& san)

{

    os << san.get_number() << std::endl;

    os << san.get_age() << std::endl;

    os << san.get_name() << std::endl;

}



int main(int argc, char** argv)

{

    /*

    std::vector<int> int_dyn_array;

    int idx = 10;

    int_dyn_array.push_back(idx++);

    int_dyn_array.push_back(idx++);

    int_dyn_array.push_back(idx++);

    int_dyn_array.push_back(idx++);

    int_dyn_array.push_back(idx++);

    

    for(std::vector<int>::iterator iter = int_dyn_array.begin();

        iter != int_dyn_array.end(); ++iter)

    {

        std::cout << "Contents:" << *iter << std::endl;

    }

    

    for(int i = 0; i < int_dyn_array.size(); i++)

    {

        std::cout << "Contents:" << int_dyn_array[i] << std::endl;

    }

    

    San var_san = San(10, 20, "San Jung");

 */

 

 

 

    std::vector<San*> san_dyn_array = std::vector<San*>();

    san_dyn_array.push_back(new San(10, 20, "cbchoi"));

    san_dyn_array.push_back(new San(11, 22, "cbchoi"));

    san_dyn_array.push_back(new San(12, 24, "cbchoi"));

    san_dyn_array.push_back(new San(13, 26, "cbchoi"));

    

    for(std::vector<San*>::iterator iter = san_dyn_array.begin();

        iter != san_dyn_array.end(); ++iter)

    {

        std::cout << "Contents:" << std::endl;

        print(std::cout, **iter);

    }

    

    std::ofstream fout;//파일 쓰기

    fout.open("output2.prac");

    fout << san_dyn_array.size() << std::endl;

    for(std::vector<San*>::iterator iter = san_dyn_array.begin();

        iter != san_dyn_array.end(); ++iter)

    {

        print(fout, **iter); // *iter = San*

    }

    fout.close();

    

    std::ifstream fin;//파일 읽기

    fin.open("output2.prac");

    

    std::cout << "_____________________" << std::endl;

    char buf[1000]; //글자 넣을 array 할당 해주고,

    //while(!fin.eof())

    fin.getline(buf, 1000); // num //첫번째 줄 넣으세여

    int count = atoi(buf); //buf에 들어가 있는걸 count로 숫자로 입력 해주세여 

    

    for(int i = 0; i < count ; i++)

    {

        fin.getline(buf, 1000); // num

        int number = atoi(buf);

        fin.getline(buf, 1000); // age

        int age = atoi(buf);

        fin.getline(buf, 1000); // name

        

        San my_san = San(number, age, buf); //san class로 만들어주세여

        print(std::cout, my_san); // 프린트 해주세여

    }

    

    /*

    std::cout << std::endl;

    std::stringstream sstream;

    print(sstream, var_san);

    const char* c_var = sstream.str().c_str();

    //std::cout << c_var << std::endl;

    */

    return 0;

}