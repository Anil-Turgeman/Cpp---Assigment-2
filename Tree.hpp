namespace ariel{
    class Tree{

        private:
            struct node{
                int data;
                node* left;
                node* right;
            };

            node* rootValue;

            void   insertPrivate(int data, node* nodeCheck);
            void   removePrivate(int data, node* parent);
            void   removeRoot();
            void   removeMatch(node* parent, node* match, bool left);
            int    sizePrivate(node* ptr);
            bool   containsPrivate(int data, node* ptr);
            node*  SearchNodePrivate(int data, node* ptr);
            int    parentPrivate(int data, node* ptr);
            void   printPrivate(node* ptr);
            int    findSmallestPrivate(node* ptr);
            void   DeconstructorTree(node* nodeCheck);

        public:
            Tree();
            ~Tree();
            node*  createLeaf(int i);
            void   insert(int i);
            void   remove(int i);
            int    size();
            bool   contains(int i);
            int    root();
            int    parent(int i);
            int    right(int i);
            int    left(int i);
            void   print();
            node*  SearchNode(int i);//help function
            int    findSmallest();//help function
        };
};
