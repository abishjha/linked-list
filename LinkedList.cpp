#include<iostream>
#include<string> //just in case the input type is string...not required for other data types
#include<algorithm> //used in random_shuffle function
#include"Node.cpp"

template<class T>
class LinkedList {
private:
     //private variables
     int count;
     int type;
     Node<T>* head;
     Node<T>* tail;

     //private functions
     void append(Node<T>* n);
     void remove_tail();
     void push(Node<T>* n);
     Node<T>* pop();
     void remove_i(int i);
     Node<T>* get_i(int i);
     void add_i(Node<T>* n, int i);
     void print();
     void deleteList();
     void reverse();
     void rotate(int rotations);
     void random_shuffle();
     int size();
public:
     LinkedList(int type);
     bool isEmpty();
     bool perform_operation(int op_code, T value);
};

template<class T>
LinkedList<T>::LinkedList(int type) {
     count = 0;
     this->type = type;
     head = NULL;
}

template<class T>
void LinkedList<T>::append(Node<T>* n) {
     if (!isEmpty()) {
          if (type == 2 || type == 4)
               n->setPrevNode(tail);
          tail->setNextNode(n);
          if (type == 3 || type == 4)
               n->setNextNode(head);
          else
               n->setNextNode(NULL);
          tail = n;

     }
     else {
          head = n;
          tail = n;
          if (type == 2 || type == 4)
               n->setPrevNode(tail);
          if (type == 3 || type == 4)
               tail->setNextNode(head);
          else
               tail->setNextNode(NULL);
     }
     count++;
}

