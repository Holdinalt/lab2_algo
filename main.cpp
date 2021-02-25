#include <iostream>
#include <vector>

struct Int2 {

    int a[2];
};

std::string input;

bool checkNext(char, char);
void makeStringFromVector(const std::vector<Int2>&);

int main() {

    std::cin >> input;
    int inputSize = input.size();
    std::vector<Int2> indexesReform(inputSize); // correct_in
    int indexesOut[inputSize];
    std::fill(indexesOut, indexesOut+inputSize, -1);

    int counter = 0;

    for (int i = 0; i < input.size(); i++){

        if ((int)input[i] >= 97){
            indexesReform[i] = Int2({i, counter});
            ++counter;
        } else {
            indexesReform[i] = Int2({i, -1});
        }
    }

    bool impossible = false;

//    std::cout << input << " input" << "\n";
//    makeStringFromVector(indexesReform);

    while (input.empty() == false && impossible == false){
        impossible = true;
        int size = input.size();
        for (int i = 0; i < size - 1; i++){
            if (checkNext(input[i], input[i+1])){


                if (input[i] < 97){
                    int index = indexesReform[i].a[0]; //corr
//                    std::cout << index << " index setup" << "\n";
                    indexesOut[index] = indexesReform[i+1].a[1]; //inn
                } else{
                    int index = indexesReform[i+1].a[0]; //corr
//                    std::cout << index << " index setup" << "\n";
                    indexesOut[index] = indexesReform[i].a[1]; //inn
                }
                input.erase(i, 2);
                indexesReform.erase(indexesReform.begin() + i, indexesReform.begin() + i + 2);
                size = size - 2;
                i--;
//                std::cout << input << " input" << "\n";
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

bool checkNext(char now, char next){
    bool flag;

    flag = (int)now + 32 == (int)next || (int)now - 32 == (int)next;

    return flag;
}

void makeStringFromVector(const std::vector<Int2>& vector){
    std::string out1 = "";
    std::string out2 = "";
    for (Int2 i : vector){
        out1.append(std::to_string(i.a[0]));
        out2.append(std::to_string(i.a[1]));
    }

    std::cout << out1 << " correctIndex" << "\n";

    std::cout << out2 << " indexesIn" << "\n";

}


