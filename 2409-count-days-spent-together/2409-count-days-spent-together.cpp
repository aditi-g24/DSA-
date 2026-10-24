class Solution {
public:
    int convert(string &s){
        int month = stoi(s.substr(0,2));
        int date = stoi(s.substr(3,2));

        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        for(int i = 0; i < month-1; i++){
            date+=days[i];
        }

        return date;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int startA = convert(arriveAlice);
        int startB = convert(arriveBob);
        int endA = convert(leaveAlice);
        int endB = convert(leaveBob);

        int start = max(startA, startB);
        int end = min(endA, endB);

        if(start > end) return 0;
        else{
            return end-start+1;
        }
    }
};