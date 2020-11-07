
#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <bitset>
#include <sstream>
#include <list>
#include "Dictionary.cpp"


int test();

class product
{
private:
    std::string name;
    std::string barcode;
    double price;
    
public:
    product()
    {
        
        barcode = " ";
        name = " ";
        price = 0.0;
        
    }
    
    product(std::string b, double p)
    {
        barcode = b;
        price = p;
    }
    void setName(std::string n){name = n;}
    std::string getBarcode(){return barcode;}
    double getPrice(){return price;}
    std::string getName(){return name;}
    
    
};




template <typename T>
class Node
{
public:
    T data;
    Node<T>* previous;
    Node<T> * next;
    Node<T>() { previous = NULL; next = NULL; data = 0; }
    Node<T>(T t) { previous = NULL; next = NULL; data = t; }
};


class hashElement
{
private:
    int key = 0;
    product theProduct;
public:
    hashElement(int k = 0)
    {
        key = k;
        
    }
    
    void setKeyValue(int k, product p)
    {
        key = k;
        theProduct = p;
    }
    
    int getKey(){return key;}
    
    product getProduct(){return theProduct;}
    
    
    
    
};

int getHash(std::string key, long cap)
{
    long max = cap;
    int sum = key[0] - 'A' + 1;
    for(int c = 0; c<key.length(); c++)
    {
        sum += (key[c]-'A' + 1);
    }
    
    return abs(sum % max);
    
//    char stringHash = key[0];
//
//    for(int i = 0; i< key.length(); i++)
//    stringHash = (stringHash * 7) + key[i];
//    return stringHash % cap;

    
    
    
}
class hashTable
{
private:
    long cap;
public:
    std::vector<std::list<hashElement>> hTable;
    
    hashTable(long SIZE)
    {
        hTable.resize(SIZE * 1.25f);
        cap = hTable.size();
    }
    
    
    product get(std::string key)
    {
        int hash = getHash(key,cap);
    
        for(std::list<hashElement>::iterator it = hTable[hash].begin(); it != hTable[hash].end(); ++it)
        {
            if(it->getProduct().getName() == key)
            {
                return it->getProduct();
            }
            
        }
        
        
        product nothing;
        return nothing;
        
       // return hTable[hash].getProduct();
    }
    
    void set(product p)
    {
        
        std::string name = p.getName();
        hashElement element;
        int hash = getHash(name,cap);
        std::cout<<name<<std::endl;
        
        element.setKeyValue(hash, p);
        
        
        hTable[hash].push_back(element);
        
        
    }
    
};


using namespace std;
std::string hexToBinary(std::string barcode)
{
    std::string code;
    
    for(int i = 0; i <barcode.size(); i++){
    if (barcode[i] == 'A')
            {
                bitset<4> bit(10);
                code += bit.to_string();
                cout<<bit;
            }

            else if (barcode[i] == 'B')
            {
                bitset<4> bit(11);
                code += bit.to_string();
                cout<<bit;
            }

            else if (barcode[i] == 'C')
            {
                bitset<4> bit(12);
                code += bit.to_string();
                cout<<bit;
            }

            else if (barcode[i] == 'D')
            {
                bitset<4> bit(13);
                code += bit.to_string();
                cout<<bit;
            }

            else if (barcode[i] == 'E')
            {
                bitset<4> bit(14);
                code += bit.to_string();
                cout<<bit;
            }

            else if (barcode[i] == 'F')
            {
                bitset<4> bit(15);
                code += bit.to_string();
                cout<<bit;
            }
            else
            {
                bitset<4> bit(barcode[i]);
                code += bit.to_string();
                cout<<bit;
            }
        
    }
    
    return code;
    
}

class Carts
{
private:
    std::string cartNumber;
    std::vector<std::string> barcodes; //hex value
public:
    Carts()
    {
        cartNumber = "";
       
    }
    
    Carts(std::string cN)
    {
        cartNumber = cN;
        
        
    }
    void setCartNumber(std::string s){cartNumber = s;}
    void setBarcode(std::string b)
    {
        barcodes.push_back(b);
    }
    
    
    std::string  getCartNumber(){return cartNumber;}
    
    void printBarcodes()
    {
        for(auto i : barcodes)
            std::cout<<i<<std::endl;
        
        
    }
    
    
    
};


void processCarts()
{
    
    std::ifstream cartsFile;
    std::vector<Carts> carts;
    
    
    std::regex e;
    std::smatch m;
    
    std::string cartNumber;
    std::string barCode;
    cartsFile.open("Carts.csv");
    
    if(cartsFile.fail())
    {
        std::cerr<<"Cannot Open Carts File! "<<std::endl;
        exit(1);
    }
    
    Carts cart;
    
    
    int once = 1;
    while (!cartsFile.eof()) {
    
        
        
        
        
        //do somthing
    }
//    int once = 1 ;
//    while(!cartsFile.eof())
//    {
//        if(once == 1){
//        std::getline(cartsFile, cartNumber);
//            once++;
//        }
//
//        cart.setCartNumber(cartNumber);
//
//        while(true){
//        std::getline(cartsFile, barCode, ',');
//            if(barCode.size()>14)
//            {
//                barCode = barCode.substr(0,12);
//
//                break;
//            }
//            cart.setBarcode(barCode);
//            barCode = "";
//        }
//        carts.push_back(cart);
//
//
//    }
//
    for(auto i : carts)
    {
        std::cout<<i.getCartNumber()<<std::endl;
        i.printBarcodes();
    }
    
    
    
    
}

int main() {
    

    //processCarts();
    
    Dictionary myDict;
    
   
    std::ifstream productPriceFile;
    std::vector<Node<product>*> productNodes;
    
    std::smatch m;
    std::regex e("\\d+.+\\d");
    
    
    productPriceFile.open("ProductPrice.xml");
    if(productPriceFile.fail()){
        std::cerr<<"Cannot Open File! "<<std::endl;
        exit(1);
        
    }
    
    
    std::string line;
    std::string data;
    std::string barcode;
    std::string price;
    int productNumber = 1;
    int count = 1;
    
    while (!productPriceFile.eof()) {
        
        std::getline(productPriceFile,line);
        
        while(std::regex_search(line,m,e))
        {
            for(auto x : m){
                data = x;
            }
            productNumber++;
            line = m.suffix().str();
            
            
        }
     
        if(count == 2)
            barcode = data;
        if(count == 3){
            price = data;
            product myP(barcode,std::stod(price));
            Node<product>* newProduct = new Node<product>(myP);
            productNodes.push_back(newProduct);
        }
        if(count == 4)
            count = 0;
            
        count++;
  

    }
    productPriceFile.close();
    
    for(auto x : productNodes)
    {
        //setting nodes products names to binary
        x->data.setName(myDict.binaryToName(x->data.getBarcode()));
        std::cout<<x->data.getName()<<"\n";
        
        std::cout<<'$'<<x->data.getPrice();
        
        std::cout<<"\n================\n";
        //std::cout<<x->data.getBarcode()<<"\n"<<x->data.getPrice()<<std::endl;
    }
    
    
    hashTable myTable(productNodes.size());
    
    for(int i = 0; i < productNodes.size(); i++)
    {
        myTable.set(productNodes[i]->data);
    }
    
    product theP;
    theP = myTable.get("LEMON");
    
    std::cout<<theP.getName()<<" "<<theP.getPrice()<<std::endl;
    
   
    return 0;
}
