#include <string>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <typeinfo>       // operator typeid
#include "stock_linked_list.h"

int main(){
    Sales sales;
    while(1){
        string ch = sales.show_manu();
        if(ch == "E"){
            break;
        }
        else if(ch == "S"){
            sales.Sell();
        }
        else if(ch == "P"){
            sales.print_stock();
        }
        else if(ch == "R"){
            sales.print_sales();
        }
        else{
            std::cout<<ch<<"?  I beg your pardon"<<std::endl;
        }
    }
}