template<class T>
void LinkedList<T>::remove_tail() {
     if (!isEmpty()) {
          if (count == 1) {
               delete head;
               head = tail = NULL;
          }
          else {
               Node<T>* temp = head;
               while (temp->getNextNode() != tail)
                    temp = temp->getNextNode();

               delete temp->getNextNode();
               if (type == 3 || type == 4)
                    temp->setNextNode(head);
               else
                    temp->setNextNode(NULL);
               tail = temp;
          }
          count--;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
void LinkedList<T>::push(Node<T>* n) {
     if (isEmpty()) {
          head = n;
          tail = n;
          if (type == 2 || type == 4)
               n->setPrevNode(tail);
          if (type == 3 || type == 4)
               tail->setNextNode(head);
          else
               tail->setNextNode(NULL);
     }
     else {
          n->setNextNode(head);
          if (type == 2 || type == 4)
               head->setPrevNode(n);

          head = n;
          if (type == 3 || type == 4)
               tail->setNextNode(head);
     }
     count++;
}

template<class T>
Node<T>* LinkedList<T>::pop() {
     Node<T>* returnVal = new Node<T>;
     returnVal->setData(NULL);
     if (!isEmpty()) {
          if (count == 1) {
               returnVal->setData(head->getData());
               delete head;
               head = tail = NULL;
          }
          else {
               returnVal->setData(head->getData());
               Node<T>* temp = head->getNextNode();
               delete head;
               head = temp;
               if (type == 2)
                    temp->setPrevNode(NULL);
               if (type == 3 || type == 4)
                    tail->setNextNode(head);
               if (type == 4)
                    head->setPrevNode(tail);
          }
          count--;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;

     return returnVal;
}

template<class T>
void LinkedList<T>::remove_i(int i) {
     if (!isEmpty()) {
          Node<T>* temp = head;
          if (i > 1 && i <= count) {
               for (int j = 1; j < i - 1; j++)
                    temp = temp->getNextNode();

               Node<T>* temp2 = temp->getNextNode()->getNextNode();
               delete temp->getNextNode();
               temp->setNextNode(temp2);
               if (type == 2 || type == 4)
                    temp2->setPrevNode(temp);
               count--;
          }
          else if (i == 1) {
               delete head;
               count--;
          }
          else
               std::cout << "\tplease enter a valid index" << std::endl;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
Node<T>* LinkedList<T>::get_i(int i) {
     if (!isEmpty()) {
          if (i > 0 && i <= count) {
               Node<T>* temp = head;
               for (int j = 1; j < i; j++)
                    temp = temp->getNextNode();
               return temp;
          }
          else
               std::cout << "\tplease enter a valid index" << std::endl;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;

     return NULL;
}

template<class T>
void LinkedList<T>::add_i(Node<T>* n, int i) {
     if (!isEmpty()) {
          if (i == count)
               append(n);
          else if (i == 1) {
               n->setNextNode(head);
               if (type == 2 || type == 4)
                    head->setPrevNode(n);

               head = n;
               if (type == 2 || type == 4)
                    tail->setPrevNode(head);

               count++;
          }
          else if (i > 1 && i < count) {
               Node<T>* temp = head;
               for (int j = 1; j < i - 1; j++)
                    temp = temp->getNextNode();
               n->setNextNode(temp->getNextNode());
               temp->setNextNode(n);
               if (type == 2 || type == 4) {
                    n->setPrevNode(temp);
                    n->getNextNode()->setPrevNode(n);
               }
               count++;
          }
          else
               std::cout << "\tplease enter a valid index" << std::endl;
     }
     else if (count == 0 && i == 1) {
          append(n);
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
void LinkedList<T>::print() {
     if (!isEmpty()) {
          Node<T>* temp = head;
          if (type == 3 || type == 4)
               tail->setNextNode(NULL);
          while (temp != NULL) {
               std::cout << "\t" << temp->getData() << std::endl;
               temp = temp->getNextNode();
          }
          if (type == 3 || type == 4)
               tail->setNextNode(head);
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
void LinkedList<T>::deleteList() {
     Node<T>* temp = head;
     Node<T>* temp2;
     if (type == 3 || type == 4)
          tail->setNextNode(NULL);
     do {
          temp2 = temp->getNextNode();
          delete temp;
          temp = temp2;
          count--;
     } while (temp != NULL);
}

template<class T>
void LinkedList<T>::reverse() {
     if (!isEmpty()) {
          if (count > 1) {
               Node<T>* prev = NULL;
               Node<T>* current = head;
               Node<T>* next = NULL;

               if (type == 3 || type == 4)
                    tail->setNextNode(NULL);

               tail = head;
               while (current != NULL) {
                    next = current->getNextNode();
                    current->setNextNode(prev);
                    if (type == 2 || type == 4)
                         current->setPrevNode(next);
                    prev = current;
                    current = next;
               }
               head = prev;

               if (type == 3 || type == 4) {
                    tail->setNextNode(head);
                    if (type == 4)
                         head->setPrevNode(tail);
               }
          }
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
void LinkedList<T>::rotate(int rotations) {
     if (!isEmpty()) {
          Node<T>* temp = head;
          T* ptr = new T[count];
          tail->setNextNode(head);

          for (int i = 0; i < count; i++) {
               ptr[i] = temp->getData();
               temp = temp->getNextNode();
          }
          temp = get_i(rotations + 1);

          for (int i = 0; i < count; i++) {
               temp->setData(ptr[i]);
               temp = temp->getNextNode();
          }
          if (type == 1 || type == 2)
               tail->setNextNode(NULL);

          delete[] ptr;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
void LinkedList<T>::random_shuffle() {
     if (!isEmpty()) {
          int size = count;
          Node<T>* temp = head;
          T* ptr = new T[size];

          for (int i = 0; i < size; i++) {
               ptr[i] = temp->getData();
               temp = temp->getNextNode();
          }
          deleteList();

          std::random_shuffle(&ptr[0], &ptr[size]); //random shuffle
          for (int i = 0; i < size; i++) {
               temp = new Node<T>;
               temp->setData(ptr[i]);
               push(temp);
          }

          delete[] ptr;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
int LinkedList<T>::size() {
     return count;
}

template<class T>
bool LinkedList<T>::isEmpty(){
    if(count == 0)
        return true;
    else
        return false;
}

template<class T>
bool LinkedList<T>::perform_operation(int op_code, T value) {
     Node<T>* temp = new Node<T>;
     int index;

     switch (op_code) {
     case 1: //append
          temp->setData(value);
          append(temp);
          return true;
     case 2: //remove tail
          remove_tail();
          return true;
     case 3: //push
          temp->setData(value);
          push(temp);
          return true;
     case 4: //pop
          temp = pop();
          if (temp->getData() != NULL)
               std::cout << "\tpopped " << temp->getData() << std::endl;
          delete temp;
          return true;
     case 5: //remove i
          std::cout << "\tplease enter the index: ";
          std::cin >> index;
          remove_i(index);
          return true;
     case 6: //get i
          std::cout << "\tplease enter the index: ";
          std::cin >> index;
          temp = get_i(index);
          if (temp != NULL)
               std::cout << "\tvalue at " << index << " is " << temp->getData() << std::endl;
          return true;
     case 7: //add i
          std::cout << "\tplease enter the index: ";
          std::cin >> index;
          temp->setData(value);
          add_i(temp, index);
          return true;
     case 8: //print
          print();
          return true;
     case 9: //delete list
          deleteList();
          return true;
     case 10: //reverse
          reverse();
          return true;
     case 11: //rotate
          std::cout << "\tplease enter number of rotations: ";
          std::cin >> index;
          rotate(index);
          return true;
     case 12: //random shuffle
          random_shuffle();
          return true;
     case 13: //size
          std::cout << "\tthe size is " << size() << std::endl;
          return true;
     }
     return false;
}