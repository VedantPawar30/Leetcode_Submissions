class Node{
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key,int val){
            this->key = key;
            this->val=val;
            next=NULL;
            prev=NULL;
        }
};
class LRUCache {
    Node* head = new Node(-1,-1);
    Node* tail =new Node(-1,-1);
    unordered_map<int,Node*> mp;
    int size;
public:
    void addNode(Node* newNode){
        Node* nxt = head->next;
        head->next=newNode;
        newNode->prev=head;
        newNode->next=nxt;
        nxt->prev=newNode;
    }
    void delNode(Node* node){
        Node* prv = node->prev;
        Node* nxt = node->next;
        prv->next = nxt;
        nxt->prev =prv;
        //delete node;
    }
    LRUCache(int capacity) {
       size=capacity;
       head->next=tail;
       tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        Node* getNode = mp[key];
        int val = getNode->val;
        
        delNode(getNode);
        mp.erase(key);

        addNode(getNode);
        mp[key] =getNode;
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* oldNode = mp[key];
            mp.erase(key);
            delNode(oldNode);
        }

        if(mp.size()==size){
            mp.erase(tail->prev->key);
            delNode(tail->prev);
        }

        Node* newNode = new Node(key,value);
        addNode(newNode);
        mp[key] =newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */