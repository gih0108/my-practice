#include <iostream>
#include <cstring>

// header file for file input/output
#include <fstream>
#include "linkedlist.h"
class StockItem : public Node
{
public:
    StockItem() : Node(nullptr,STRING_NODE)
    {
        item_name = nullptr;
        item_quantity = -1;
        item_cost = -1;
        
    }
    
    StockItem(char* name, int quant, int cost, Node* next)
    :Node(next, STRING_NODE),item_quantity(quant), item_cost(cost)
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

class LinkedList
{
    protected:
        Node* pHead;
    
    public:
        LinkedList();
        void InsertToFront(char* val, int quan, int cost);
        Node* get_head(){ return pHead; }
        Node* find_prev_node(Node* next);
        //void RemoveNode(const char* val);
        Node* find_node(const char* val);
        
        char* search_name(const char* val);
        int search_quant(const char* val);
        int search_cost(const char* val);
        
        virtual void print(std::ostream& os){
            for(Node* cur = pHead; cur!= nullptr; cur = cur->get_next())
            {
                StockItem* node = static_cast<StockItem*>(cur);
                os<<node->get_name() << " ";
            }
        }
};

class Sales
{
    public:
        Sales(){std::cout<<"sales now"<<std::endl;}
        
        void Load_stock(){
            char buf[100];
            char buf2[100];
            char buf3[100];
            std::ifstream fin;
            fin.open("stock.txt");
            
	        if (fin.is_open()) {
		        while (!fin.eof()) {
					fin.getline(buf, 100, ',');
					fin.getline(buf2, 100, ',');
					fin.getline(buf3, 100);
			        
			        stock_list.InsertToFront(buf, atoi(buf2), atoi(buf3));
			        
	            	}
        	}else {
	        	std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	       }

       }
            
        void Store_stock(){
            std::ofstream fout;
            fout.open("stock2.txt");
            
           // Node* cur = stock_list.get_head();
            //StockItem* fish = static_cast<StockItem*>(cur);
            for(Node* cur = stock_list.get_head(); cur!= nullptr; cur = cur->get_next())
            {
                StockItem* fish = static_cast<StockItem*>(cur->get_next());
                fish->WriteToFile(fout);
            }
            fout.close();
        }
        
        void print_sales();
        void print_stock(){
            stock_list.print(std::cout);
        }
        void Sell();
        void show_manu();
        
    
    private:
        LinkedList stock_list;
        LinkedList sales_hist;
    
    
};


    
LinkedList::LinkedList()
:pHead(nullptr)
{
    
}

void LinkedList::InsertToFront(char* val,int quan, int cost)
{
    StockItem* inode = new StockItem(val,quan,cost,pHead);
    pHead = inode;
    
}

Node* LinkedList::find_node(const char* val)
{
    Node* cur = pHead;
    StockItem* fish = static_cast<StockItem*>(cur);
        
        while(fish != NULL)
        {   
           
            if(!strcmp(val,fish->get_name()))
                break;
            else{
                cur = cur->get_next();
                fish = static_cast<StockItem*>(cur);
            }
        }
        return cur;
}

Node* LinkedList::find_prev_node(Node* next)
{
    Node* cur = pHead;
    if(next == cur)
    {
        return nullptr;
    }
    
    while(cur->get_next() != next && cur != nullptr)
    {
        cur = cur->get_next();
    }
    
    return cur;
}

char* LinkedList::search_name(const char* val)
{
    Node* cur = find_node(val);
    if(cur==NULL){
           
        return NULL;
            }
        else{
            StockItem* fish = static_cast<StockItem*>(cur);
            return fish->get_name();
        }
    }


int LinkedList::search_quant(const char* val)
{
    Node* cur = find_node(val);
    if(cur==NULL){
           
        return NULL;
            }
        else{
            StockItem* fish = static_cast<StockItem*>(cur);
            return fish->get_quantity();
        }
    }


int LinkedList::search_cost(const char* val)
{
    Node* cur = find_node(val);
    if(cur==NULL){
           
        return NULL;
            }
        else{
            StockItem* fish = static_cast<StockItem*>(cur);
            return fish->get_cost();
        }
    }
