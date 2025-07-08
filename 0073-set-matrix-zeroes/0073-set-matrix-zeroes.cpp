class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        	// Write your code here.
    int n=matrix.size();
    int m=matrix[0].size();
	unordered_map<int,int>Map;
	vector<vector<int>>mark(n);
	int row=0;

	while(row<n)
	{

		auto b=matrix[row].begin();
		auto e=matrix[row].end();

		auto it=find(b,e,0);

		while(it!=e)
		{
		int j=distance(b,it);
		mark[row].push_back(j);
		matrix[row][j]=-1;
		it=find(b,e,0);
		}

		row++;

	}


	row=0;

	while(row<n)
	{
		if(!mark[row].empty())
		{

			//* Making the row to be zeros.

			for(int i=0;i<m;i++)
			{
				matrix[row][i]=0;
			}

			//** Making the all mark column to be zeros.
			while(!mark[row].empty())
			{
				int index=mark[row].back();
				mark[row].pop_back();

				if(Map.count(index)==0)
				{

				
				for(int x=0;x<n;x++)
				{
					matrix[x][index]=0;
				}
				Map[index]=1;
				}
			}
			
		}

		row++;

	}





return  ;

    }
};