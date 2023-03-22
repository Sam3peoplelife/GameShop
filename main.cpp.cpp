#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class GameinStore	{
private:
	char *company,*title,*marketplace;
	float *price;
	int *stock;
public:	
	GameinStore()	{
	company= new char[20];
	title=new char[20];
	marketplace=new char[20];
	price= new float;
	stock=new int;
	}
	void feeddata();
	void editdata();
	void showdata();
	int search(char[],char[]);
	void buybook();
	
};

void GameinStore::feeddata()	{
	cin.ignore();
	cout<<"\nEnter Company Name: ";      cin.getline(company,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Marketplace Name: ";   cin.getline(marketplace,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;   
	
}

void GameinStore::editdata()	{
	
	cout<<"\nEnter Company Name: ";      cin.getline(company,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Marketplace Name: ";   cin.getline(marketplace,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;     
	
}

void GameinStore::showdata()	{
	cout<<"\nCompany Name: "<<company;
	cout<<"\nTitle Name: "<<title;
	cout<<"\nMarketplace Name: "<<marketplace;
	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;   
	
}

int GameinStore::search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,company)==0)
		return 1;
	else return 0;
		
}

void GameinStore::buygame()	{
	int count;
	cout<<"\nEnter Number Of Game copies to buy: ";
	cin>>count;
	if(count<=*stock)	{
		*stock=*stock-count;
		cout<<"\nGames Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(*price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}

int main()	{
	GameinStore *B[20];
	int i=0,r,t,choice;
	char titlebuy[20],companybuy[20];
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of Game Store"
		<<"\n2. Buy Game"
		<<"\n3. Search For Game"
		<<"\n4. Edit Details Of Game"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;
		
		switch(choice)	{
			case 1:	B[i] = new GameinStore;
				B[i]->feeddata();
				i++;	break;
				
			case 2: cin.ignore();
				cout<<"\nEnter Title Of Game: "; cin.getline(titlebuy,20);
				cout<<"Enter Company Of Game: ";  cin.getline(companybuy,20);
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,companybuy))	{
						B[t]->buygame();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Game is Not in Stock";
				
				break;
			case 3: cin.ignore();
				cout<<"\nEnter Title Of Game: "; cin.getline(titlebuy,20);
				cout<<"Enter Company Of Game: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nGame Found Successfully";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Game is Not in Stock";
				break;
			
			case 4: cin.ignore();
				cout<<"\nEnter Title Of Game: "; cin.getline(titlebuy,20);
				cout<<"Enter Company Of Game: ";  cin.getline(authorbuy,20);
				
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nGame Found Successfully";
						B[t]->editdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Game is Not in Stock";
				break;
			
			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";
			
		}
	}
	
	
	
	
	return 0;
}
