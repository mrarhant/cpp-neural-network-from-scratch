#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(int input, int hidden, int output)
    : inputNodes(input), hiddenNodes(hidden), outputNodes(output),
      weights_ih(hidden, input), weights_ho(output, hidden),
      bias_h(hidden, 1), bias_o(output, 1) {

    weights_ih.randomize();
    weights_ho.randomize();
    bias_h.randomize();
    bias_o.randomize();
    learning_rate = 0.1;
}

Matrix NeuralNetwork::feedForward(const Matrix& input_matrix) {
    Matrix hidden = weights_ih.multiply(input_matrix);
    hidden.add(bias_h);
    hidden.map(sigmoid);

    Matrix output = weights_ho.multiply(hidden);
    output.add(bias_o);
    output.map(sigmoid);

    return output;
}

void NeuralNetwork::train(const Matrix& input_matrix, const Matrix& target_matrix) {
    // 1. Ýleri Yayýlým
    Matrix hidden = weights_ih.multiply(input_matrix);
    hidden.add(bias_h);
    hidden.map(sigmoid);

    Matrix outputs = weights_ho.multiply(hidden);
    outputs.add(bias_o);
    outputs.map(sigmoid);

    // 2. Çýktý Katmaný
    Matrix output_errors = Matrix::subtract(target_matrix, outputs);
    Matrix gradients = outputs;
    gradients.map(dsigmoid);
    gradients.multiplyElements(output_errors);
    gradients.multiply(learning_rate);

    Matrix hidden_T = Matrix::transpose(hidden);
    Matrix weight_ho_deltas = gradients.multiply(hidden_T);

    weights_ho.add(weight_ho_deltas);
    bias_o.add(gradients);

    // 3. Gizli Katman
    Matrix who_T = Matrix::transpose(weights_ho);
    Matrix hidden_errors = who_T.multiply(output_errors);

    Matrix hidden_gradient = hidden;
    hidden_gradient.map(dsigmoid);
    hidden_gradient.multiplyElements(hidden_errors);
    hidden_gradient.multiply(learning_rate);

    Matrix inputs_T = Matrix::transpose(input_matrix);
    Matrix weight_ih_deltas = hidden_gradient.multiply(inputs_T);

    weights_ih.add(weight_ih_deltas);
    bias_h.add(hidden_gradient);
}
