#include <iostream>
#include <vector>
#include <string>



class Item
{
private:
    std::string Name;
    int VAT_tax_type;
    float Unit_net_price;
    float Amount_sold;

public:
    Item(std::string name = "unknown", int VAT = 0, float unit = 0, float amount = 0)
    {
        Name = name;
        VAT_tax_type = VAT;
        Unit_net_price = unit;
        Amount_sold = amount;
    }

    friend std::ostream& operator<<(std::ostream& stream,const Item &something);
};

class Invoice
{
private:
    int seller;
    int buyer;
    std::vector <Item> items;

public:
    Invoice(int sel, int buy/*std::vector <Item> item*/)
    {
        seller = sel;
        buyer = buy;
        /*items.emplace_back(item);*/
    }

    void add_item(std::vector <Item> item)
    {
        items.emplace_back(item);
    }
    friend std::ostream& operator<<(std::ostream& stream,const Invoice &something);

};

std::ostream& operator<<(std::ostream& stream,const Invoice &something)
{
    stream << "------------------VAT invoice------------------" << std::endl
           << "===============================================" << std::endl
           << "Seller: " << something.seller << "      " << something.buyer << std::endl << std::endl
           << "                  c.j. VAT   il.    net   total" << std::endl;
    return(stream);
}


int main()
{
    return(0);

}
