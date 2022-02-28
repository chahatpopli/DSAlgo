#include <iostream>
#include <queue>
#include<vector>

using namespace std;
template <typename T>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Treenode{
	public:
	T data;
	vector<Treenode<int>*> children;
	Treenode(T data){
		this->data = data;
	}
};



// print Tree Recursively

void printNodeLevel(Treenode<int> *root){
	
	queue<Treenode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        Treenode<int>* front = q.front();
        q.pop();
        cout<<front->data<<":";
         for(int i=0;i<front->children.size();i++)
  	     {  
  	     q.push(front->children[i]);
         if(i==front->children.size()-1)
              cout<<front->children[i]->data;
         
         else
  	         cout<<front->children[i]->data<<",";
 	     }
         cout<<endl;
        
    }
}

// print Tree Levelwise

void printNode(Treenode<int> *root){
	cout << root->data << ":";
	for(int i=0;i<root->children.size();i++){
		cout<< root->children[i]->data<<",";
	}
	cout<<endl;
	for(int i=0;i<root->children.size();i++){
		printNode(root->children[i]);
	}
}

// Take Input Recursively

Treenode<int> *inputtake(){
	int rootData;
	cout<<"Enter the data : ";
	cin>>rootData;
	
	Treenode<int>* root = new Treenode<int>(rootData);
	
	int n;
	cout<<"Enter the Childs of " << rootData<<": ";
	cin>>n;
	for(int i=0;i<n;i++){
		Treenode<int>* child = inputtake();
		root->children.push_back(child);
	}
	return root;
	
}

// Take Input Levelwise

Treenode<int> *inputtakeLevel(){
	int rootData;
	cout<<"Enter the data : ";
	cin>>rootData;
	
	Treenode<int>* root = new Treenode<int>(rootData);
	queue<Treenode<int>*> pendingNodes;
	pendingNodes.push(root);
	while(pendingNodes.size() != 0){
		Treenode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		cout<<"enter the num of children of "<< front->data <<": ";
		int numChild;
		cin>>numChild;
		for(int i=0;i<numChild;i++){
			int childData;
			cout<<"Enter " << i<<"th Child of "<<front->data <<": ";
			cin>>childData;
			
			Treenode<int>* child = new Treenode<int>(childData);
            front->children.push_back(child); // Each child node is pushed

            pendingNodes.push(child);
			
		}
	}
	
	return root;
	
	
}

int main(int argc, char** argv) {
	/*Treenode<int>* root = new Treenode<int>(1);
	Treenode<int>* node1 = new Treenode<int>(2);
	Treenode<int>* node2 = new Treenode<int>(3);
	root->children.push_back(node1);
	root->children.push_back(node2);*/
	
	Treenode<int>* root = inputtakeLevel();
	
	cout<< "Printed Tree Recursively"<<endl;
	printNode(root);
	cout<< "Printed Tree Levelwise"<<endl;
	printNodeLevel(root);
	
}
