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
    sales.print_stock();
    sales.Store_stock();
}