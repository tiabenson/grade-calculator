// This is a weighted grade calculator
// Created by Tia Benson

#include <iostream>
#include <vector>
#include <iomanip>

void calculate()
{
    int num = 1;
    float total, p, grade, percentage;
    std::vector<float> grades, percent;
    
    while(true)
    {
        std::cout<<"Enter grade #"<<num<<": ";
        std::cin>>grade;
        
        if(grade == 00) //stop taking grades if 00 is typed
        {
            break;
        }
        
        else
        {
            grades.push_back(grade);
        }

        std::cout<<"Enter percentage (%) of grade #"<<num<<": ";
        std::cin>>percentage;
        
        percent.push_back(percentage);
        num++;
        std::cout<<"\n";
        
    }
    
    for(int i = 0; i < grades.size(); i++) //calculate weighted average
    {
        total += (grades[i]*percent[i]);
        p += percent[i];
    }
    
    std::cout<<"\nYour average grade is "<<std::fixed<<std::setprecision(2)<<(total/p)<<std::endl;
    
    if((total/p) >= 90 && (total/p) <= 100) //determine letter grade
    {
        std::cout<<"Your letter grade is an A!"<<std::endl;
    }
    
    else if((total/p) >= 80 && (total/p) < 90)
    {
        std::cout<<"Your letter grade is a B."<<std::endl;
    }
    
    else if((total/p) >= 70 && (total/p) < 80)
    {
        std::cout<<"Your letter grade is a C..."<<std::endl;
    }
    
    else
    {
        std::cout<<"You failed the course."<<std::endl;
    }
}

int main(int argc, char ** argv)
{
    std::cout<<"\n** Weighted Grade Calculator **\n"<<std::endl;
    bool check = true;
    std::string ans;
    
    while (check)
    {
        calculate();
        
        std::cout<<"\n\nWould you like to calculate another average? (Y/N): ";
        std::cin>>ans;
        
        if(ans == "Y" || ans == "y" || ans == "Yes" || ans == "yes") //yes
        {
            std::cout<<"\n";
        }
        
        else //no
        {
            std::cout<<"\n\n***Thank you for using the grade calculator!***\n\n";
            break;
        }
    }
    
    return 0;
}

