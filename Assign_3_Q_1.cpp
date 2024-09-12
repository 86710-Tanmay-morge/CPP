#include <iostream>
using namespace std;
int volume()
{
    int l = 10;
    int b = 20;
    int h = 25;
    int volume = l * b * h;
    return volume;
}
int volume(int x)
{
    int volume = x * x * x;
    return volume;
}
int volume(int l, int b, int h)
{
    int volume = l * b * h;
    return volume;
}
int menu()
{
    int choice;
    cout << "Please enter a choice" << endl;
    cout << "1.Calculate Volume with default values" << endl;
    cout << "2.Calculate Volume with length,breadth and height with same value" << endl;
    cout << "3.Calculate Volume with different length,breadth and height values." << endl;
    cout << "4.exit!!!" << endl;
    cin >> choice;
    return choice;
}
int main()
{
    int choice;
    int vol;
    do
    {
        choice = menu();
        switch (choice)
        {
        case 1:
            vol = volume();
            cout << "volume is" << vol << endl;
            break;
        case 2:
            int x;
            cout << "enter the same values" << endl;
            cin >> x;
            vol = volume(x);
            cout << "volume is" << vol << endl;
            break;
        case 3:
            int l, b, h;
            cout << "enter the values of l b h" << endl;
            cin >> l >> b >> h;
            vol = volume(l, b, h);
            cout << "volume is" << vol << endl;
            break;

        default:
            break;
        }

    } while (choice != 4);

    return 0;
}