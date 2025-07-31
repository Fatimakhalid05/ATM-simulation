#include<iostream>
#include<fstream>

using namespace std;
string usernames[50];
string pins[50];
float balance[50];
int total_users=0;
void savedusers(){
	ifstream in("users.txt");
	total_users=0;
	while(in>>usernames[total_users]>>pins[total_users]>>balance[total_users]){
		total_users++;
	}
	in.close();
	
}
void newsave(){
	ofstream out("users.txt");
	for(int i=0; i<total_users; i++)
	{
		out<<usernames[i]<<" "
		<<pins[i]<<" "
		<<balance[i]<<endl;
	}
	out.close();
}
int finduser(string entername){
	for(int i=0; i<total_users; i++)
	{
		if (usernames[i]==entername)
		{
		
		
		
		return 1;
		}
		else
{
	
	
		return 0;}
	}
	
	
}
void save_receipt(string name, string action, float amount, float bal)
{
	ofstream file("receipt.txt");
	file<<"---Reciept---"<<endl;
	file<<"User: "<<name<<endl;
	 file   <<"Action: "<<action<<endl;
		file<<"Amount: "<<amount<<endl;
		file<<"Balance: "<<bal<<endl;
		file.close();    
}
int main()
{
savedusers();
string entername;



string enterpin;
int index;
string option;
cout<<"******ATM INTERFACE SIMULATION******"<<endl;
cout<<"Enter username: "<<endl;
cin>>entername;
index=finduser(entername);	
if(index==0){
	cout<<"User not found.... Registring new user"<<endl;
	usernames[index]=entername;
	cout<<"enter 4-digit PIN..."<<endl;
	cin>>enterpin;
	balance[total_users]=0;
	index=total_users;
	total_users++;
	cout<<"User registered successfully...."<<endl;
	
}
else
{
	cout<<"Enter PIN"<<endl;
	cin>>enterpin;
	
	if(pins[index]==enterpin)
	
		cout<<"login successful.."<<endl;
	
	else
	{
		cout<<"Incorrect PIN...."<<endl;
		cout<<"Forget Password? (Yes/No).."<<endl;
		cin>>option;
		if(option=="yes")
		{
		cout<<"Enter new PIN"<<endl;
		cin>>pins[index];
		cout<<"PIN changed successfully.."<<endl;	
		}
		else
		{
			cout<<"login failed"<<endl;
		}
	}
}
int choice;
cout<<"---------ATM Menu---------"<<endl;
cout<<"Press 1 to check your balance.."<<endl;
cout<<"Press 2 to deposit money.."<<endl;
cout<<"Press 3 to withdraw money.."<<endl;
cout<<"Press 4 to exit.."<<endl;
cout<<"choose the option..."<<endl;
cin>>choice;
if(choice==1)
{
	cout<<"Current balance: "<<balance[index]<<endl;
	save_receipt(usernames[index],"check balance",0,balance[index]);
}
else if(choice==2)
{ float dep;
	cout<<"Enter deposit amount.."<<endl;
	cin>>dep;
	balance[index]=balance[index]+dep;
	cout<<"Deposit successful...New balance is: "<<balance[index];
	save_receipt(usernames[index],"Deposit",dep,balance[index]);
}
else if(choice==3)
{  float wid;
	cout<<"Enter amount you want to withdraw.."<<endl;
	cin>>wid;
	balance[index]=balance[index]-wid;
	cout<<"Withdraw successful...New balance is: "<<balance[index];
	save_receipt(usernames[index],"Withdraw",wid,balance[index]);
}
else if(choice==4)
{
	cout<<"....Thank You...."<<endl;
}
else
{
	cout<<"Invalid option...Try again.... "<<endl;
}
return 0;
}
