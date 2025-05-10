#include <bits/stdc++.h>
using namespace std;
class Product
{
private:
    string name;
    double price;

public:
    Product()
    {
        name = ' ';
        price = 0;
    }
    Product(string name, double price)
    {
       
        this->name =name;
        this->price = price;
    }
    Product(Product &p)
    {
        name=p.name;
        
        price = p.price;
    }
    void setProduct(char *name, double price)
    {
        
        this->name= name;
        this->price = price;
    }
    void display()
    {
        cout << "Product: " << name << " - Price: $" << price << endl;
    }
    double getPrice(){
        return price;
    }
    string getName(){
        return name;
    }
    // Product &operator=(const Product &p)
    // {
    //     if (this != &p)
    //     {
    //         delete[] name;
    //         name = new char[strlen(p.name) + 1];
    //         strcpy(name, p.name);
    //         price = p.price;
    //     }
    //     return *this;
    // }
    
};
class OnlineStore
{
private:
    Product *product;
    int size;

public:
    OnlineStore()
    {
        product = new Product[100];
        size = 0;
    }
    void addProduct(Product &P)
    {
        product[size] = P;
        size++;
    }
    void displayProducts()
    {
        for (int i = 0; i < size; i++)
        {
            product[i].display();
        }
    }
    ~OnlineStore(){
        delete []product;
    }
};
class ShoppingCart
{
private:
    Product *product;
    int size;

public:
    ShoppingCart()
    {
        product = new Product[100];
        size = 0;
    }
    void addProduct(Product &P)
    {
        product[size] = P;
        size++;
    }
    void displayCart()
    {
        double sum=0;

        for (int i = 0; i < size; i++)
        {
            product[i].display();
            sum=sum+product[i].getPrice();
        }
        cout<<"total cost"<<sum<<endl;
    }
    void removeProduct(char * s){
        int idx=-1;
        for(int i=0;i<size;i++){
            if(strcmp(product[i].getName(), s) == 0){
                idx=i;
                break;
            }
        }
        for(int i=idx;i<size-1;i++){
            product[i]=product[i+1];
        }
        size--;
    }

    ~ShoppingCart(){
        delete []product;
    }
};

int main()
{
    OnlineStore store;
    // Add products to the online store
    Product product1("Laptop", 999.99);
    Product product2("Smartphone", 699.99);
    Product product3("Headphones", 99.99);
    store.addProduct(product1);
    store.addProduct(product2);
    store.addProduct(product3);
    // Display available products
    store.displayProducts();
    // Display available products
store.displayProducts();
// Create a new shopping cart
ShoppingCart cart;
// Add products to the shopping cart
cart.addProduct(product1);
cart.addProduct(product2);
// Display the shopping cart
cart.displayCart();
// Add another product to the cart
cart.addProduct(product3);
// Display the updated shopping cart
cart.displayCart();
// Remove a product from the cart
cart.removeProduct("Laptop");
// Display the updated shopping cart
cart.displayCart();
return 0;
}