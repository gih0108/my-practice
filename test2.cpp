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