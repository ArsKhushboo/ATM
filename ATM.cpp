#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
/* Project-ATM
    -> Check Balance
    -> Cash Withdraw
    -> User Details
    -> Update Mobile No.
*/
class atm
{
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_No;
public:
    //setData function is setting the Data into the private member variables
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_No_a)
    {
    account_No = account_No_a;
    name = name_a;
    PIN = PIN_a;
    balance = balance_a;
    mobile_No = mobile_No_a;
    }
    // getAccountNo function is returning the users's account No.
    long int getAccountNo()
    {
        return account_No;
    }
    // getName function is returning the users's Name.
    string getName()
    {
        return name;
    }
    // getPIN function is returning the users's PIN.
    int getPIN()
    {
        return PIN;
    }
    // getBalance function is returning the users's Bank Balance.
    double getBalance()
    {
        return balance;
    }
    // getMobileNo function is returning the users's Mobile No.
    string getMobileNo()
    {
        return mobile_No;
    }
    // setMobile function is updating the user monile no.
    void setMobile(string mob_prev, string mob_new)
    {
        if(mob_prev==mobile_No)
        {
            mobile_No = mob_new;
            cout<<endl<<"Successfully updated Mobile No.";
            _getch();
        }
        else
        {
            cout<<endl<<"Incorrect Old Mobile No.";
            _getch();
        }
    }
    //cashWithDraw function is used to withdraw money from ATM
    void cashWithDraw(int amount_a)
    {
        if(amount_a > 0 && amount_a < balance)
        {
            balance -= amount_a;
            cout<<endl<<"Please Collect Your Cash";
            cout<<endl<<"Available Balance:"<<balance;
            _getch();
        }
        else
        {
            cout<<endl<<"Invalid Input or Insufficient Balance";
            _getch();
        }
    }

};

int main()
{
    int choice = 0, enterPIN;
    long int enterAccountNo;
    system("cls");

    atm user1;
    user1.setData(1234567,"Neha",9876,45000.09,"9876543210");

    do
    {
        system("cls");
        cout<<endl<<"Welcome To ATM"<<endl;
        cout<<endl<<"Enter Your Account No";
        cin>>enterAccountNo;

        cout<<endl<<"Enter PIN";
        cin>>enterPIN;

        // check whether enter values matches with user details
        if((enterAccountNo == user1.getAccountNo())&&(enterPIN == user1.getPIN()))
        {
            do
            {
                int amount = 0;
                string oldMobileNo,newMobileNo;

                system("cls");

                cout<<endl<<"Welcome To Atm"<<endl;
                cout<<endl<<"Select Options";
                cout<<endl<<"1.Check Balance";
                cout<<endl<<"2.Cash Withdraw";
                cout<<endl<<"3.Show User Details";
                cout<<endl<<"4.Update Mobile No.";
                cout<<endl<<"5. Exit"<<endl;
                cin>>choice;
                switch(choice)
                {
                    case 1:
                    cout<<endl<<"Your Bank Balance Is :"<<user1.getBalance();
                    _getch();
                    break;

                    case 2:
                    cout<<endl<<"Enter the amount:";
                    cin>>amount;
                    user1.cashWithDraw(amount);
                    break;

                    case 3:
                    cout<<endl<<" User Details Are:";
                    cout<<endl<<" Account No :"<<user1.getAccountNo();
                    cout<<endl<<" Name :"<<user1.getName();
                    cout<<endl<<" Balance :"<<user1.getBalance();
                    cout<<endl<<" Mobile No:"<<user1.getMobileNo();
                    _getch();
                    break;

                    case 4:
                    cout<<endl<<"Enter Old Mobile No:";
                    cin>>oldMobileNo;
                    cout<<endl<<"Enter New Mobile No :";
                    cin>>newMobileNo;
                    user1.setMobile(oldMobileNo,newMobileNo);
                    break;

                    case 5:
                     exit(0);
                    
                    default:
                    cout<<"Enter Valid Data";
                }
            } while (1);
            
        }
    } while (1);
    
}
