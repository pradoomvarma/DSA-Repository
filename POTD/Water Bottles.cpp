class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles + (numBottles / numExchange);
        int exch = (numBottles / numExchange) + (numBottles % numExchange);
        while(exch >= numExchange) {
            cnt += exch / numExchange;
            exch = (exch / numExchange) + (exch % numExchange);
        }
        return cnt;;
    }
};  