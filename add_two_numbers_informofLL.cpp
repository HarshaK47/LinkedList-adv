Node* finalList(vector<int> ans,int n){
    int a = ans[0];
    Node* head = new Node(a);
    Node* tail=head;
    for(int i=1;i<n;i++){
        int a = ans[i];
        tail->next = new Node(a);
        tail=tail->next;
    }
    return head;
}

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int cnt1=1;
        int cnt2=1;
        Node* t1=first;
        Node* t2=second;
        while(t1!=NULL){
            t1=t1->next;
            cnt1++;
        }
        while(t2!=NULL){
            t2=t2->next;
            cnt2++;
        }
        
        Node* prev=NULL;
        Node* next=NULL;
        Node* curr=first;
        t1=first;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        t1=prev;
        
        
        prev=NULL;
        next=NULL;
        curr=second;
        t2=second;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        t2=prev;
        
        vector<int> ans;
        int carry=0;
        
        while(t1!=NULL and t2!=NULL){
            int sum=t1->data + t2->data;
            if(sum+carry<10){
                ans.push_back(sum+carry);
                carry=0;
            }
            else{
                int rem;
                rem=(sum+carry)%10;
                carry=(sum+carry)/10;
                ans.push_back(rem);
            }
            t1=t1->next;
            t2=t2->next;
        }
        
        
        while(t2!=NULL){
            int sum = t2->data + 0;
            if(sum+carry<10){
                ans.push_back(sum+carry);
                carry=0;
            }
            else{
                int rem;
                rem=(sum+carry)%10;
                carry=(sum+carry)/10;
                ans.push_back(rem);
            }
            t2=t2->next;
            
        }
        
        while(t1!=NULL){
            int sum = t1->data + 0;
            if(sum+carry<10){
                ans.push_back(sum+carry);
                carry=0;
            }
            else{
                int rem;
                rem=(sum+carry)%10;
                carry=(sum+carry)/10;
                ans.push_back(rem);
            }
            t1=t1->next;
            
        }
        if(carry!=0){
            ans.push_back(carry);
        }
        
        reverse(ans.begin(),ans.end());
        
        Node* newHead=finalList(ans,ans.size());
        return newHead;
        
        
    }
};
