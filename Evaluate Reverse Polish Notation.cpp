
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
Note that:
The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
Example 1:
Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9
Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n=tokens.size();
        int ans = 0;
        int count = 0;
        int a,b;
         for(int i=0;i<n;i++){
             if(tokens[i]=="+"){
                 a = st.top();
                 st.pop();
                 b=st.top();
                 st.pop();
                 ans = (a+b);
                 st.push(ans);
             }
             else if(tokens[i]=="-"){
                 a=st.top();
                 st.pop();
                 b=st.top();
                 st.pop();
                 ans=b-a;
                 st.push(ans);
             }
             else if(tokens[i]=="*"){
                 a=st.top();
                 st.pop();
                 b=st.top();
                 st.pop();
                 ans=a*b;
                 st.push(ans);
             }
             else if(tokens[i]=="/"){
                 a=st.top();
                 st.pop();
                 b=st.top();
                 st.pop();
                 ans=(b/a);
                 st.push(ans);
             }
             else{
                 st.push(stoi(tokens[i]));
             }
         }
         ans=st.top();
         st.pop();
         return ans;
    }
};
