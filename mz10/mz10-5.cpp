#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::stack<std::string> st;
    char c;
    
    while (std::cin >> c) {
        if (c >= 'a' && c <= 'z') {
            st.push(std::string(1, c));
        } else {
            std::string exp2 = st.top();
            st.pop();
            std::string &exp1 = st.top();
            exp1 = '(' + exp1 + c + exp2 + ')';
        }
    }

    std::cout << st.top() << std::endl;

    return 0;
}
