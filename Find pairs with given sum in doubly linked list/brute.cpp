//Time=O(n^2) , Space=O(n^2)
class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> mpp;
        Node* temp1 = head;
        
        while (temp1 != NULL)
        {
            Node* temp2 = temp1->next;
            while (temp2 != NULL)
            {
                if ((temp1->data + temp2->data) == target)
                {
                    mpp.push_back({temp1->data, temp2->data});
                }
                temp2 = temp2->next;
            }
            temp1 = temp1->next;
        }
        return mpp;
    }
};