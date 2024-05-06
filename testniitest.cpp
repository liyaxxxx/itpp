void erase(type x) {
    root = eraseNode(root, x);
}

node* eraseNode(node* root, type x) {
    if (root == nullptr) // Base case: If tree is empty
        return root;

    // If the value to be deleted is smaller than the root's value, then it lies in the left subtree
    if (x < root->value)
        root->left = eraseNode(root->left, x);

    // If the value to be deleted is greater than the root's value, then it lies in the right subtree
    else if (x > root->value)
        root->right = eraseNode(root->right, x);

    // If the value is the same as root's value, then this is the node to be deleted
    else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->value = temp->value;

        // Delete the inorder successor
        root->right = eraseNode(root->right, temp->value);
    }
    return root;
}

// Function to find the node with minimum value in a subtree rooted at given node
node* minValueNode(node* node) {
    node* current = node;

    // Loop down to find the leftmost leaf
    while (current && current->left != nullptr)
        current = current->left;

    return current;
}
