#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define vc vector

int size;
const int cap=1000;
int arr[cap];
int parent(int i){
	return (i-1)/2;
}
int left(int i){
	return 2*i+1;
}
int right(int i){
	return 2*i+2;
}


void comp_down(int i)
{
	int smallest=i;
	
	if(left(i)<size && arr[left(i)]<arr[i])
	smallest=left(i);
	
	if(right(i)<size && arr[right(i)]<arr[smallest])
	smallest=right(i);
	
	if(i!=smallest)
	{
		swap(arr[i],arr[smallest]);
		comp_down(smallest);
	}
}

void print()
{
	loop(i,0,size)
	cout<<arr[i]<<" ";
	cout<<endl;
}

void comp_up(int i)
{
	if(i!=0 && arr[parent(i)] > arr[i])
	{
		swap(arr[parent(i)],arr[i]);
		comp_up(parent(i));
	}
	else
	return;
}

int remove_root()
{
	swap(arr[0],arr[size-1]);
	size--;
	comp_down(0);
}

void del(int i)
{
	if(i==0)
	remove_root;
	else
	{
		swap(arr[i],arr[size-1]);
		size--;
		if(arr[i]<arr[parent(i)])
		comp_up(i);
		else
		comp_down(i);
	}
}

int main()
{

	cout<<"Enter the number of elements ";
	cin>>size;

	
	cout<<"Enter the elements "<<endl;
	loop(i,0,size)
	cin>>arr[i];
	
	cout<<"Given array is "<<endl;
	print();
	
	// creating a min heap from a user given array 
	for(int i=(size-2)/2;i>=0;i--)
	{
		comp_down(i);
	}
	
	cout<<"Min heap is "<<endl;
	print();
	
	
	//inserting an element in the heap
	cout<<"\nEnter the element to be inserted\n";
	size++;
	cin>>arr[size-1];
	
	comp_up(size-1);
	cout<<"\nThe array after insertion is\n";
	print();
	
	
	// removing the root
	cout<<"\nEnter 1 if you want to remove and review the root\n";
	bool flag;
	cin>>flag;
	if(flag)
	{
		cout<<"Root is "<<arr[0]<<endl;
		cout<<"\nThe updated hea after removing is \n";
		remove_root();
		print();
	}
	
	//deleteing an elememt 
	
	cout<<"\nEnter the index that has to be deleted\n";
	int temp;
	cin>>temp;
	del(temp);
	cout<<"The heap after deleting is \n";
	print();
	
	
	
    
}









