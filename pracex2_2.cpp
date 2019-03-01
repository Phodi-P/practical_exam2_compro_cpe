#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] > x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	
	//Write your code here

	//Read file in to array
	float data[20];
	string txtline;
	int i = 0;
	ifstream score("score1.txt");
	while(getline(score,txtline))
	{
		data[i] = atof(txtline.c_str());
		i++;
	}
	score.close();

	//Determine ranking number
	int rankData[20];
	sort(data,20); //sort data
	for(int i = 0 ; i<20 ; i++)
	{
		rankData[i] = i+1;
		for(int j = 20; j>=0 ; j--)
		{
			if(data[j] == data[j-1])
			{
				rankData[j] = rankData[j-1];
			}
		}
	}
	//Output ranking
	ofstream rank("rank.txt");
	for(int i = 0; i<20 ; i++)
	{
		rank << data[i] << "=" << rankData[i];
		if(i < 19) rank << endl;
	}
	rank.close();

	
	return 0;
}

