#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

#include "Matrix.h"

class NeuralNetwork {
private:
    int inputNodes;
    int hiddenNodes;
    int outputNodes;

    Matrix weights_ih;
    Matrix weights_ho;
    Matrix bias_h;
    Matrix bias_o;
    double learning_rate;

public:
    NeuralNetwork(int input, int hidden, int output);
    Matrix feedForward(const Matrix& input_matrix);
    void train(const Matrix& input_matrix, const Matrix& target_matrix);
};

#endif
