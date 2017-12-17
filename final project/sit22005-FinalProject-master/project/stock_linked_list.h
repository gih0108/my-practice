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
    private:
        LinkedList stock_list;
        LinkedList sales_hist;
    
    
    public:
        Sales(){std::cout<<"sales now11"<<std::endl;}
        
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

            for(Node* cur = stock_list.get_head(); cur!= nullptr; cur = cur->get_next())
            {
                StockItem* fish = static_cast<StockItem*>(cur);
                fish->WriteToFile(fout);
            }
            fout.close();
        }
        
        
        char* take_name(){
            
            char input[20];
            char ask;
            char* name;
            
            
            while(1){
                
                std::cout<< "What you want to buy? >>> ";
                
                std::cin.getline(input,20);
                //std::cout<< input;
                name = stock_list.search_name(input);
                std::cout << std::endl;
                if(name != NULL){
                    //std::cout<< input;
                    break;
                }else{
                std::cout<< "Sorry, we do not have a stock for " << input << "."<<std::endl;
                std::cout<< "Do you want to buy other item? (y/n) >>> ";
                std::cin >> ask;
                if(ask == 'n'){
                    name == NULL;
                    break;
                }
                std::cin.get();
                }
            }
            return name;
        }
        
        int take_quant(const char* val){
                int qty;
                while(1){
                std::cout<< "How many?>>>";
                std::cin >> qty;
                Node* cur = stock_list.find_node(val);
                StockItem* inode = static_cast<StockItem*>(cur);
                if(qty>stock_list.search_quant(val)){
                     std::cout<< "Sorry we have " << stock_list.search_quant(val) << " items."<<std::endl;
                     std::cout<< "Would you buy? (y/n)>>>";
                     char ans;
                     std::cin >> ans;
                     if(ans == 'y'){
                         qty = stock_list.search_quant(val);
                         break;}
                else{
                    qty = 0;
                    }
                }else{
                    break;
                }
                
               
            }
          
             return qty;
        }
        
                
        void Sell(){
            char* fruit;
            fruit = take_name();
            if (fruit != NULL){
                int _quant = take_quant(fruit);
                if(_quant!=0){
                Node* cur = stock_list.find_node(fruit);
                StockItem* fish = static_cast<StockItem*>(cur);
                fish->set_quantity(fish->get_quantity() - _quant);
                
                std::cout << "item = " << fruit << "; price = " << fish->get_cost() << "; quantity = "<<_quant<< "; amount = "<< fish->get_cost() * _quant <<std::endl;
                
                sales_hist.InsertToFront(fruit, _quant, fish->get_cost());
                }
                
            } 
        }   
        
        void print_sales(){
            printf("\n                       %s \n\n","SALES REPORT");
            std::cout << "Name              Price           Quantitiy          Amount "<<std::endl;
            
            for(Node* cur = sales_hist.get_head(); cur!= nullptr; cur = cur->get_next())
            {
                StockItem* node = static_cast<StockItem*>(cur);
                printf("%-10s         %5d              %5d          %5d\n", node->get_name(), node->get_cost(),node->get_quantity(),node->get_cost() * node->get_quantity());
                
            }
            
            
        }
        
        void print_stock(){
            printf("\n                      %s \n\n","STOCK REPORT");
            std::cout << "Name              Price           Quantitiy          Amount "<<std::endl;
            
            for(Node* cur = stock_list.get_head(); cur!= nullptr; cur = cur->get_next())
            {
                StockItem* node = static_cast<StockItem*>(cur);
                printf("%-10s         %5d              %5d          %5d\n", node->get_name(), node->get_cost(),node->get_quantity(),node->get_cost() * node->get_quantity());
                
            }
            
            
        }
        
        void show_manu(){
            
            std::cout<<std::endl;
            std::cout<< "What would you like to do?" <<std::endl;
            std::cout<<"   S: Sell an item" <<std::endl;
            std::cout<<"   P: Print stock" <<std::endl;
            std::cout<<"   R: Report sales" <<std::endl;
            std::cout<<"   E: Exit" <<std::endl;
            char input;
            std::cout <<  "Enter your choice (S, P, R, or E)>>>";
            std::cin>>input;
            
            return input;
            
        }
        
    
    
    
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
