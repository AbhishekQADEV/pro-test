#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

// Binary Search Tree Implementation
struct BST {
    int data;
    struct BST* left;
    struct BST* right;
};

struct BST* CreateNode() {
    struct BST* new = (struct BST*)malloc(sizeof(struct BST));
    new->left = NULL;
    new->right = NULL;
    return new;
}

void Insert(struct BST** RootPtr, int value) {
    struct BST* temp = *RootPtr;
    if (temp == NULL) {
        /*When list is empty*/
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        *RootPtr = NewNode;
    }
    else if (value <= temp->data) {
        /*If user value is less then current node value insert in left of the node...*/
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->left = NewNode;
    }
    else {
        /*If user value is greater then current node value insert at right of the node*/
        struct BST* NewNode = CreateNode();
        NewNode->data = value;
        temp->right = NewNode;
    }
}

int Search(struct BST* RootPtr, int item) {
    /*Implemented search using recursion*/
    if (RootPtr == NULL) {
        return 0; /*Returns 0 if list is empty*/
    }
    else if (item == RootPtr->data) {
        return 1; /*Returns 1 when element found*/
    }
    else if (item < RootPtr->data) {
        Search(RootPtr->left, item); /*Otherwise search in left side of binary tree if searching value is less then the current node value*/
    }
    else {
        Search(RootPtr->right, item); /*Otherwise search in right side of binary tree if searching value is greater then the current node value*/
    }
}

void main() {
    struct BST* RootPtr = NULL;
    int item, cont, key;
    do {
        printf("Enter item: ");
        scanf("%d", &item);
        Insert(&RootPtr, item);
        printf("\n1 to keep inserting/ 0 to Exit: ");
        scanf("%d", &cont);
    } while (cont == 1);
    printf("\nEnter element to search: ");
    scanf("%d", &key);
    if (Search(RootPtr, key) == 0) {
        printf("\nFound\n");
    }
    else {
        printf("\nNot Found\n");
    }
}

// Doubly Linked List Implementation
struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
};

struct Node* head;

struct Node* CreateNode() {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    return new;
}

void Insert(int val) {
    /*Inserting element at head*/
    struct Node* NewNode = CreateNode();
    /*NewNode is created everytime function is called*/
    NewNode->value = val;
    /*Value assigned to NewNode*/
    NewNode->next = head;
    /*NewNode's next points to head*/
    NewNode->prev = NULL;
    /*NewNode's previous points to NULL*/
    if (head != NULL) {
        head->prev = NewNode;
    }
    head = NewNode;
}

void Display() {
    struct Node* temp = head;
    printf("\nForward:\n");
    /*Printing normally in forward manner*/
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

void ReverseDisplay() {
    struct Node* temp = head;
    while (temp->next != NULL) {
        /*Moving to the last node*/
        temp = temp->next;
    }
    printf("\nBackward:\n");
    /*Printing in backward manner*/
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("\n");
}

void main() {
    int n, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter element: ");
        scanf("%d", &val);
        Insert(val);
        /*Inserting value everytime loop executes*/
    }
    Display();
    ReverseDisplay();
}

// Menu-driven Linked List Implementation
struct node {
    int data;
    struct node* next;
};

struct node* head;

// Structure used to create node again and again when required..
struct node* CreateNode() {
    struct node* new = (struct node*)malloc(sizeof(struct node));
    return new;
}

void InsertAtBegin(int value) {
    struct node* NewNode = CreateNode();
    if (head == NULL) {
        /*Only works when list is empty*/
        NewNode->data = value;
        head = NewNode;
        NewNode->next = NULL;
    }
    else {
        printf("\n\t**Element already exists at this position**\n");
    }
}

void InsertAtnthNode(int pos, int value) {
    struct node* temp = head;
    if (pos == 1) {
        printf("\n\t**Use Insert at begining**\n");
    }
    else {
        struct node* NewNode = CreateNode();
        NewNode->data = value;
        NewNode->next = NULL;
        for (int i = 0; i < pos - 2; i++) {
            temp = temp->next;
            /*Accessing(n-1)th node*/
        }
        NewNode->next = temp->next;
        /*Linking nth node to(n+1)th node*/
        temp->next = NewNode;
        /*Linking(n-1)th node to nth node*/
    }
}

void InsertAtEnd(int value) {
    if (head == NULL) {
        /*Does not work when list is empty. Underflow situation...*/
        printf("\n\t**Use Insert at begining**\n");
    }
    else {
        struct node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        struct node* NewNode = CreateNode();
        NewNode->data = value;
        NewNode->next = temp->next;
        temp->next = NewNode;
        /*Links new node n to(n-1)th node*/
    }
}

