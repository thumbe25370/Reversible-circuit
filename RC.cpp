#include<iostream>
#include<string>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<map> 
#include<algorithm>
#include<fstream>
#include<sstream> 

using namespace std;

string turn_binary(int input, int bit)
{
	int n;
	//45465464456454654654545445
	string bin_tmp,tmp;
	for(int i =0;i<bit;i++)
	{
		n = input % 2; 
		input = input / 2;
		tmp = (n + '0');
		bin_tmp = tmp + bin_tmp;
	}
	return bin_tmp;
}

int main(){
	int bit = 3;
//	char init_fun[8];
	int level = 1;
	
	map<string, int> decimal;
	vector<string> binary;
	for(int i = 0;i< pow(2,bit);i++)
	{
		//init_fun[i] = i + '0';
		level = level * (i+1);
		binary.push_back(turn_binary(i, bit));
		decimal[turn_binary(i, bit)] = i;
		//cout<<binary[i]<<endl;
	}

	string str_fun = "";
	fstream file;
	int tmp;
	char filename[]="a3b_result.txt";
	fstream fp;
    fp.open(filename, ios::out);
	file.open("a3b.txt",ios::in);
	while(getline(file, str_fun))
	{
		vector<int> function;
		stringstream ss(str_fun);
		while( ss >> tmp)
		{
			function.push_back(tmp);
			//cout<<tmp<<' ';
			fp<<tmp<<' ';//¼g¤J¦r¦ê
		}
		int min_edge;
		int min_hmd = 999;
		int edge  = bit;
		for(int j = 0 ; j < bit ; j++ ) 
		{
			int hmd = 0;	
			edge --;
			for(int k = 0;k<pow(2, bit);k++)
			{
				//int hmd = 0;
			
				if(binary[k][j] == '0')  
				{
					if(binary[function[k]][j] != '0')
					{
						for(int x  = 0; x < bit ; x++)
						{
							//cout<<binary[function[k]][x]<<'+'<<binary[k][x]<<endl;
							hmd += binary[function[k]][x] ^ binary[k][x];
						}
						//cout<<hmd<<endl; 
					}
				}
				else if(binary[k][j] == '1')
				{
					if(binary[function[k]][j] != '1')
					{
						for(int x  = 0; x < bit ; x++)
						{
							//cout<<binary[function[k]][x]<<'-'<<binary[k][x]<<endl;
							hmd += binary[function[k]][x] ^ binary[k][x]; 
						}
						//cout<<hmd<<endl;
					}
				}
			}
			//cout<<j<<"-"<<hmd<<endl;
			if(min_hmd > hmd)
			{
				min_hmd = hmd;
				min_edge = edge;
			}		
		}
		//cout<<min_edge<<":"<<min_hmd; 
		fp<<"edge: "<<min_edge<<" "<<"hd: "<<min_hmd<<endl;
		//cout<<endl;
	} 
}
