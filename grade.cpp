// This is a weighted grade calculator
// Created by Tia Benson

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

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
    
    std::cout<<"\nYour average grade is "<<(total/p)<<std::endl;
    
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

void GPA()
{
    int num = 1;
    std::string grade;
    int credit;
    int total = 0, total_credits = 0;
    std::vector<std::string> letters;
    std::vector<int> credits;
    
    while(true)
    {
        std::cout<<"Enter grade letter of class #"<<num<<": ";
        std::cin>>grade;
        
        if(grade == (std::to_string(00))) //stop taking grades if 00 is typed
        {
            break;
        }
        
        else
        {
            letters.push_back(grade);
        }
        
        std::cout<<"Enter number of credits of class #"<<num<<": ";
        std::cin>>credit;
        
        credits.push_back(credit);
        num++;
        std::cout<<"\n";
    }
    
    for(int i = 0; i < credits.size(); i++)
    {
        if(letters[i] == "A" || letters[i] == "a")
        {
            total += 4 * credits[i];
            total_credits += credits[i];
        }
        
        else if(letters[i] == "B" || letters[i] == "b")
        {
            total += 3 * credits[i];
            total_credits += credits[i];
        }
        
        else if(letters[i] == "C" || letters[i] == "c")
        {
            total += 2 * credits[i];
            total_credits += credits[i];
        }
        
        else if(letters[i] == "D" || letters[i] == "d")
        {
            total += 1 * credits[i];
            total_credits += credits[i];
        }
        
        else    //assume the user typed a failing grade letter
        {
            total += 0 * credits[i];
            total_credits += credits[i];
        }
    }
    
    float gpa = total/total_credits;
    
    std::cout<<"Your GPA is "<<gpa<<std::endl;
 
}

int main(int argc, char ** argv)
{
    bool check = true;
    
    while(check)
    {
        int option = 0;
        
        std::cout<<"\n** Weighted Grade Calculator **\n"<<std::endl;
        std::cout<<"Please type 1, 2, or 3 to select what you want to calculate:"<<std::endl;
        std::cout<<"1: Weighted Grade"<<std::endl;
        std::cout<<"2: GPA"<<std::endl;
        std::cout<<"3: Quit"<<std::endl;
        std::cin>>option;
        std::string ans;
        
        if(option == 1)
        {
            while(1)
            {
                calculate();
                
                std::cout<<"\n\nWould you like to calculate another average? (Y/N): ";
                std::cin>>ans;
                
                if(ans == "Y" || ans == "y" || ans == "Yes" || ans == "yes") //yes
                {
                    std::cout<<"\n";
                }
                
                else //if no is typed
                {
                    std::cout<<"\n***Thank you for using the weighted grade calculator!***\n\n";
                    break;
                }
            }
        }
        
        else if(option == 2)
        {
            while(1)
            {
                GPA();
                
                std::cout<<"\n\nWould you like to calculate another GPA? (Y/N): ";
                std::cin>>ans;
                
                if(ans == "Y" || ans == "y" || ans == "Yes" || ans == "yes") //yes
                {
                    std::cout<<"\n";
                }
                
                else //if no is typed
                {
                    std::cout<<"\n***Thank you for using the GPA calculator!***\n\n";
                    break;
                }
            }
        }
        
        else if(option == 3)
        {
            std::cout<<"\n***Thank you for using the grade calculator!***\n\n";
            exit(0);
        }
        
        else
        {
            std::cout<<"Option not recognized. Please try again."<<std::endl;
            continue;
        }
    }
 
    return 0;
}