void DeleteAtBegin() {
    if (head == NULL) {
        /*Does not work when list is empty. Underflow situation...*/
        printf("\n\t**No element exists**\n");
    }
    else {
        head = head->next;
        /*2nd node is now declared as head*/
        printf("\n\t**Element deleted successfully**\n");
    }
}

void DeleteAtEnd() {
    if (head == NULL) {
        /*Does not work when list is empty. Underflow situation...*/
        printf("\n\t**No element exists**\n");
    }
    else if (head->next == NULL) {
        printf("\n\t**Use Delete at begining**\n");
    }
    else {
        struct node* temp = head;
        while (temp->next->next != NULL) {
            /*Accessing(n-1)th node*/
            temp = temp->next;
        }
        temp->next = NULL;
        /*(n-1)th node will now point to null instead of nth node*/
        free(temp->next);
        printf("\n\t**Element deleted successfully**\n");
    }
}

void DeletenthNode(int pos) {
    struct node* temp = head;
    if (pos == 1) {
        printf("\n\t**Use Delete at begining**\n");
    }
    else {
        for (int i = 0; i < pos - 2; i++) {
            temp = temp->next;
        }
        struct node* temp2 = temp->next;
        /*Accessing nth node, which we want to delete*/
        temp->next = temp2->next;
        /*(n-1)node is pointing to(n+1)node now. Breaking the link between(n-1),n,(n+1)nodes.*/
        free(temp2);
        printf("\n\t**Element deleted successfully**\n");
    }
}

