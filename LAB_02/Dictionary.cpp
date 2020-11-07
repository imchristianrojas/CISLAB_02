//
//  Dictionary.cpp
//  LAB_02
//
//  Created by Christian on 11/1/20.
//

#include <stdio.h>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <iostream>
#include <regex>
class Dictionary
{
        
  
public:
    std::vector<std::pair<std::string, std::string>> dict;
  
    Dictionary()
    {
        std::ifstream nAndW;
        nAndW.open("test.txt");
        
        if(nAndW.ios_base::fail())
        {
            std::cerr<<"Cannot Open Narrow and Wides File "<<std::endl;
            exit(1);
            
        }
        std::pair<std::string, std::string> product;
        
        std::string character;
        std::string barcode;
        
        //test
        
        std::regex e("[^'],[^\\t],[^\\s]+");
        std::smatch m;
        
        


        while(!nAndW.eof())
        {
            std::getline(nAndW>>std::ws,character);
            std::getline(nAndW>>std::ws,barcode);
            character = character[1];
            product = std::make_pair(character, barcode);

            dict.push_back(product);



        }
        
        
        for(int i = 0; i<dict.size(); i++)
        {
            std::cout<<dict[i].first<< " "<<dict[i].second<<"\n"<<std::endl;
        }

        std::string binary;
        for(int i = 0; i<dict.size(); i++)
        {
            binary = "";
            for(int j = 0; j<dict[i].second.size(); j++)
            {
                if(dict[i].second[j] == 'w')
                    binary+= "1";
                else
                    binary+= "0";
            }
            dict[i].second = binary;
        }
        
        for(int i = 0; i<dict.size(); i++)
        {
            std::cout<<dict[i].first<< " "<<dict[i].second<<"\n"<<std::endl;
        }
        
        
        nAndW.close();
        
        
    }
    
    //maybe sort the vector? binary search. yes do this after I finish
    std::string lookUp(std::string binary)
    {
        for(int i = 0; i <dict.size(); i++)
        {
            if(binary == dict[i].second)
                return dict[i].first;
        }
        
        
        return "";
        
        
    }
    
    
    std::string binaryToName(std::string barcode)
    {
        
        std::string name;
        std::string binary;
        
        int i = 0;
        for(int k = 0; k<barcode.size(); k++)
        {
            binary +=barcode[k];
            if(i % 8 == 0 && i!=0)
            {
                name += lookUp(binary);
                binary = "";
                i = -1;
            }
            i++;
            
            
        }
        
        
        //std::cout<<name;
        
        return name;
    }
    
    
    
    
};
