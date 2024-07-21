#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define vc vector

class Node
{
	public:
		int data;
		Node * left=NULL;
		Node * right=NULL;
		
	Node(int d)
	{
		data=d;
	}		
};


Node * insert(Node *root,int d)
{
	if(root==NULL)
	{
		root=new Node(d);
		return root;
	}
	
	if(root->data>d)
	{
		root->left=insert(root->left,d);
	}
	
	if(root->data<d)
	{
		root->right=insert(root->right,d);
	}
	return root;
}


void inorder(Node * root)
{
	if(root==NULL) return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{
    
    int arr[7]={2,4,1,3,6,5,7};
    Node *root=NULL;
    
    for(int i=0;i<7;i++)
    {
    	root=insert(root,arr[i]);
	};
	
	inorder(root);
	cout<<endl;
    
    
    
    
}














