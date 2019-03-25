#include <stdio.h>
#include <iostream>
#include <string> // for string, and to_string
#include <iomanip> // for setw, std:left, std:right

typedef struct tree {
  int item;
  tree *parent;
  tree *left;
  tree *right;

  tree(): parent(nullptr), left(nullptr), right(nullptr) {}
  tree(int v) {
    this->item = v;
    this->parent = nullptr;
    this->left = nullptr;
    this->right = nullptr;
  }
} tree;

namespace bst {
  tree* search(tree *l, int x) {
  if (l == nullptr) return(nullptr); // empty return
  if (l->item == x) return(l); // found right at root, return root

  if (x < l->item) {
    return search(l->left, x);
  } else {
    return search(l->right, x);
  }
  }


  void traversal_in_order (tree *l) {
    if (l == nullptr) return;
    
    traversal_in_order(l->left);
    std::cout <<  std::setw(4) << l->item << std::endl;
    traversal_in_order(l->right);
  }

  void traversal_pre_order (tree *l) {
    if (l == nullptr) return;
    std::cout << l->item << std::endl;
    traversal_pre_order(l->left);
    traversal_pre_order(l->right);
  }

  void traversal_post_order (tree *l) {
    if (l == nullptr) return;
    traversal_post_order(l->right);
    traversal_post_order(l->left);
    std::cout << l->item << std::endl;
  }

  tree* find_minimum(tree* l) {
    if ( l==nullptr ) return(l);
    tree* min_tree;
    while (l->left != nullptr) {
      min_tree = l->left;
    }
    return min_tree;
  }

  tree* find_maximum(tree *l) {
    if (l == nullptr) return(l);
    tree* max_tree;
    while(l->right != nullptr) {
      max_tree = l->right;
    }
    return max_tree;
  }

  int max_depth(tree* l) {
    if (l == nullptr) return(0);

    int lDepth = max_depth(l->left);
    int rDepth = max_depth(l->right);

    if (lDepth > rDepth) {
      return (lDepth + 1);
    } else {
      return (rDepth + 1);
    }
  }

  void insert_tree(tree **l, int x, tree* parent) {
    tree *p; // temporary pointer

    // if we hit leaf, add new node, and move the linked pointer to new node
    tree *current = (*l);
    if ( current == nullptr) {
      p = new tree(x);
      p->parent = parent;
    // update linked subtree
      *l = p;
      return;
    }
    
    if (x < current->item) {
      insert_tree( &(current->left), x, *l ); 
    }else {
      insert_tree( &(current->right), x, *l);
    }
  }

  namespace {
    void _delete_tree(tree *l) {
      if (l==nullptr) return;
      _delete_tree(l->left);
      _delete_tree(l->right);
      std::cout << "delete " << l->item << std::endl;
      delete l;
    }
  }

  void delete_tree (tree** l) {
    _delete_tree(*l);
    *l = nullptr;
  }

  tree* delete_node(tree* l, int x) {
  // base case
  if (l == nullptr) return l;
  if (x < l->item) {
    l->left = delete_node(l->left, x);
  } // x is smaller, hence look only left branch

  if (x > l->item ) {
    l->right = delete_node(l->right, x);
  } // x is larger, hence look only right branch

  if ( x == l-> item) {
    if ( l->left == nullptr) {
      tree* tmp = l->right;
      l->parent = nullptr;
      delete(l);
      return tmp; 
    }else if ( l->right == nullptr){
      tree *tmp = l->right;
      l->parent = nullptr;
      delete(l);
      return tmp;
    } // these blocks assign node back to the above two assignment

  tree* tmp = find_minimum(l->right); // populate the leftmost node in the right brach to replace the current node

  l->item = tmp->item;
  
  // delete the inorder sucess
  l->right = delete_node(l->right, tmp->item);

  } // find the correct node to delete, do the rearrange 

  return l;
}

  void pprint(tree* l, int indent = 2) {
    if (l == nullptr) return;
    indent = indent + 2;
    pprint(l->right, indent);
      for (int i = 2; i < indent; ++i ) 
      {
        std::cout << " ";
      }
      std::cout << l->item << std::endl;
    pprint(l->left, indent);
  }

  /// - MARK: Test cases
  void test_delete_node() {
    tree* root =  new tree(5);
    int data[] = {3,7,2,4,6,8};
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; ++i){
      int v = data[i];
      insert_tree(&root, v, root);
    }
    traversal_in_order(root);
    std::cout << std::endl <<"------------------" << std::endl;
    tree* new_root = delete_node(root, 2);
    // pprint(new_root);
    traversal_in_order(root);
  }

  void test_delete_tree() {
      tree * root = new tree(2);
    int data[] =  {1,7,4,8,6,5};
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; ++i){
      int v = data[i];
      bst::insert_tree(&root, v, root);
    }
    bst::pprint(root);
    bst::delete_tree(&root);
  }

    void test_max_depth() {
    tree* root =  new tree(5);
    int data[] = {3,7,2,4,6,8};
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; ++i){
      int v = data[i];
      insert_tree(&root, v, root);
    }
    pprint(root);
    std::cout << std::endl <<"------------------" << std::endl;
    int depth = max_depth(root);
    std::cout << "Tree's depth is: " << depth << std::endl;

    traversal_in_order(root);
  }

}




int main(int argc, char* argv[]) {


  bst::test_max_depth();
  return EXIT_SUCCESS;
}
