// lab 2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "github.h"

void print(githubuser* arr, const int size)//function to print
{
	for (int b=0;b<size;b++)
	{
		cout<<endl<<endl;
		cout<<"The first name of user "<<b+1<<" is: "<<endl;
		cout<<arr[b].firstName;
		cout<<endl;
		cout<<"The username of user "<<b+1<<" is: "<<endl;
		cout<<arr[b].userName;
		cout<<endl;
		cout<<"The password of user "<<b+1<<" is: "<<endl;
		cout<<arr[b].password;
		cout<<endl;
		cout<<"The email of user "<<b+1<<" is: "<<endl;
		cout<<arr[b].email;
		cout<<endl;
		cout<<"The foldercount of user "<<b+1<<" is: "<<endl;
		cout<<arr[b].folderCount;
		cout<<endl;

        
	}

}
void printarr2(githubuser arr2)//function to print arr2
{
	    cout<<endl<<endl;
	    cout<<"The first name of is:"<<endl;
		cout<<arr2.firstName;
        cout<<endl;
		cout<<"The username of is:"<<endl;
		cout<<arr2.userName;
		cout<<endl;
		cout<<"The password of user[b] is:"<<endl;
		cout<<arr2.password;
		cout<<endl;
		cout<<"The email of user[b] is:"<<endl;
		cout<<arr2.email;
		cout<<endl;
		cout<<"The foldercount of user[b] is:"<<endl;
		cout<<arr2.folderCount;
		cout<<endl;


}
bool Comparison(githubuser user1 , githubuser user2);//compare to users
void inputFromUser(githubuser* &arr, int &size);//input from user to populate
githubuser* searchUser ( githubuser* users, int size, string userName) //search different users and return address
{
	for(int j=0; j<size;j++)
	{
		if(users[j].userName==userName)
		{
			return users+j;

		}

	}
	return nullptr;
}
bool exists(githubuser* arr, int size, string userName)//search if user already exists
{
	for (int i=0;i<size;i++)
	{
		if(arr[i].userName==userName)
			return true;

	}
	return false;
}


int main()
{
	int size=0;
	string username;
	githubuser* arr1=nullptr; 

	inputFromUser(arr1, size);
	print(arr1,size);
	cout<<endl;
	cout<<"enter the username to search:"<<endl;
	cin>>username;
	githubuser* arr2 = searchUser(arr1,size,username);
	if(arr2!=nullptr)
		{
			printarr2(*arr2);
        }
	else 
		cout<<"user not found! 404"<<endl;
    delete[] arr1;




	return 0;
}

bool Comparison(githubuser user1, githubuser user2)
{
	if (user1.userName==user2.userName || user1.email==user2.email )
	{
       return true;
	}

	return false;
}

void inputFromUser(githubuser* &arr, int &size)
{
	cout<<"enter the number of users:"<<endl;
	cin>>size;
	arr=new githubuser[size];

	for(int a=0; a<size; a++)
	{
		cout<<"enter the first name:"<<endl;
		cin>>arr[a].firstName;
		cout<<"enter the username:"<<endl;
		cin>>arr[a].userName;
		while (!exists(arr,size,arr[a].userName))
		{
			cout<<"This username already exists"<<endl;
			cin>>arr[a].userName;
		}
		cout<<"enter the password:"<<endl;
		cin>>arr[a].password;
		cout<<"enter the email:"<<endl;
		cin>>arr[a].email;
		cout<<"enter the number of folders:"<<endl;
		cin>>arr[a].folderCount;
		
		
		

	}


}

