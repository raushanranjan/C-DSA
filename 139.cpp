#include <bits/stdc++.h>
using namespace std;


class List{
    private:
  struct Node{
    int data;
    Node* link;
};
    typedef struct Node* nodePtr;
    
    nodePtr curr;
    nodePtr temp;
    nodePtr next;
    nodePtr prev;
    public:
    nodePtr head;
    List(){
        head =NULL;
        curr = NULL;
        temp = NULL;
        next= NULL;
        prev= NULL;
    }
    void addNode(int value){
        nodePtr n = new Node;
        n->link = NULL;
        n->data = value;
        if(head!=NULL){
            curr = head;
            while(curr->link != NULL){
                curr = curr->link;
            }
            curr->link = n;
        }
        else{
            head = n;

        }
    }
    void DeleteNode(int delData){
        nodePtr delPtr = NULL;
        temp = head;
        curr = head;
        while(curr->link != NULL && curr->data != delData){
          
            temp = curr;
            curr = curr->link;
        }
        if (curr==NULL){
           
            cout<< delData << " is not in the list"<< endl;
            delete delPtr;
    }
        else{
          
            delPtr = curr;
            curr = curr->link;
            temp->link = curr;
            if (delPtr == head){
                head = head->link;
                temp=NULL;
            }
            delete delPtr;
            cout<<"the value "<< delData << "was deleted\n"<< endl;
        }
    }
    void PrintList(){
        curr = head;
        while(curr!=NULL){
            cout<< curr->data<< endl;
            curr = curr->link;
        }
    }
    void ReverseLL(){
        curr = head;
        
        while(curr!=NULL){
            next = curr->link;
            curr->link = prev;
            prev = curr;
            curr = next;
        }
        head = prev;

    }
    nodePtr RecursiveReverse(nodePtr c){
        nodePtr next1;
        if(c->link==NULL){
            head=c;
            return head;
        }
        else{
        next1 = c->link;
        head = RecursiveReverse(next1);
        next1->link=c;
   
        c->link=NULL;
        return head;
        }


    }


};
//Node* A;
//A = NULL;
//
int main(){
    
    List myLL;
    myLL.addNode(3);
     
   // myLL.addNode(5);
    //myLL.addNode(6);
    //myLL.addNode(31);
    myLL.addNode(52);
    myLL.addNode(63);
   // myLL.PrintList();
  // myLL.DeleteNode(3);
     // myLL.PrintList();
     // myLL.ReverseLL();
    myLL.PrintList();
    myLL.RecursiveReverse(myLL.head);
    myLL.PrintList();

return 0;
}