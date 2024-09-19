#include <iostream>
#include <typeinfo>
using namespace std;

enum Eaccount
{
    SAVING = 1,
    CURRENT,
    DMAT

};

class Account
{
    int accno;
    Eaccount Type;
    double balance;
    static int generate_Accno;

public:
    Account()
    {
    }

    Account(int accno, Eaccount Type, double balance) : accno(++generate_Accno)
    {
        this->balance = balance;
    }

    void accept()
    {
        int input;

        cout << "1) SAVINGS \n";
        cout << "2) CURRENT \n";
        cout << "3) DMAT \n";
        cout << "Select type of account\n";
        cin >> input;

        switch (input)
        {
        case 1:
            Type = Eaccount(input);
            break;

        case 2:
            Type = Eaccount(input);
            break;
        case 3:
            Type = Eaccount(input);
            break;
        default:
            cout << "Invalid account type \n";
        }

        cout << "Enter balance of account : \n";
        cin >> balance;

        accno = generate_Accno++;
    }

    void display()
    {
        cout << "Details of account : \n";
        cout << "accno : " << accno << "\n";
        cout << "type: ";
        if (Type == 1)
        {
            cout << "SAVINGS\n";
        }
        else if (Type == 2)
        {
            cout << "CURRENT\n";
        }
        else
        {
            cout << "DMAT\n";
        }
        cout << "balance : " << balance << "\n";
    }

    int getaccno()
    {
        return this->accno;
    }

    void deposit(double amount)
    {
        balance = balance + amount;
    }

    void withdraw(double amount)
    {

        balance = balance - amount;
    }
};

int Account::generate_Accno = 1000;

class inSufficientFundsException : exception
{
    int accno;
    double currentBalance;
    double withdrawAmount;

public:
    inSufficientFundsException(int accno, double currentBalance, double withdrawamount) : accno(accno), currentBalance(currentBalance), withdrawAmount(withdrawAmount)
    {
    }

    void display()
    {

        cout << "Error in accno : " << accno << "\n";
        cout << "Current operation : " << currentBalance << " attempted amount : " << withdrawAmount << "\n";
        cout << "Transaction failed due to insufficient amount \n";
    }
};

enum Emenu
{
    EXIT,
    ADD_ACCOUNT,
    DEPOSIT_AMOUNT,
    WITHDRAW_AMOUNT,
    DISPLAY
};

int menu()
{
    int choice;

    cout << "************MENU*************\n";
    cout << "0) EXIT \n";
    cout << "1) ADD_ACCOUNT \n";
    cout << "2) DEPOSIT_AMOUNT \n";
    cout << "3) WITHDRAW_AMOUNT \n";
    cout << "4) DISPLAY \n";

    cout << "Enter your choice : \n";
    cin >> choice;

    return choice;
}

// function for searching the account with help of accno

int searchAccount(Account **arr, int index, int accno)
{

    for (int i = 0; i < index; i++)
    {
        if (accno == (arr[i]->getaccno()))
        {
            return i;
        }
    }

    cout << "Account not found .....\n";
    return -1;
}

int main()
{

    Account *arr[5];

    int choice;
    int index = 0;
    while ((choice = menu()) != Emenu::EXIT)
    {
        int accnotowithdraw;
        int acctowithdrawindex;
        int acctodepositindex;

        switch (choice)
        {

        case ADD_ACCOUNT:
            if (index < 5)
            {
                arr[index] = new Account;
                arr[index]->accept();
                index++;
            }
            else
            {
                cout << "5 accounts already exists \n";
            }

            break;

        case DEPOSIT_AMOUNT:
            int accno;

            cout << "Enter the accno in which u want to deposit : \n";
            cin >> accno;
            acctodepositindex = searchAccount(arr, index, accno);

            if (acctodepositindex != -1)
            {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;

                try
                {
                    arr[acctodepositindex]->deposit(amount);
                    cout << "After transaction (deposited):\n";
                    arr[acctodepositindex]->display();
                }
                catch (inSufficientFundsException &e)
                {
                    e.display();
                }
            }

            break;

        case WITHDRAW_AMOUNT:

            cout << "Enter accno from which u want to withdraw \n";
            cin >> accnotowithdraw;

            acctowithdrawindex = searchAccount(arr, index, accno);

            if (acctowithdrawindex != -1)
            {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;

                try
                {
                    arr[acctowithdrawindex]->withdraw(amount);
                    cout << "After transaction (withdrawn):\n";
                    arr[acctowithdrawindex]->display();
                }
                catch (inSufficientFundsException &e)
                {
                    e.display();
                }
            }

            break;

        case DISPLAY:

            for (int i = 0; i < index; i++)
            {
                arr[i]->display();
            }
            break;
        }
    }
}