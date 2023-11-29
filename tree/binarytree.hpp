template <class T>
struct Node{
    T data;
    Node<T>* left;
    Node<T>* right;
};

template <class T>
class BinaryTree{
    protected:
        Node<T>* root;
    public:
        BinaryTree();
        bool isEmpty();
        void inorderTrav();
        void preorderTrav();
        void postorderTrav();
        int treeHeight();
        int treeNodeCount();
        int treeLeavesCount();
        void destroyTree();
        ~BinaryTree();
    private:

        void inorder(Node<T>*);
        void preorder(Node<T>*);
        void postorder(Node<T>*);
        int height(Node<T>*);
        int max(int, int);
        int nodeCount(Node<T>*);
        int leavesCount(Node<T>*);
        void destroy(Node<T>*);
};

template<class T>
BinaryTree<T>::BinaryTree(){
    root = NULL;
}

template<class T>
bool BinaryTree<T>::isEmpty(){
    return root==NULL;
}

template<class T>
void BinaryTree<T>::inorderTrav(){
    inorder(root);
}

template<class T>
void BinaryTree<T>::inorder(Node<T>* p){
    if(p != NULL){
        inorder(p->left);
        cout << p->info << " ";
        inorder(p->right);
    }
    return;
}

template<class T>
int BinaryTree<T>::treeHeight(){
    return height(root);
}

template<class T>
int BinaryTree<T>::height(Node<T>* p){
    if(p == NULL){
        return 0;
    }else{
        return 1 + max(height(p->left), height(p->right));
    }
}

template<class T>
int BinaryTree<T>::max(int x, int y){
    if(x >= y){
        return x;
    }else{
        return y;
    }
}

template<class T>
int BinaryTree<T>::treeNodeCount(){
    return nodeCount(root);
}

template <class T>
int BinaryTree<T>::nodeCount(Node<T>* p){
    return 1;
}