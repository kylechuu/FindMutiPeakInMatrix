#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<limits.h>
#include<vector>
using namespace std;
const int max_col= 1000,max_row=1000;
//int matrix[max_row][max_col]={0};
class peakinfo{
    public:
        int peak_row;
        int peak_col;
};
int main(int argc, char *argv[]){
    int row=0,col=0,peakcount=0;
    //int matrix[max_row][max_col]={0};
    vector<vector<int> > matrix;
    ifstream matrixfile ("matrix.data");
    if(matrixfile.is_open()){
        matrixfile>>row;
        matrixfile>>col; 
        matrix.resize(row);   
        for(int i =0;i<=row+1;i++){
            matrix[i].resize(col);
                //matrix[i][j]=INT_MIN;      //初始化矩陣
            //for(int j =0;j<=col+1;j++)
                //matrix[i][j].resize(col);
        }
        for(int i=1;i<=row;i++) 
            for(int j=1;j<=col;j++) 
                matrixfile >> matrix[i][j]; //將文字檔的矩陣元素儲存到矩陣裡
        matrixfile.close(); 
        peakinfo peak;
        vector<peakinfo> peak_list;


        for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++) 
                if(matrix[i][j]>matrix[i-1][j]&&matrix[i][j]>matrix[i+1][j]&&matrix[i][j]>matrix[i][j-1]&&matrix[i][j]>matrix[i][j+1]){
                    peakcount++;
                    peak.peak_row=i;
                    peak.peak_col=j;
                    peak_list.push_back(peak);
                }
            
        ofstream final_peak("final_peak");
            if(!final_peak.is_open()) cout<<"failed to open file";
            else{
                final_peak<<peakcount<<"\n";
                for(int i=0;i<peakcount;i++)
                final_peak<<peak_list[i].peak_row<<" "<<peak_list[i].peak_col<<"\n";
            }
    }
    else cout<<"unable to open file";
    return 0;
}