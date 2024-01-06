class DataStream {
public:
 int tempk, tempv;
 unordered_map<int,int>count;
    DataStream(int value, int k) {
       tempk=k;
       tempv=value; 
    }
    queue<int>q;
    bool consec(int num) {
    q.push(num);
    count[num]++;
    if(q.size()>tempk)
    {
        int front = q.front();
            q.pop();
            count[front]--;
            if (count[front] == 0) {
                count.erase(front);
            }
    }
    if(q.size()==tempk && count.size() == 1 && count.begin()->first == tempv)
    {
        return true;
        
    }
    return false;
    }
};