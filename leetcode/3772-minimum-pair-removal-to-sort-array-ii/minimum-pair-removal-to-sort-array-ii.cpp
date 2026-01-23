class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        // pair<int,int> -> sum, id where sum start
        std::priority_queue<pair<long long,int>, std::vector<pair<long long,int>>, std::greater<pair<long long,int>>> minHeap;
        int n = nums.size();
        int commitedSteps = 0;
        vector<pair<long long,int>> linkedList(n); // [5, 1], [2, 3], [3, 3], [1, -1];
        vector<pair<long long,int>> reverseLinkedList(n); // [5, -1], [2, 0], [3,1], [1, 2];
        vector<int> deleted_origin_nums(n);
        int wrong_order_count = 0;
        for (int i = 0; i < n-1; i++) {
            minHeap.push(std::make_pair((long long)nums[i] + nums[i+1], i));
            linkedList[i] = std::make_pair((long long)nums[i], i+1);
            reverseLinkedList[i] = std::make_pair((long long)nums[i], i-1);
            if (nums[i] > nums[i+1]) wrong_order_count++;
        }
        linkedList[n-1] = std::make_pair((long long)nums[n-1], -1);
        if (wrong_order_count == 0) {
            return 0;
        }
        while (wrong_order_count > 0 && !minHeap.empty()) {
            std::pair<long long,int> min_sum = minHeap.top();
            minHeap.pop();
            int min_sum_id = min_sum.second;
            long long min_sum_sum = min_sum.first;

            int sumPairSecondNumId = linkedList[min_sum_id].second;
            if (deleted_origin_nums[min_sum_id] || sumPairSecondNumId == -1 || deleted_origin_nums[sumPairSecondNumId]) {
                continue;
            }
            if ((long long) linkedList[min_sum_id].first + linkedList[sumPairSecondNumId].first != min_sum_sum){
                continue;
            }
            int prevNumId = reverseLinkedList[min_sum_id].second;
            int nextNum_afterSumId = linkedList[sumPairSecondNumId].second;
            if (prevNumId != -1) {
                if (linkedList[prevNumId].first > linkedList[min_sum_id].first) {
                    wrong_order_count--;
                }
            }

            if (linkedList[min_sum_id].first > linkedList[sumPairSecondNumId].first){
                wrong_order_count--;
            }
            if (nextNum_afterSumId != -1) {
                if (linkedList[sumPairSecondNumId].first > linkedList[nextNum_afterSumId].first) {
                    wrong_order_count--;
                }
            }

            commitedSteps++;
            linkedList[min_sum_id].first = min_sum_sum;
            deleted_origin_nums[sumPairSecondNumId] = true;

            linkedList[min_sum_id].second = nextNum_afterSumId;
            if (nextNum_afterSumId != -1) {
                reverseLinkedList[nextNum_afterSumId].second = min_sum_id;
            }

            if (prevNumId != -1) {
                if (linkedList[prevNumId].first > linkedList[min_sum_id].first){
                    wrong_order_count++;
                }
                minHeap.push(std::make_pair(linkedList[prevNumId].first + linkedList[min_sum_id].first, prevNumId));
            }

            if (nextNum_afterSumId != -1) {
                if (linkedList[min_sum_id].first > linkedList[nextNum_afterSumId].first) {
                    wrong_order_count++;
                }
                minHeap.push(std::make_pair(linkedList[nextNum_afterSumId].first + linkedList[min_sum_id].first, min_sum_id));
            }
        }
        return commitedSteps;
    }
};