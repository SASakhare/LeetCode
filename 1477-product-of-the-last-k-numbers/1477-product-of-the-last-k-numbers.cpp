class ProductOfNumbers {
    private :
     vector<int>preProd;
     int ind=-1;
     int n=0;

public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        n++;
        if(num==0)
        {
            preProd.push_back(0);
            ind=n-1;

        }else if(preProd.size()==0 || preProd.back()==0){
            preProd.push_back(num);
            
        }
        else
        {
            preProd.push_back(num*preProd.back());
        }
    }
    
    int getProduct(int k) {
        
        int temp=n-1-k;//last index up to which we can use

        if(temp<ind)
        {
            return 0;
        }else if(temp==ind)
        {
            return preProd.back();
        }
        
        return preProd.back() /preProd[temp];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */