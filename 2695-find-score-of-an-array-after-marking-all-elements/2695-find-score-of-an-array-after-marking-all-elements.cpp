class Solution {
public:
    long long findScore(vector<int>& nums) {

        // int N = nums.size();
        // long long Scores = 0;

        // while (true) {

        //     int Small = -1; // Index
        //     int Smallval = INT_MAX;

        //     for (int i = 0; i < N; i++) {
        //         if (Smallval > nums[i]) {
        //             Small = i;
        //             Smallval = nums[i];
        //         }
        //     }

        //     if (Small == -1) {
        //         break;
        //     }

        //     Scores += nums[Small];
        //     nums[Small] = INT_MAX;
        //     int next = Small + 1;
        //     int pre = Small - 1;
        //     if (next < N) {
        //         nums[next] = INT_MAX;
        //     }
        //     if (pre >= 0) {
        //         nums[pre] = INT_MAX;
        //     }
        // }

  //  std::vector<std::pair<int, int>> element;
  //       for (int i = 0; i < N; i++) {
  //           element.push_back({nums[i], i});
  //       }

  //       sort(element.begin(), element.end());

  //       // int minElement=element

  //       vector<bool> proccesed(N, false);

  //       for (const auto& [value, index] : element) {
  //           if (proccesed[index]) {
  //               continue;
  //           }

  //           Scores += value;

  //           if (index + 1 < N) {
  //               proccesed[index + 1] = true;
  //           }
  //           if (index - 1 >= 0) {
  //               proccesed[index - 1] = true;
  //           }
  //       }

  //       return Scores;


      // Another Method 3 : Priority_queue:

      int n=nums.size();
      long long score=0;

      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minHeap;// element,index; // element wise the Heap:
      vector<int>mark(n,0);// 0 --> not Marked and 1 --> marked.
      // making the maxHeaP;
      for(int i=0;i<n;i++)
      {
        // maxHeap.push({nums[n-1-i],n-1-i});
        minHeap.push({nums[i],i});
      }


      // for(int i=0;i<n;i++)
      // {
      //   cout<<"("<<maxHeap.top().first<<","<<maxHeap.top().second<<") ";
      //   maxHeap.pop();
      // }

      

      // now getting the element from the heap:

      while(!minHeap.empty())
      {
        
        // auto curr=minHeap.top();
        auto [element,index]=minHeap.top();
        minHeap.pop();

        // int num=curr.first;
        // int index=curr.second;
        if(mark[index]==0)
        {
          score+=nums[index];
          mark[index]=1;
          // if(index-1>=0 && mark[index-1]!=1)
          // {
          //   mark[index-1]=1;
          // }
            
            if(index-1>=0)
              mark[index-1]=1;

          // if(index+1<n  && mark[index+1]!=1)
          // {
          //   mark[index+1]=1;
          // }
            if(index+1<n)
              mark[index+1]=1;
        }
      }
      
      return score;
    }
};