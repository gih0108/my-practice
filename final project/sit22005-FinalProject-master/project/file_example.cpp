#include <iostream>
#include <cstring>

// header file for file input/output
#include <fstream>

class StockItem
{
public:
    StockItem()
    {
        item_name = nullptr;
        item_quantity = -1;
        item_cost = -1;
    }
    
    StockItem(char* name, int quant, int cost)
    :item_quantity(quant), item_cost(cost)
    {
        item_name = new char[strlen(name)+1];
        strcpy(item_name, name);
        item_name[strlen(name)] = '\0';
    }
    
    virtual ~StockItem()
    {
        delete [] item_name;
    }

public:
    void ReadFromString(char* buff)
    {
        char* token = strtok(buff, ",");
        
        if(item_name == nullptr)
        {
            item_name = new char[strlen(token)+1];
            strcpy(item_name, token);
            item_name[strlen(token)] = '\0';
        }
        
        item_quantity = atoi(strtok(nullptr, ","));
        
        item_cost = atoi(strtok(nullptr, ","));
 
    }
    
    void WriteToFile(std::ofstream& fout)
    {
        fout << item_name << ","
             << item_quantity << ","
             << item_cost << std::endl;
    }
    
public:
    char* get_name(){ return item_name; }
    int   get_quantity(){ return item_quantity; }
    int   get_cost(){ return item_cost; }
    
    void set_quantity(int quan) { item_quantity = quan; }
    void set_cost(int cost) { item_cost = cost; }

    void print()
    {
        std::cout << "item name: " << item_name << std::endl;
        std::cout << "item quantity: " << item_quantity << std::endl;
        std::cout << "item cost: " << item_cost << std::endl;
    }
    
private:
    char* item_name;
    int item_quantity;
    int item_cost;
};

int main() {
    
    // Read from stock.txt file
    {
        std::ifstream fin;
        fin.open("stock.txt");
    
        char buff[1000];    
        while(!fin.eof())
        {
            fin.getline(buff, 1000);
            if(buff[0] != 0)
            {
                StockItem si;
                si.ReadFromString(buff);
                si.print();
                std::cout << std::endl;    
            }
        }
        
        fin.close();
    }
    
    // Write from stock.txt file
    {
        std::ofstream fout;
        fout.open("stock2.txt");
        
        std::ifstream fin;
        fin.open("stock.txt");
    
        char buff[1000];    
        while(!fin.eof())
        {
            fin.getline(buff, 1000);
            if(buff[0] != 0)
            {
                StockItem si;
                si.ReadFromString(buff);
                si.set_quantity(si.get_quantity() + 10);
                si.WriteToFile(fout);
            }
        }
        
        fin.close();
        fout.close();
    }
}
