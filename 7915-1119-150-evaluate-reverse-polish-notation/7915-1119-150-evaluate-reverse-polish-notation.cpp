class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto each : tokens){
            if(each =="+"||each=="-" || each =="*" || each =="/"){
                int operand2 = st.top();
                st.pop();

                int operand1=st.top();
                st.pop();

                if(each=="+")   st.push(operand1+operand2);
                else if(each =="-") st.push(operand1-operand2);
                else if(each=="*")  st.push(operand1*operand2);
                else if(each=="/")  st.push(operand1/operand2);
            } else{
                st.push(stoi(each));
            }
        }
    
        return st.top();
    }
};