#pragma once

// this file contains the declaration and function implementation of the Single_Linked_List class


using namespace std;

template <typename Item_Type>
class Single_Linked_List {
private:

    // the nodes of the list defined as having the data and a pointer to the next node
    struct Node {
        Item_Type data;
        Node* next;
        Node(const Item_Type& data_item, Node* next_ptr = nullptr) :
            data(data_item), next(next_ptr) {}
    };
    Node* head;
    Node* tail;
    int num_items;

public:

    // main constructor
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    // ALL OF THE REST OF THE FUBCTIONS ARE DEFINED TO HAVE THE SAME FUCTIONALITY AS THEIR standard list class COUNTERPART

    void push_front(const Item_Type& item) {
        head = new Node(item, head);
        if (num_items == 0) {
            tail = head;
        }
        ++num_items;
    }

    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item);
        if (num_items == 0) {
            head = new_node;
        }
        else {
            tail->next = new_node;
        }
        tail = new_node;
        ++num_items;
    }

    void pop_front() {
        if (num_items > 0) {
            Node* old_head = head;
            head = head->next;
            delete old_head;
            --num_items;
            if (num_items == 0) {
                tail = nullptr;
            }
        }
    }

    void pop_back() {
        if (num_items > 0) {
            if (num_items == 1) {
                delete tail;
                head = tail = nullptr;
            }
            else {
                Node* cur = head;
                while (cur->next != tail) {
                    cur = cur->next;
                }
                delete tail;
                tail = cur;
                tail->next = nullptr;
            }
            --num_items;
        }
    }

    Item_Type front() const {
        return head->data;
    }

    Item_Type back() const {
        return tail->data;
    }

    bool empty() const {
        return num_items == 0;
    }

    void insert(int index, const Item_Type& item) {
        if (index == 0) {
            push_front(item);
        }
        else {
            Node* cur = head;
            for (int i = 1; i < index && cur != nullptr; ++i) {
                cur = cur->next;
            }
            if (cur == nullptr) {
                push_back(item);
            }
            else {
                cur->next = new Node(item, cur->next);
                ++num_items;
                if (cur == tail) {
                    tail = cur->next;
                }
            }
        }
    }

    bool remove(int index) {
        if (index >= num_items) {
            return false;
        }
        else {
            Node* cur = head;
            Node* prev = nullptr;
            for (int i = 0; i < index; ++i) {
                prev = cur;
                cur = cur->next;
            }
            if (prev == nullptr) {
                head = cur->next;
            }
            else {
                prev->next = cur->next;
            }
            if (cur == tail) {
                tail = prev;
            }
            delete cur;
            --num_items;
            return true;
        }
    }

    int find(const Item_Type& item) {
        Node* cur = head;
        for (int i = 0; i < num_items; ++i) {
            if (cur->data == item) { return i; }
            cur = cur->next;
        }
        return num_items;
    }

};