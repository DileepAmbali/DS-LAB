
struct listNode{
    int data;
    struct listNode *link;
};

struct listNode* create(int value){
    struct listNode *node;
    node = (struct listNode*)malloc(sizeof(struct listNode));
    node->data = value;
    node->link = NULL;
    return node;
}

void insertEnd(int value){
    struct listNode *node = create(value);
    struct listNode *temp = first;
    while(temp->link){
        temp = node->link;
    }
    temp->link = node;
}


void delete(int value){
    struct listNode *temp = first;
    struct listNode *trail = first;
    
    while(temp->data!=value){
        trail = temp;
        temp = node->link;
    }
    trail->link = temp->link;
}