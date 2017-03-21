template<class T>
class Node {
private:
     T data;
     Node<T>* nextNode;
     Node<T>* prevNode;
public:
    Node();
    Node(T data, Node<T>* nextNode);
    Node(T data, Node<T>* nextNode, Node<T>* prevNode);
    void setData(T data);
    void setNextNode(Node<T>* nextNode);
    void setPrevNode(Node<T>* prevNode);
    T getData();
    Node<T>* getNextNode();
    Node<T>* getPrevNode();
};

template<class T>
Node<T>::Node() {
     nextNode = NULL;
     prevNode = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T>* nextNode) {
     this->data = data;
     this->nextNode = nextNode;
     prevNode = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T>* nextNode, Node<T>* prevNode) {
     this->data = data;
     this->nextNode = nextNode;
     this->prevNode = prevNode;
}

template<class T>
void Node<T>::setData(T data) {
     this->data = data;
}

template<class T>
void Node<T>::setNextNode(Node<T>* nextNode) {
     this->nextNode = nextNode;
}

template<class T>
void Node<T>::setPrevNode(Node<T>* prevNode) {
     this->prevNode = prevNode;
}

template<class T>
T Node<T>::getData() {
     return data;
}

template<class T>
Node<T>* Node<T>::getNextNode() {
     return nextNode;
}

template<class T>
Node<T>* Node<T>::getPrevNode() {
     return prevNode;
}