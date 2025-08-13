class SeatManager {
    private :

    vector<int>seat;
    int size;

    void Heapify()
    {
        int parent=0;

        while(parent<size)
        {
            int left=2*parent + 1;
            int right= 2* parent + 2;

            if(left <size && right <size)
            {
                int child = seat[left] < seat[right] ? (seat[left]<seat[parent] ? left : parent) : (seat[right]<seat[parent] ? right : parent);
                if(child==parent)
                {
                    break;
                }else
                {
                    swap(seat[parent],seat[child]);
                    parent=child;
                }

            }else if( left <size && seat[left] < seat[parent])
            {
                swap(seat[parent],seat[left]);
                break;
            }else
            {
                break;
            }
        }
    }
public:
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
        {
            seat.push_back(i);
        }
        this->size=n;
    }
    
    int reserve() {
        int seat_no=seat[0];
        seat[0]=seat[size-1];
        size--;
        Heapify();
        return seat_no;
    }
    
    void unreserve(int seatNumber) {
        seat[size]=seatNumber;
        
        int index=size;

        while(index>0 && seat[(index-1)/2] > seat[index])
        {
            swap(seat[(index-1)/2] , seat[index]);
            index=(index-1)/2;
        }
        size++;
        return ;
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */