#include<iostream>
#define maxAmount 5000
#define password "cpp123"
using namespace std;

//*** VARIABLES ***//
string inputPassword = "";
int balance = 10000;
int userOption = 1;
//*** Choices and Functions ***//
void depositMoney ();
void withdrawMoney ();
bool isPasswordCorrect(string inputPassword);

int main() 
{
    system("color 3");
    cout<<"---------------------------------\n";
    cout<<"Hello Sir ! Please Enter Your Password !\n";                                                                         
    cout<<"Password : ";
    cin>>inputPassword;
    
    if (isPasswordCorrect(inputPassword)) 
    {
        SUCCESS_LOGIN :
        cout<<"---------------------------------\n";
        cout<<"What Do You Want to Do ?\n";
        cout<<"[1] Display Balance.\n";
        cout<<"[2] Deposit Money.\n";
        cout<<"[3] Withdraw Money.\n";
        cout<<"[4] EXIT.\n";
        cout<<"----------\n";
        cout<<"operation : ";
        cin>>userOption;
        cout<<"---------------------------------\n";
        switch (userOption)
        {
            case 1 :
                cout<<"==========BALANCE==========\n";
                cout<<"Your Current Balance is "<<balance<<" SDG\n";
            break;
            
            case 2 :
                cout<<"==========DEPOSIT MONEY==========\n";
                depositMoney();
            break;
            
            case 3 :
                cout<<"==========WITHDRAW MONEY==========\n";
                withdrawMoney();
            break;
            
            case 4 :
                cout<<"========THANKS FOR USING HAVE A NICE DAY ;-)========\n";
                goto EXIT;
            break;
            
            default :
                cout<<"OUT OF RANGE ! CHOOSE BETWEEN 1-4 !!\n";
            break;
            cout<<"---------------------------------\n";
        }
        goto SUCCESS_LOGIN;
    }
    else 
    {
        cout<<"---------------------------------\n";
        cout<<"Wrong Password ! Please Try Again !\n";
        cout<<"Password : ";
        cin>>inputPassword;
        if (isPasswordCorrect(inputPassword))
            goto SUCCESS_LOGIN;
        else 
        {
            cout<<"---------------------------------\n";
            cout<<"Sorry ! Wrong Password, Try Again Later !\n";
            goto EXIT;
        }
    }
    
    EXIT :
    cout<<"---------------------------------\n";
    return 0;
}

///==========================================================///

//*** CHECK PASSWORD ***//
bool isPasswordCorrect (string inputPassword)
{ 
    return inputPassword==password ;
}

//*** DEPOSIT MONEY ***//
void depositMoney ()
{
    int depositedAmount = 0;
    cout<<"amount of deposit : ";
    cin>>depositedAmount;
    
    if (depositedAmount<=maxAmount)
    {
        balance += depositedAmount;
        cout<<"Money Deposited Sucessfully !\n";
    }
    else
        cout<<"Can not Deposit More than 5,000 SDG at Once !!\n";
}

//*** WITHDRAW MONEY ***//
void withdrawMoney ()
{
    int withdrawedAmount = 0;
    if (balance==0)
        cout<<"Sorry You Don't Have Any Balance !\n";
    else
    {
        cout<<"current balance :"<<balance<<" SDG\n";
        cout<<"withdraw :";
        cin>>withdrawedAmount;
        if (withdrawedAmount <= balance and withdrawedAmount <= maxAmount)
        {
            balance -= withdrawedAmount;
            cout<<"Money Withdrawed Sucessfully !\n";
        }
        else if (withdrawedAmount > balance) 
            cout<<"You Don't Have Enough Balance !!\n";
        else if (withdrawedAmount > maxAmount) 
            cout<<"Can not Withdraw More Than 5,000 SDG at Once !!\n";
    }
}

