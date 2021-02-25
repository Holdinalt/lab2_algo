#include <iostream>
#include <vector>

struct Int2 {

    int a[2];
};

std::string input;

bool checkNext(char, char);
std::string makeStringFromVector(const std::vector<int>&);

int main() {

    std::cin >> input;
    std::vector<Int2> indexesReform; // correct_in
    int inputSize = input.size();
    std::vector<int> indexesIn(inputSize, -1);
    int indexesOut[inputSize];
    std::fill(indexesOut, indexesOut+inputSize, -1);
    std::fill(indexesReform.begin(), indexesReform.end(), Int2({-1, -1}));
    std::vector<int> correctIndex(inputSize, -1);

    int counter = 0;

    for (int i = 0; i < input.size(); i++){
        correctIndex[i] = counter;
        ++counter;
    }

    counter = 0;

    for (int i = 0; i < input.size(); i++){

        if ((int)input[i] >= 97){
            indexesIn[i] = counter;
            ++counter;
        }
    }

    bool impossible = false;

//    std::cout << input << " input" << "\n";
//    std::cout << makeStringFromVector(indexesIn) << " indexesIn" << "\n";
//
//    std::cout << makeStringFromVector(correctIndex) << " correctIndex" << "\n";

    bool working = true;

    while (input.empty() == false && impossible == false){
        impossible = true;
        int size = input.size();
        for (int i = 0; i < size - 1; i++){
            if (checkNext(input[i], input[i+1])){


                if (input[i] < 97){
                    int index = correctIndex[i];
//                    std::cout << index << " index setup" << "\n";
                    indexesOut[index] = indexesIn[i+1];
                } else{
                    int index = correctIndex[i+1];
//                    std::cout << index << " index setup" << "\n";
                    indexesOut[index] = indexesIn[i];
                }
                input.erase(i, 2);
                indexesIn.erase(indexesIn.begin() + i, indexesIn.begin() + i + 2);
                correctIndex.erase(correctIndex.begin() + i , correctIndex.begin() + i + 2);
                size = size - 2;
                i--;
//                std::cout << input << " input" << "\n";
//                std::cout << makeStringFromVector(indexesIn) << " indexesIn" << "\n";
//
//                std::cout << makeStringFromVector(correctIndex) << " correctIndex" << "\n";

                impossible = false;
            }
        }
    }


    if (impossible){
        std::cout << "Impossible" << "\n";
        return 0;
    } else{
        std::cout << "Possible" << "\n";

        for (int i = 0; i < inputSize; i++){
            if (indexesOut[i] != -1){
                std::cout << indexesOut[i] + 1 << " ";
            }
        }
    }


    return 0;

}

bool checkNext(char now, char next){
    bool flag;

    flag = (int)now + 32 == (int)next || (int)now - 32 == (int)next;

    return flag;
}

std::string makeStringFromVector(const std::vector<int>& vector){
    std::string out = "";
    for (int i : vector){
        out.append(std::to_string(i));
    }
    return out;
}


