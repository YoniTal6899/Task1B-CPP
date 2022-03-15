#include "mat.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
namespace ariel {
    const int MIN=33;
    const int MAX=126;
    string mat(int col, int row, char a, char b) {
        if (col<=0 || row<=0) {__throw_invalid_argument("Enter positive carpet size");}
        if (col %2 == 0 || row%2==0) {__throw_invalid_argument("Enter odd carpet size");}
        if(a<MIN || a>MAX || b<MIN || b>MAX) {__throw_invalid_argument("Enter printable chars");}
        vector<vector<char>> MAT(row, vector<char>(col)); // Using Vector of vectors in order tp represent 2D array.
        int CurrL=0;
        bool flag=false; 
        char sym=a; // default value.
        int max=0; // how many layers do we have?
        if(row>col){max=(col/2)+1;}
        else{max=(row/2)+1;}
        for(CurrL=0;CurrL<max;CurrL++) // Filling every layer 
        {
            if(flag) {sym=b;} // Change symbol
            else {sym=a;}
            flag=!flag;
            for(int i=CurrL;i<col-CurrL;i++) //Fill first row
            {
                MAT[CurrL][i]=sym;
            }
            for(int j=CurrL;j<row-CurrL;j++) //Fill first col
            {
                MAT[j][CurrL]=sym;
            }
            int c=CurrL;
            for(int i=row-CurrL-1;c<col-CurrL;c++)//Fill last row
            {               
                MAT[i][c]=sym;
            }
            c=CurrL;
            for(int j=col-CurrL-1;c<row-CurrL;c++)//Fill last col
            {
                MAT[c][j]=sym;
            }            
        }
        string ans="0";
        flag=true;
        for(int i=0;i<row;i++) //Run over the matrix to assemble final answer
        {
            for(int j=0;j<col;j++)
            {
                if(flag){ans=MAT[i][j];}  
                else {ans+=MAT[i][j];}
                flag=false;               
            }
            if(i!=row-1) { ans+="\n";}
        }
        return ans;
    }  
}
