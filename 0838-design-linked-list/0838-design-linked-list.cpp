class Node {
    public:
        int data;
        Node* next;

        Node(int val): data(val), next(nullptr) {}
};
class MyLinkedList {
    private:
        Node* head;
    
    public:
    
        MyLinkedList() : head(nullptr) {}
        
        int get(int index) {
            if (!head) return -1;
            
            Node* ptr = head;
            for (int i = 0; i < index; i++) {
                if (!ptr->next) return -1; 
                ptr = ptr->next;
            }
            return ptr->data;
        }
        
        void addAtHead(int val) {
            Node* newNode = new Node(val);
            newNode -> next = head;
            head = newNode;
        }
        
        void addAtTail(int val) {
            Node* ptr = head;
            if(ptr == nullptr) {
                addAtHead(val);
                return;
            }
            while(ptr -> next != nullptr){
                ptr = ptr -> next;
            }
            Node* newNode = new Node(val);
            ptr -> next = newNode;
        }
        
        void addAtIndex(int index, int val) {
            if (index == 0) {
                addAtHead(val);
                return;
            }

            Node* ptr = head;
            for (int i = 0; i < index - 1; i++) {
                if (!ptr) {  
                    return;
                }
                ptr = ptr->next;
            }

            if (!ptr) return; 

            Node* newNode = new Node(val);
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        
        void deleteAtIndex(int index) {
            if(index == 0) {
                if(head == nullptr) return;
                head = head -> next;
                return;
            }
            Node* ptr = head;
            for(int i = 0; i < index-1; i++) {
                if(ptr -> next == nullptr) return;
                ptr = ptr -> next;
            }
            if(ptr -> next == nullptr) return;
            ptr -> next = ptr -> next -> next;
        }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */