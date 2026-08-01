/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;

        Node* curr = head;
        stack<Node*> st;

        while(curr!=NULL){
            if(curr->child){
                st.push(curr);
                curr = curr->child;
            }else{
                curr=curr->next;
            }
        }

        while(!st.empty()){
            Node* par = st.top();
            st.pop();
            Node* ch = par->child;
            if(par->next==NULL){
                par->next = ch;
                ch->prev=par;
                par->child=NULL;
                continue;
            }
            Node* lastNode= ch;
            while(lastNode->next){
                lastNode = lastNode->next;
            }
            Node* nxtNode = par->next;
            par->next = ch;
            ch->prev = par;
            lastNode->next = nxtNode;
            nxtNode->prev = lastNode;
            par->child=NULL;

        }

        return head;

    }
};