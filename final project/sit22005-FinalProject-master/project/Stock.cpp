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
    sales.Load_stock();
    //sales.print_stock();
    //sales.Sell();
    //sales.take_name();
    
    //std::cout<<  sales.take_quant(sales.take_name())<<std::endl;
    sales.Sell();
    sales.Store_stock();
    
}