https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        // TC-O(n) sc-O(3*n)--3n for leftsmaller array,rightsmaller and stack;
//         int leftsmaller[n];
//         int rightsmaller[n];
//         stack<int>s;
//         for(int i=0;i<n;i++)
//         {
//             while(!s.empty() && heights[s.top()]>=heights[i])
//             {
//                 s.pop();
//             }
//             if(s.empty())
//             {
//                 leftsmaller[i]=0;
//             }
//             else
//             {
//                 leftsmaller[i]=s.top()+1;
//             }
            
//             s.push(i);
//         }
//         while(!s.empty())
//         {
//             s.pop();
//         }
//         for(int i=n-1;i>=0;i--)
//         {
//             while(!s.empty() && heights[s.top()]>=heights[i])
//             {
//                 s.pop();
//             }
//             if(s.empty())
//             {
//                 rightsmaller[i]=n-1;
//             }
//             else
//             {
//                 rightsmaller[i]=s.top()-1;
//             }
            
//             s.push(i);
//         }
//         int maxA=0;
//         for(int i=0;i<n;i++)
//         {
//             maxA = max(maxA, heights[i] * (rightsmaller[i] - leftsmaller[i] + 1));
//         }
//         return maxA;
        
        
        
        
        
        
        // TC-O(n), SC-O(n);
        stack<int>s;
        int maxa=0;
        for(int i=0;i<=n;i++)
        {
            while(!s.empty() && (i==n ||heights[i]<=heights[s.top()]))
            {
                int h=heights[s.top()];
                s.pop();
                int wid;
                if(s.empty())
                {
                    wid=i;
                }
                else
                {
                    int l=s.top();
                    wid=i-l-1;
                }
                maxa=max(maxa,h*wid);
            }
            s.push(i);
        }
        return maxa;
    }
};