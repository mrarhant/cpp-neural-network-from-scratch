#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include "NeuralNetwork.h"

int main() {
    srand(time(NULL));
    NeuralNetwork nn(2, 4, 1);

    std::vector<Matrix> training_inputs;
    std::vector<Matrix> training_targets;

    // XOR Veri Seti (Girdiler ve Hedefler)
    Matrix in1(2, 1); in1.at(0,0)=0; in1.at(1,0)=0;
    Matrix out1(1, 1); out1.at(0,0)=0;
    training_inputs.push_back(in1); training_targets.push_back(out1);

    Matrix in2(2, 1); in2.at(0,0)=0; in2.at(1,0)=1;
    Matrix out2(1, 1); out2.at(0,0)=1;
    training_inputs.push_back(in2); training_targets.push_back(out2);

    Matrix in3(2, 1); in3.at(0,0)=1; in3.at(1,0)=0;
    Matrix out3(1, 1); out3.at(0,0)=1;
    training_inputs.push_back(in3); training_targets.push_back(out3);

    Matrix in4(2, 1); in4.at(0,0)=1; in4.at(1,0)=1;
    Matrix out4(1, 1); out4.at(0,0)=0;
    training_inputs.push_back(in4); training_targets.push_back(out4);

    std::cout << "Ag egitiliyor... Lutfen bekleyin." << std::endl;

    for (int i = 0; i < 50000; ++i) {
        int r = rand() % 4;
        nn.train(training_inputs[r], training_targets[r]);
    }

    std::cout << "Egitim Tamamlandi!\n" << std::endl;
    std::cout << "--- TEST SONUCLARI ---" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Girdi: [" << training_inputs[i].at(0,0) << ", " << training_inputs[i].at(1,0) << "] -> Beklenen: " << training_targets[i].at(0,0) << " | Agin Tahmini: ";
        Matrix result = nn.feedForward(training_inputs[i]);
        std::cout << result.at(0,0) << std::endl;
    }
    // ... (Eski test sonuçlarýný yazdýran döngü burada bitiyor)

    std::cout << "\n=====================================" << std::endl;
    std::cout << "       YAPAY ZEKA ILE TEST ET" << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "(Programdan cikmak icin herhangi bir adimda -1 girin)\n" << std::endl;

    // Kullanýcý Etkileþim Döngüsü
    while (true) {
        double val1, val2;

        std::cout << "1. Degeri girin (0 veya 1): ";
        std::cin >> val1;
        if (val1 == -1) break; // Kullanýcý -1 girerse döngüyü ve programý bitir

        std::cout << "2. Degeri girin (0 veya 1): ";
        std::cin >> val2;
        if (val2 == -1) break;

        // Kullanýcýnýn girdiði deðerleri matrise çevir
        Matrix user_input(2, 1);
        user_input.at(0, 0) = val1;
        user_input.at(1, 0) = val2;

        // Aða tahmin ettir
        Matrix prediction = nn.feedForward(user_input);

        // Sonucu þýk bir þekilde yazdýr
        std::cout << ">>> YAPAY SINIR AGININ TAHMINI: " << prediction.at(0, 0) << "\n" << std::endl;
    }

    return 0;
}

