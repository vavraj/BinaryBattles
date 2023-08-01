#include <iostream>
class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};


void convertToSortedDLL(TreeNode *root, TreeNode *&head)
{
    if (root == NULL)
        return;

    convertToSortedDLL(root->right, head);

    root->right = head;
    if (head != NULL)
        head->left = root;

    head = root;
    convertToSortedDLL(root->left, head);
}


TreeNode *mergeSotedDLL(TreeNode *head1, TreeNode *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    TreeNode *head = NULL;
    TreeNode *tail = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }
    return head;
}



int countNodes(TreeNode *root)
{
    int count = 0;
    while (root != NULL)
    {
        count++;
        root = root->right;
    }
    return count;
}



TreeNode *convertToBST(TreeNode *&head, int n)
{
    if (n <= 0 || head == NULL)
    {
        return NULL;
    }

    TreeNode *left = convertToBST(head, n / 2);

    TreeNode *root = head;
    root->left = left;

    head = head->right;

    root->right = convertToBST(head, n - n / 2 - 1);
    return root;
}


TreeNode *mergeBST(TreeNode *root1, TreeNode *root2)
{
    TreeNode *head1 = NULL;
    convertToSortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode *head2 = NULL;
    convertToSortedDLL(root2, head2);
    head2->left = NULL;

    TreeNode *head = mergeSotedDLL(head1, head2);

    return convertToBST(head, countNodes(head));
}