#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int Max(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

struct tree {
    int value;
    struct tree* left;
    struct tree* right;
};

struct tree* AddTree(struct tree* tree, int father, int baby, int* puppyf) {
    if (tree == NULL) {
            if (*puppyf == 1) {
            tree = (struct tree*) malloc (sizeof(struct tree));
            tree -> value = baby;
            tree -> left =  NULL;
            tree -> right = NULL;
            *puppyf = 2;
        }
    } else if ((father == tree -> value) && (*puppyf == 0)) {
        *puppyf = 1;
        tree -> left = AddTree(tree -> left, father, baby, puppyf);
    } else if (*puppyf == 1) {
        tree -> right = AddTree(tree -> right, father, baby, puppyf);
    } else if (*puppyf == 0) {
        tree -> left = AddTree(tree -> left, father, baby, puppyf);
        tree -> right = AddTree(tree -> right, father, baby, puppyf);
    }
    return (tree);
}



void TreePrint(struct tree* tree, int count) {
    if (tree != NULL) { 
        for (int i = 0; i < count; ++i) {
            printf(" ");
        }
        ++count;
        printf("%d\n", tree -> value);
        TreePrint(tree -> left, count);
        --count;
        TreePrint(tree -> right, count);
    }
}


    

int height(struct tree* tree) {
    if (tree == NULL) {
        return 0;
    }
    int left = height(tree->left);
    int right = height(tree->right);
    return Max(left, right) + 1;
}

int numberVertexesOnLevels[1000];
void dfs(struct tree* tree, int nodeHeight, int (&numberVertexesOnLevels)[1000]) {
    numberVertexesOnLevels[nodeHeight] += 1;

    if (tree->left != NULL)  dfs(tree->left, nodeHeight + 1, numberVertexesOnLevels);
    if (tree->right != NULL) dfs(tree->right, nodeHeight + 1, numberVertexesOnLevels);
}

int width(struct tree* tree) {
    int he = height(tree);
    dfs(tree, 0, numberVertexesOnLevels);
    int max = numberVertexesOnLevels[0];

    for (int i = 0; i < 1000; ++i) {
        if (numberVertexesOnLevels[i] > max) {
            max = numberVertexesOnLevels[i];
        }
    }
    return max;
}


int main(void) {
    int numberVertexesOnLevels[1000];
    struct tree* root;
    root = NULL;
    int count;
    scanf("%d", &count);
    int father, son;
    scanf("%d %d", &father, &son);
    int fatherFound = 1;
    root = AddTree(root, father, son, &fatherFound);
    for (int i = 0; i < count - 1; ++i) {
        scanf("%d %d", &father, &son);
        fatherFound = 0;
        root = AddTree(root, father, son, &fatherFound);
    }
    TreePrint(root, 0);
    int maxCount = 0;
    int res = width(root);
    printf("res = %d\n", res);

    return 0;
} 