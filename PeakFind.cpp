#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<limits.h>
#include<vector>
#include <stdio.h>
//#include <unistd.h>
using namespace std;
//const int max_col= 1000,max_row=1000;
class peakinfo{
    public:
        int peak_row;
        int peak_col;
};
char * getcwd(char * path, int size);
int main(int argc, char *argv[]){
    ////getcwd(path,sizeof(path));
    string inputpath;
    inputpath.assign(argv[1]);
    inputpath=inputpath+"/matrix.data";
    string outputpath;
    outputpath.assign(argv[1]);
    outputpath=outputpath+"/output";
    //string outputpath=*argv[1]
    int row=0,col=0,peakcount=0;
    vector<vector<int> > matrix;
    ifstream matrixfile (inputpath);
    if(matrixfile.is_open()){
        matrixfile>>row;
        matrixfile>>col;
        matrix.resize(row+2);   
        for(int i =0;i<=row+1;i++){
            matrix[i].resize(col+2);             
        }
        for(int i =0;i<=row+1;i++)
            for(int j=0;j<=col+1;j++)
                matrix[i][j]=INT_MIN;
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++) 
                matrixfile >> matrix[i][j];
        } 
        matrixfile.close(); 
        peakinfo peak;
        vector<peakinfo> peak_list;

         for(int i=1;i<=row;i++)
            for(int j=1;j<=col;j++) 
                if(matrix[i][j]>=matrix[i-1][j]&&matrix[i][j]>=matrix[i+1][j]&&matrix[i][j]>=matrix[i][j-1]&&matrix[i][j]>=matrix[i][j+1]){
                    peakcount++;
                    peak.peak_row=i;
                    peak.peak_col=j;
                    peak_list.push_back(peak);
                }  
        ofstream final_peak(outputpath);
            if(!final_peak.is_open()) cout<<"failed to open file";
            else{
                final_peak<<peakcount<<"\n";
                for(int i=0;i<peakcount;i++)
                final_peak<<peak_list[i].peak_row<<" "<<peak_list[i].peak_col<<"\n";
                final_peak.close();
            }
    }
    else cout<<"unable to open file";
    return 0;
}