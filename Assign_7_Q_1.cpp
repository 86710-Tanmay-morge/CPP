#include <iostream>
#include <string>
using namespace std;
class Product
{
public:
    int id;
    string title;
    virtual void accept()
    {
        cout << "Enter Product ID: ";
        cin >> id;
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
    }
    virtual void display() const
    {
        cout << "ID: " << id << endl;
        cout << "Title: " << title << endl;
    }
    virtual ~Product() {}
};

class Book : public Product
{
    string author;
    double price;

public:
    void accept() override
    {
        Product::accept();
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Price: ";
        cin >> price;
    }
    void display() const override
    {
        Product::display();
        cout << "Author: " << author << endl;
        cout << "Price: " << price << endl;
    }
    double getFinalPrice() const
    {
        return price * 0.90;
    }
};
class Tape : public Product
{
    string artist;
    double price;

public:
    void accept() override
    {
        Product::accept();
        cout << "Enter Artist: ";
        getline(cin, artist);
        cout << "Enter Price: ";
        cin >> price;
    }
    void display() const override
    {
        Product::display();
        cout << "Artist: " << artist << endl;
        cout << "Price: " << price << endl;
    }
    double getFinalPrice() const
    {
        return price * 0.95;
    }
};

void menu()
{
    Product *arr[3];
    int choice;
    double total = 0, discountedTotal = 0;

    for (int i = 0; i < 3; ++i)
    {
        cout << "Enter product type (1 for Book, 2 for Tape): ";
        cin >> choice;

        if (choice == 1)
        {
            arr[i] = new Book();
        }
        else if (choice == 2)
        {
            arr[i] = new Tape();
        }
        else
        {
            cout << "Invalid choice. Try again." << endl;
            --i;
            continue;
        }

        arr[i]->accept();
    }

    cout << "\nProduct Details:\n";
    for (int i = 0; i < 3; ++i)
    {
        arr[i]->display();
        if (Book *b = dynamic_cast<Book *>(arr[i]))
        {
            total += b->getFinalPrice();
            discountedTotal += b->getFinalPrice();
        }
        else if (Tape *t = dynamic_cast<Tape *>(arr[i]))
        {
            total += t->getFinalPrice();
            discountedTotal += t->getFinalPrice();
        }
        cout << endl;
    }

    cout << "Total Price after Discounts: " << discountedTotal << endl;

    for (int i = 0; i < 3; ++i)
    {
        delete arr[i];
    }
}

int main()
{
    menu();
    return 0;
}
