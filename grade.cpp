// This is a weighted grade and GPA calculator
// Created by Tia Benson

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

void calculate()    //calculate weighted grade average
{
    int num = 1;
    float total, p, grade, percentage;
    std::vector<float> grades, percent;
    
    while(1)
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
    
    for(int i = 0; i < grades.size(); i++) //calculates weighted average
    {
        total += (grades[i]*percent[i]);
        p += percent[i];
    }
    
    std::cout<<"\nYour average grade is "<<(total/p)<<std::endl;
    
    //determine letter grade
    if((total/p) >= 90 && (total/p) <= 100)
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

void GPA()  //Calculates GPA
{
    int num = 1;
    std::string grade;
    int credit;
    double total = 0.00, total_credits = 0.00;
    std::vector<std::string> letters;
    std::vector<int> credits;
    
    while(1)
    {
        std::cout<<"Enter grade letter of class #"<<num<<": ";
        std::cin>>grade;
        
        if(grade == "done" || grade == "Done") //stop taking input for GPA if "done" is typed
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
    
    //Calculate GPA
    for(int i = 0; i < letters.size(); i++)
    {
        if(letters[i] == "A" || letters[i] == "a")  //A = 4 points
        {
            total += (4 * credits[i]);
            total_credits += credits[i];
        }

        else if(letters[i] == "B" || letters[i] == "b") //B = 3 points
        {
            total += (3 * credits[i]);
            total_credits += credits[i];
        }

        else if(letters[i] == "C" || letters[i] == "c") //C = 2 points
        {
            total += (2 * credits[i]);
            total_credits += credits[i];
        }

        else if(letters[i] == "D" || letters[i] == "d") //D = 1 point
        {
            total += (1 * credits[i]);
            total_credits += credits[i];
        }

        else    //assume the user typed a failing grade letter (0 points)
        {
            total += (0 * credits[i]);
            total_credits += credits[i];
        }
    }
    
    double gpa = total/total_credits;
    
    std::cout<<"\nYour GPA is "<<std::setprecision(2)<<std::fixed<<gpa<<std::endl;
 
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
        
        if(option == 1) //weighted grade
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
        
        else if(option == 2)    //GPA
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
        
        else if(option == 3)    //quit program
        {
            std::cout<<"\n***Thank you for using the grade calculator!***\n\n";
            exit(0);
        }
        
        else    //error check invalid input
        {
            std::cout<<"Option not recognized. Please try again."<<std::endl;
            continue;
        }
    }
 
    return 0;
}

