"""store tool to object-orinted"""
#load the text file and convrt to list

class Load_stock(object):
    def __init__(self, filename):
        file = open(filename,"r")
        self.stock_list = []
        for line in file:
            line = line.strip()
            item = line.split(",")
            item[1] = int(item[1])
            item[2] = int(item[2])
            self.stock_list.append(item)
        file.close()
        self.stock_list.sort()
    def returning(self):
        return self.stock_list

#store th elements into txt file
class Store_stock(object):
    def __init__(self, stock_list):
        file = open("stock.txt", "w")
        for line in stock_list:
            line[1] = str(line[1])
            line[2] = str(line[2])
            self.item = ",".join(line) + "\n"
            file.write(self.item)
        file.close()
        
#selling : ask for what item
class Take_name(object):
    def __init__(self,stock_list):
        while True:
            self.name = raw_input("What you want to buy? >>>")
            for item in stock_list:
                if item[0] == self.name:
                    break
            if item[0] == self.name:
                break
            else:
                print "Sorry, we do not have a stock for " + self.name + "."
                self.res = raw_input("Do you want to buy other item? (y/n)>>>")
                if self.res == "n":
                    item = []
                    break
        self.item = item
    def returning(self):
        return self.item

#selling : ask for how many item
class Take_quant(object):
    def __init__(self):
        try:
            self.qty = int(raw_input("How many?>>>"))
        except:
            print "Type in a number. >>>"
    def tool(self,item):        
        while True:
                if self.qty <= item[1]:
                    return self.qty
                else:
                    print "Sorry we have %5d items." %item[1]
                    self.res = raw_input("Would you buy? (y/n)>>>")
                    if self.res == "y":
                        self.qty = item[1]
                    else:
                        self.qty = 0
                    return self.qty

#selling : report decrease amount and show the result
class Sell(object):
    def __init__(self, stock_list, sales_hist):
        self.item = Take_name(stock_list).returning()
        if self.item != []:
            self.quant = Take_quant().tool(self.item)
        if self.item == [] or self.quant == 0 :
            return
        self.item[1] -= self.quant 
        
        print "item = ", self.item[0], "; price = ", self.item[2], "; quanity = ",\
              self.quant, "; amount = ", self.item[2] * self.quant
        sales_hist.append((self.item[0], self.item[2], self.quant))
            

#show what item remain in stock
class Print_stock(object):
    def __init__(self,stock_list):
        print "\n", " " * 20 + "STOCK REPORT"
        print "Name             price      quatity        amount"
        for item in stock_list:
            print "%-10s      %5d         %5d        %6d" % (item[0], item[2], item[1], item[1] * item[2])
        
#show what item sold
class Print_sales(object):
    def __init__(self, sales_hist):
        print " " * 20 + "SALES REPORT"
        print "Name       price      quatity        amount"
        for item in sales_hist:
            print "%-10s  %5d         %5d        %6d" % (item[0], item[1], item[2], item[1] * item[2])

#main menu
def show_manu():
    print "\n", "What would you like to do?"
    print "   S: Sell an item"
    print "   P: Print stock"
    print "   R: Report sales"
    print "   E: Exit"
    return raw_input("Enter your choice (S, P, R, or E)>>>")

#if user input wrong value
def input_error(s):
    print s + "?" + "I beg your pardon."
#main
def main():
    
    stock_list = Load_stock("stock.txt").returning()
    sales_hist = []
    while True:
        s = show_manu()
        if s =="E" :
            break
        elif s == "S":
            Sell( stock_list, sales_hist)
        elif s == "P":
            Print_stock(stock_list)
        elif s ==  "R":
            Print_sales(sales_hist)
        else:
            input_error(s)
    Store_stock(stock_list)
    print stock_list
    
main()
    
