// https://leetcode.com/problems/exam-room/

class ExamRoom {
private:
    int N;
    vector<int> data;
public:
    ExamRoom(int n) {
        N = n;
    }
    
    int seat() {
        if(data.size()==0){
            data.push_back(0);
            return 0;
        }

        int idx = -1, maxmDis=0, n=data.size();
        for(int i=0; i<n-1; i++){
            if((data[i+1]-data[i])/2>maxmDis){
                idx = i;
                maxmDis = (data[i+1]-data[i])/2;
            }
        }
        
        int val = -1;
        if(data[0]!=0 && (data[0]-0)>=maxmDis){
            val = 0;
            idx = -1;
            maxmDis = data[0]-0;
        }

        if(data[n-1]!=N-1 && ((N-1)-data[n-1])>maxmDis){
            val = N-1;
            idx = n-1;
        }

        if(val==-1){
            val = data[idx]+maxmDis;
        }
        data.insert(data.begin()+idx+1, val);
        return val;
    }
    
    void leave(int p) {
        int n=data.size(), idx=-1;
        for(int i=0; i<n; i++){
            if(data[i]==p){
                idx = i;
                break;
            }
        }
        data.erase(data.begin()+idx);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */