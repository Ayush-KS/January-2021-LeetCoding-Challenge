// Merge k Sorted Lists

class Compare {
    public:
    bool operator () (pair<int, ListNode*> t1, pair<int, ListNode*> t2) {
    	return t1.first > t2.first;
	}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Compare> pq;
        
        ListNode* outHead = NULL;
        ListNode* outTail = NULL;
        int i = 0;
        for(ListNode* head : lists) {
            if(head)
                pq.push({head -> val, head});
        }
        
        while(pq.size()) {
            pair<int, ListNode*> top = pq.top();
            pq.pop();
            ListNode* newNode = new ListNode(top.first);
            if(!outTail) {
                outHead = newNode;
                outTail = newNode;
            } else {
                outTail -> next = newNode;
                outTail = newNode;
            }
            if(top.second -> next == NULL)
                continue;
            else
                pq.push({top.second -> next -> val, top.second -> next});
        }
        
        return outHead;
    }
};