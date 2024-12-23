
    Node* findMin(Node* node) {
        while (node->left != NULL) node = node->left;
        return node;
    }

    Node* deleteNode(Node* node, string name) {
        if (node == NULL) return node;
        if (name < node->name) {
            node->left = deleteNode(node->left, name);
        } else if (name > node->name) {
            node->right = deleteNode(node->right, name);
        } else {
            if (node->left == NULL) {
                Node *temp = node->right;
                delete node;
                return temp;
            } else if (node->right == NULL) {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = findMin(node->right);
            node->name = temp->name;
            node->right = deleteNode(node->right, temp->name);
        }
        return node;
    }