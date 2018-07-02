int getRandom() {
    int choice;
    ListNode* node = start;
    int count = 0;
    while(node){
        count++;
        if (rand()%count == 0)
            choice = node->val;
        node = node->next;
    }
    return choice; 
}