void Display() {
    if (head == NULL) {
        printf("\n\t**No elements to display**\n\n");
    }
    else {
        struct node* temp = head;
        printf("\nCurrent List:\n");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

void main() {
    head = NULL;
    int ch;
    while (1) {
        printf("\n\t\t**MENU**\n");
        printf("\t1. Insert at begining\n");
        printf("\t2. Insert at nth position\n");
        printf("\t3. Insert at end\n");
        printf("\t4. Delete at begining\n");
        printf("\t5. Delete at end\n");
        printf("\t6. Delete nth node\n");
        printf("\t7. Display\n");
        printf("\t8. Exit\n");
        printf("\n\tEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1:
            printf("\nEnter value to be inserted: ");
            int v1;
            scanf("%d", &v1);
            InsertAtBegin(v1);
            break;
        case 2:
            printf("\nEnter position to insert value: ");
            int v2, pos1;
            scanf("%d", &pos1);
            printf("Enter value to be inserted: ");
            scanf("%d", &v2);
            InsertAtnthNode(pos1, v2);
            break;
        case 3:
            printf("\nEnter value to insert at end: ");
            int v3;
            scanf("%d", &v3);
            InsertAtEnd(v3);
            break;
        case 4:
            DeleteAtBegin();
            break;
        case 5:
            DeleteAtEnd();
            break;
        case 6:
            printf("\nEnter position to delete element: ");
            int pos2;
            scanf("%d", &pos2);
            DeletenthNode(pos2);
            break;
        case 7:
            Display();
            break;
        case 8:
            printf("\n\t**THANK YOU!**\n");
            exit(0);
        default:
            printf("\n\t**Chose a valid option**\n");
        }
    }
}

// Binary Search Implementation
int binsearch(int yarr[10], int element) {
    int mid = sizeof(yarr) / sizeof(yarr[0]) / 2;
    int left = (int)yarr / 2 - mid;
    int right = yarr - left;
    extern int i;
    if (element == mid)
        printf("%d", &mid);
    if (element != yarr[right]) {
        for (i = 0; i < left; i++) {
            if (element == i) { //Does this so that it doesn't print multiple times
                printf("%d", i);
            }
        }
    }
}

int main(int argc, int argv[]) {
    binsearch(argv[0], argv[1]);
}

// Bubble Sort Implementation
void bubble_sort(int* array, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

int main(void) {
    int yarr[] = { 3, 9, 4, 8, 7, 6, 1, 2, 0, 10 };
    bubble_sort(yarr, 10);
    printf("[");
    for (int i = 0; i < 10; i++)
        printf("%d, ", yarr[i]);
    printf("\b\b]\n");
    return 0;
}

// Counting Numbers Implementation
int count(int num) {
    printf("[");
    if (num > 20) {
        int i;
        for (i = 0; i < num; i++)
            printf("\n%d, \n", i);
        if (i == num + 1)
            printf("]");
    }
    else {
        int i;
        for (i = 0; i < num; i++)
            printf("%d", i);
        if (i == num)
            printf("]");
    }
}

int main() {
    int num;
    printf("Count:~$ ");
    scanf("%d", &num);
    count(num);
}

// Even or Odd Implementation
int main() {
    long num;
    printf("Enter a number\n");
    scanf("%ld", &num);
    int rem = num % 2;
    if (rem == 0)
        printf("Even");
    else
        printf("Odd");
}

// Factorial Implementation
int fak(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    else if (n < 0) {
        return 1;
        exit(1);
    }
    return n * fak(n - 1);
}

int main() {
    printf("fak(1): %d\n", fak(1));
    printf("fak(2): %d\n", fak(2));
    printf("fak(3): %d\n", fak(3));
    printf("fak(4): %d\n", fak(4));
    printf("fak(5): %d\n", fak(5));
    printf("fak(-1): %d\n", fak(-1));
    return 1;
}

// Infinite Loop Implementation
int main() {
    long a;
    long b;
    for (a = 0, b = 1; b > a; b++) {
        a++;
        printf("%ld \n %ld", &a, &b);
    }
    if (b == sizeof(long)) {
        exit(1);
    }
}

// Selection Sort Implementation
void print_arr(int* ptr, int size) {
    putchar('[');
    while (size--) {
        printf("%d", *ptr++);
        if (size)
            putchar(',');
    }
    printf("]\n");
}

void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

int* find_min(int* ptr, int size) {
    int* min;
    min = ptr;
    while (size--) {
        if (*ptr < *min)
            min = ptr;
        ptr++;
    }
    return (min);
}

void selection_sort(int* ptr, int size) {
    int* min;
    while (--size) {
        if ((min = find_min(ptr + 1, size))) {
            if (*ptr > *min)
                swap(ptr, min);
        }
        ptr++;
    }
}

void fill(char** av, int* ptr, int size) {
    int i;
    i = 2;
    while (av[i] && size--)
        *ptr++ = atoi(av[i++]);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        puts("Usage: ./your-executable-name [array size] [array]");
        puts("Example: ./your-executable-name 3 2 1 0");
        return EXIT_FAILURE;
    }
    int size = atoi(argv[1]);
    if (!size) {
        puts("Error: size of array can't be 0");
        return EXIT_FAILURE;
    }
    int* arr = malloc(size * sizeof(int));
    if (!arr)
        return EXIT_FAILURE;
    fill(argv, arr, size);
    printf("Before sorting: ");
    print_arr(arr, size);
    selection_sort(arr, size);
    printf("After sorting: ");
    print_arr(arr, size);
    free(arr);
    return EXIT_SUCCESS;
}

// Merge Sort Implementation
void merge(int a[], int low, int mid, int high) {
    int b[20]; //same size of a[]
    int i, j, k;
    i = low, j = mid + 1, k = low;
    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= mid)
        b[k++] = a[i++];
    while (j <= high)
        b[k++] = a[j++];
    for (k = low; k <= high; k++)
        a[k] = b[k];
}

void mergesort(int a[], int low, int high) {
    int mid;
    if (low >= high)
        return;
    mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}

int main() {
    int a[7] = { 83, 20, 9, 50, 115, 61, 17 };
    int n = 7;
    mergesort(a, 0, n - 1);
    printf("\n Sorted numbers are:");
    for (int k = 0; k < 7; k++)
        printf(" %d,", a[k]);
    return 0;
}

// Quick Sort Implementation
void swap(int* a, int* b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int a[], int l, int h) {
    int i = l, j = l, p = h;
    while (i < h) {
        if (a[i] < a[p]) {
            swap(&a[i], &a[j]);
            j++;
        }
        i++;
    }
    swap(&a[p], &a[j]);
    return j;
}

void quick_sort(int a[], int l, int h) {
    int p;
    if (l < h) {
        p = partition(a, l, h);
        quick_sort(a, l, p - 1);
        quick_sort(a, p + 1, h);
    }
    return;
}

int main() {
    int size;
    printf("Size: ");
    scanf("%d", &size);
    int* arr = malloc(size * sizeof(int));
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
    quick_sort(arr, 0, size - 1);
    printf("Sorted array:");
    for (int i = 0; i < size; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}

// Keylogger Implementation
int keylog() {
    FILE* fPtr;
    fPtr = fopen("keylogger.txt", "w+");
    fopen("keylogger.txt", "w");
    const char* a = getchar();
    if (a != NULL)
        fprintf(fPtr, a);
    time_t now = time(NULL);
    struct tm* tm_struct = localtime(&now);
    int hour = tm_struct->tm_hour;
    if (hour == 24)
        fclose(fPtr);
}

int main() {
    keylog();
}

// Linear Search Implementation
int linsearch(char** yarr, char* val) {
    int size = sizeof(yarr) / sizeof(yarr[0]);
    for (int i = 0; i < size; i++) {
        if (strcmp(yarr[i], val) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char* yarr[] = { "Shluck much", "much Shluck" };
    char* val = "Shluck Much";
    linsearch(yarr, val);
}