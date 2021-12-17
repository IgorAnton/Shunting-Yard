#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int evaluateS(string s){

    stack<double> st;

    int n = s.length();

    for(int i = 0 ; i < n ; )
    {

        if(s[i] ==' ')
            continue;

        if(isdigit(s[i]) == 1) {
                st.push(s[i] - '0');

        }
        else if(!isdigit(s[i])){
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();

            switch (s[i]) {
                case '+' : st.push(a+b);break;
                case '-' : st.push(b-a);break;
                case '/': st.push(b/a);break;
                case '*' : st.push(a*b);break;

            }

        }
        i++;

    }

    return st.top();

}



int prednost(char c)
{
    if(c == '+' || c=='-')
        return 1;
    else if(c == '*' || c =='/')
        return 2;
    else if(c == '^')
        return 3;
    else
        return -1;
}

double tiF(string s, double br) // trigonometrijska funkcija
{
    if(s == "sin")
    {
        return sin(br);
    }
    else if(s == "cos")
        return cos(br);
    else if(s == "tan")
        return tan(br);

        return atan(br);
}





double evaluateTrig(string s)
{
    stack<double> st;
    int n = s.length();
    string pom ;
    pom  = "";
    string brPom;
    brPom = "";
    for(int i = 0 ; i < n ; ){

        double br;
        if(s[i] == ' ')
        {
            i++;
            continue;
        }
        if(s[i]>='0' && s[i]<='9'){
            br = evaluateS(string(1,s[i]));
            st.push(br);
            i++;
        }
        else if(s[i] == 's'){
            while(!isdigit(s[i])) {
                pom += s[i];
                i++;
            }
            while(isdigit(s[i])){
                brPom+=s[i];
                i++;
            }
            br = stod(brPom);
            st.push(tiF(pom,br));

        }
        else if(s[i] == 'c'){
            while(!isdigit(s[i])) {
                pom += s[i];
                i++;
            }
            while(isdigit(s[i])){
                brPom+=s[i];
                i++;
            }

            br = stod(brPom);
            st.push(tiF(pom,br));

        }
        else if(s[i] == 't'){

            while(!isdigit(s[i])) {
                pom += s[i];
                i++;
            }
            while(isdigit(s[i])){
                brPom+=s[i];
                i++;
            }
            br = stod(brPom);
            st.push(tiF(pom,br));

        }
        else if(s[i] == 'a'){
            while(!isdigit(s[i])) {
                pom += s[i];
                i++;
            }
            while(isdigit(s[i])){
                brPom+=s[i];
                i++;
            }
            br = stod(brPom);
            st.push(tiF(pom,br));

        }

        else{
            float a = st.top();
            st.pop();
            float b = st.top();
            st.pop();

            switch (s[i]) {
                case '+' : st.push(a+b);break;
                case '-' : st.push(b-a);break;
                case '/': st.push(b/a);break;
                case '*' : st.push(a*b);break;

            }
            i++;
        }


        brPom="";
        pom="";

    }


    return st.top();
}

string shuntingYard(string s){

    string res = "";
    stack <char> st;

    int n = s.length();

    for(int i = 0 ; i < n ; i++)
    {
        if(s[i]== ' ')
            continue;

        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9') )
            res+=s[i];
        else if(s[i] == '(')
            st.push(s[i]);
        else if(s[i]==')')
        {
            while( st.top()!='(')
            {
                res += st.top();
                st.pop();
            }

            st.pop();
        }
        else{

            while(!st.empty() && (prednost(s[i]) <= prednost(st.top())))
            {
                res+= st.top();
                st.pop();
            }
            st.push(s[i]);
        }


    }

    while(!st.empty())
    {
        res+=st.top();
        st.pop();
    }

    return res;


}


int main() {

    string s = "2+ 3*5";
    string trig = "cos30 + sin30";
    string e = shuntingYard(s);
    string t = shuntingYard(trig);
    cout << t << "\n";
    cout << e << "\n";
    cout << evaluateS(e) << endl;
    cout << evaluateTrig(t);



    return 0;
}
