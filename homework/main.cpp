#include <iostream>
#include <vector>
#include <string>

class Item
{
private:
    std::string Name;
    float VAT_tax_type;
    float Unit_net_price;
    float Amount_sold;

public:
    Item(std::string name = "unknown", float VAT = 0, float unit = 0, float amount = 0)
    {
        Name = name;
        VAT_tax_type = VAT;
        Unit_net_price = unit;
        Amount_sold = amount;
    }

    std::string name_fun (){return Name ;}
    float vat_fun (){return VAT_tax_type;}
    float net_fun (){return Unit_net_price;}
    float amount_fun (){return Amount_sold;}
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

    friend std::ostream& operator<<(std::ostream& stream, Invoice &something);
};

std::ostream& operator<<(std::ostream& stream, Invoice &something)
{
    float a = 0;
    float b = 0;

    stream << "------------------VAT invoice------------------" << std::endl
           << "===============================================" << std::endl
           << "seller: " << something.seller << " buyer: " << something.buyer << std::endl << std::endl;

    for(int i = 0; i < (int)something.items.size(); i++)
    {
        stream << "name: "<< something.items[i].name_fun()
               << " VAT: " << something.items[i].vat_fun()
               << " net: " << something.items[i].net_fun()
               << " amt: " << something.items[i].amount_fun() << std::endl;

        b = b + something.items[i].net_fun() * something.items[i].amount_fun();
        a = a + (something.items[i].net_fun() * something.items[i].amount_fun()) + (something.items[i].net_fun() * something.items[i].amount_fun()) * something.items[i].vat_fun()/100;
    }
    stream <<  std::endl << "Total without VAT: " << b << std::endl << "Total with VAT: " << a;

    return (stream);
}

int main()
{
    Invoice inv(7770003699, 1123456789);
    inv.add_item(Item("M3 screw", 23, 0.37, 100));
    inv.add_item(Item("2 mm drill", 8, 2.54, 2));
    std::cout << inv << std::endl;
}
