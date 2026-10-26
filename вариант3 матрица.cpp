#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

void fillMatrix(std::vector<int> *arr, size_t size, int inputMode){
    for (size_t i=0; i < size; i++){
        for (size_t j = 0; j < size; j++){
            switch(inputMode){
        case 1:
        std::cin>>arr[i][j]; break;
        case 2:
        arr[i][j] = rand() % 100; break;
        default:
        std::cout<<"Неверный выбор";
        std::exit(1);
            }
        }
    }
}

void process(std::vector<int> *arr, size_t size){
    int temp = 1;
    int rowMax = 0;
    int columnMax = 0;
        for(size_t i = 0; i < size; i++){
            for (size_t j = 0; j < size; j++) {  
            std::cout<<arr[i][j]<<" ";
            }
            std::cout<<"\n";
        }
  
    int maxValue = arr[size - 1][size - 1];
    for(size_t i = size - 1;i > 0; i--){
        for(size_t j = temp; j < size; j++){
            if(arr[i][j] > maxValue){
                maxValue = arr[i][j];
                rowMax = i;
                columnMax = j;
                temp++;
            }
        }
    }   
    std::cout<<"Максимальный элемент нижнего правого треугольника матрицы: "<<maxValue<<"\n";

    temp=0;
    for(size_t i = size - 1; i > 0; i--){
        for(size_t j = 0; j < size; j++){
            if(arr[i][j] > maxValue){
                maxValue = arr[i][j];
                rowMax = i;
                columnMax = j;
            }
        }
    }
    for(size_t i = 0; i < size; i++){
        std::swap(arr[0][i], arr[rowMax][i]);}
    for(size_t i = 0; i < size; i++){
        std::swap(arr[i][0], arr[i][columnMax]);
    }
    std::cout<<"Изменённая матрица: \n";

    for(size_t i = 0; i < size; i++){
            for (size_t j = 0; j < size; j++) {  
            std::cout<<arr[i][j]<<" ";
            }
                      std::cout<<"\n";
        }
}


int main(){
    size_t size;
    int inputMode;
    int temp = 1;
    srand(time(0));
    std::cout<<"Введите размер матрицы: \n";
    while (!(std::cin >> size) || size <= 0 || std::cin.peek() != '\n') {
        std::cout << "Ошибка! Введите натуральное число: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cout<<"1 - задать матрицу самому, 2 - рандомная генерация";
    std::cin>>inputMode;
    std::vector<std::vector<int>> arr(size, std::vector<int>(size));
        fillMatrix(arr.data(), size, inputMode);
        process(arr.data(), size);
return 0;
}