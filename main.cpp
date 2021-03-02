#include <iostream>
#include <vector>
#include <stack>

struct Int2 {
    char input;
    int a[2];
};

std::string input;

void makeStringFromVector(const std::vector<Int2>&);

//std::stack<char> stack;


int main() {


//    std::cin >> input;
//
//    char outArray[input.size()];
//
//    int indexCounter = 0;
//
//    stack.push(input[0]);
//
//    for(int i = 1; i < input.size(); i++){
//        if ((int)stack.top() - (int)input[i] == 32){
//
//        }
//    }







    int inputSize = input.size();
    std::vector<Int2> indexesReform(inputSize); // correct_in
    int indexesOut[inputSize];
    std::fill(indexesOut, indexesOut+inputSize, -1);

    int counter = 0;

    for (int i = 0; i < input.size(); i++){

        if ((int)input[i] >= 97){
            indexesReform[i] = Int2({input[i], i, counter});
            ++counter;
        } else {
            indexesReform[i] = Int2({input[i], i, -1});
        }
    }

    bool impossible = false;

//    makeStringFromVector(indexesReform);

    int size = indexesReform.size();

    while (size != 0 && impossible == false){
        impossible = true;

        for (int i = 0; i < size; i++){
            if (abs((int)indexesReform[i].input - (int)indexesReform[(i+1)%size].input) == 32){
                if (indexesReform[i].input < 97){
                    int index = indexesReform[i].a[0]; //corr
//                    std::cout << index << " index setup1" << "\n";
                    indexesOut[index] = indexesReform[(i+1)%size].a[1]; //inn
                } else{
                    int index = indexesReform[(i+1)%size].a[0]; //corr
//                    std::cout << index << " index setup2" << "\n";
                    indexesOut[index] = indexesReform[i].a[1]; //inn
                }

                indexesReform.erase(indexesReform.begin() + i);
                indexesReform.erase(indexesReform.begin() + (i % (size - 1)));
                size--;
                --size;
                i--;
//                makeStringFromVector(indexesReform);

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


void makeStringFromVector(const std::vector<Int2>& vector){
    std::string out0 = "";
    std::string out1 = "";
    std::string out2 = "";
    for (Int2 i : vector){
        out0.append(std::to_string(i.input));
        out1.append(std::to_string(i.a[0]));
        out2.append(std::to_string(i.a[1]));
    }

    std::cout << out0 << " input" << "\n";

    std::cout << out1 << " correctIndex" << "\n";

    std::cout << out2 << " indexesIn" << "\n";

}


