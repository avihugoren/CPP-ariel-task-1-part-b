#include "snowman.hpp"
#include <array>
namespace ariel

{
    void inputCheck(int num)
    {
        const int correct_length = 8 ;

        if (num <= 0)
        {
            throw std::out_of_range{"num must be positive but it is" + std::to_string(num) };
        }
         std::string snow_man (std::to_string(num));
         if(snow_man.size() != correct_length)//correct_length is 8
         {
            throw std::out_of_range{"num must be 8 digit long but it is "+ std::to_string(snow_man.size()) };
         }
          for (int i = 0; i < snow_man.size(); i++) //digit should be between 1 to 4
          {
           if(snow_man[i] < '1'|| '4' < snow_man[i])
           {
            throw std::out_of_range{"each digit must be between 1-4 but there is digit that equal"+ std::to_string(snow_man[i])};
           }
    }
     
    }
    std::string snowman(int num) 
    {
        inputCheck(num);
        const int options = 5;//there are 4 options for each element in the snowman +1 because i put all the elemnt in array 
        const int hat_index = 0;
        const int nose_mouth_index = 1;
        const int left_eye_index = 2;
        const int right_eye_index = 3;
        const int left_hand_index = 4;
        const int right_hand_index = 5;
        const int torso_index = 6 ;
        const int base_index = 7;
        const int upper_hand_number = 2;
        std::string ans;
        std::string snow_man (std::to_string(num)); //convert from int to string
        std::array<std::string,options> hats = { "",
                             "\n _===_ \n",      //hat 1 
                             "  ___ \n ..... \n",//hat 2
                             "   _  \n  /_\\  \n",//hat 3
                             "  ___  \n (_*_) \n" };//hat 4
        std::array<std::string,options> mouth_nose = { "" , "," , "." , "_" , " "};
        std::array<std::string,options> left_eye = { "" , "(." , "(o" , "(O" , "(-"};
        std::array<std::string,options> right_eye = { "" , ".)" , "o)" , "O)" , "-)"};
        std::array<std::string,options> left_hand = { "" , "<" , "\\" , "/" , " "};
        std::array<std::string,options> right_hand = { "" , ">\n" , "/\n" , "\\\n" , "\n"};
        std::array<std::string,options> torso = { "" , "( : )" , "(] [)" , "(> <)" , "(   )"};
        std::array<std::string,options> base = { "" , " ( : )\n" , " (\" \")\n" , " (___)\n" , " (   )\n"};
        bool up_left_hand = (snow_man[left_hand_index]-'0' == upper_hand_number);//if left hand is up so equal true
        bool up_right_hand= (snow_man[right_hand_index]-'0' == upper_hand_number);//if right hand is up so equal true
        ans.append(hats.at(snow_man[hat_index]-'0'));//add the hat
        //if both hands up
        if(up_right_hand&&up_left_hand)
        {
          ans.append(left_hand.at(snow_man[left_hand_index]-'0'));
          ans.append(left_eye.at(snow_man[left_eye_index]-'0'));
          ans.append(mouth_nose.at(snow_man[nose_mouth_index]-'0'));
          ans.append(right_eye.at(snow_man[right_eye_index]-'0'));
          ans.append(right_hand.at(snow_man[right_hand_index]-'0'));
          ans.append(" ");
          ans.append(torso.at(snow_man[torso_index]-'0'));
          ans.append("\n");
          ans.append(base.at(snow_man[base_index]-'0'));
        }
        //if right hand is up and left hand is not up
        else if(up_right_hand&&!up_left_hand)
        {
         ans.append(" ");
         ans.append(left_eye.at(snow_man[left_eye_index]-'0'));
         ans.append(mouth_nose.at(snow_man[nose_mouth_index]-'0'));
         ans.append(right_eye.at(snow_man[right_eye_index]-'0'));
         ans.append(right_hand.at(snow_man[right_hand_index]-'0'));
         ans.append(left_hand.at(snow_man[left_hand_index]-'0'));
         ans.append(torso.at(snow_man[torso_index]-'0'));
         ans.append("\n");
         ans.append(base.at(snow_man[base_index]-'0'));
        }
        //if left hand is up and right hand is not up 
        else if(!up_right_hand&&up_left_hand)
        {
          ans.append(left_hand.at(snow_man[left_hand_index]-'0'));
          ans.append(left_eye.at(snow_man[left_eye_index]-'0'));
          ans.append(mouth_nose.at(snow_man[nose_mouth_index]-'0'));
          ans.append(right_eye.at(snow_man[right_eye_index]-'0'));
          ans.append("\n ");
          ans.append(torso.at(snow_man[torso_index]-'0'));
          ans.append(right_hand.at(snow_man[right_hand_index]-'0'));
          ans.append(base.at(snow_man[base_index]-'0'));
        }
        //both hands not up
        else if(!up_right_hand&&!up_left_hand)
        {
          ans.append(" ");  
          ans.append(left_eye.at(snow_man[left_eye_index]-'0'));
          ans.append(mouth_nose.at(snow_man[nose_mouth_index]-'0'));
          ans.append(right_eye.at(snow_man[right_eye_index]-'0'));
          ans.append("\n");
          ans.append(left_hand.at(snow_man[left_hand_index]-'0'));
          ans.append(torso.at(snow_man[torso_index]-'0'));
          ans.append(right_hand.at(snow_man[right_hand_index]-'0'));
          ans.append(base.at(snow_man[base_index]-'0'));
        }
        return ans;
    };
}



