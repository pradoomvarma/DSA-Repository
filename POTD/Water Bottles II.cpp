class Solution {
public:

    typedef long long ll;

    int maxBottlesDrunk(int numBottles, int numExchange) {
        int emptyBottle = 0, drunk = 0;
        drunk += numBottles;
        emptyBottle = numBottles;
        numBottles = 0;

        while((numBottles + emptyBottle) >= numExchange) {
            if(emptyBottle >= numExchange) {
                numBottles++;
                emptyBottle -= numExchange;
                numExchange++;
            }
            else {
                drunk += numBottles;
                emptyBottle += numBottles;
                numBottles = 0;
            }
        }

        drunk += numBottles;

        return drunk;
    }
};