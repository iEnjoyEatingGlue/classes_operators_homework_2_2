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

    std::string dumb_af_0 (){return Name ;}
    int dumb_af_1 (Item abc){return abc.VAT_tax_type;}
    float dumb_af_2 (Item abc){return abc.Unit_net_price;}
    float dumb_af_3 (Item abc){return abc.Amount_sold;}

};

class Invoice
{
private:
    unsigned long long int seller;
    unsigned long long int buyer;
    std::vector <Item> items;

public:
    Invoice(unsigned long long int sel, unsigned long long int buy)
    {
        seller = sel;
        buyer = buy;
    }

    void add_item(Item item)
    {
        items.emplace_back(item);
    }

//    std::string just_dumb_0(Item abc)
//    {

//    }

    friend std::ostream& operator<<(std::ostream& stream, Invoice &something);
};

std::ostream& operator<<(std::ostream& stream, Invoice &something)
{
    stream << "------------------VAT invoice------------------" << std::endl
           << "===============================================" << std::endl
           << "Seller: " << something.seller << "      " << something.buyer << std::endl << std::endl
           << something.items[0].dumb_af_0();



    return (stream);
}

int main()
{
    Invoice inv(777, 999);
    inv.add_item(Item("M3 screw", 23, 0.37, 100));
    inv.add_item(Item("2 mm drill", 8, 2.54, 2));
    std::cout << inv << std::endl;
}
