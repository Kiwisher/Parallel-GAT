#include <vector>
#include <cstdlib>
#include <random>

#ifndef PROJ_NODE_H
#define PROJ_NODE_H

class Nodes {
public:
    int input_dim;
    int output_dim;
    int num_nodes;
    float **input_feats;
    float **output_feats;

    Nodes(int n_node, int in_dim, int out_dim) :
        input_dim(in_dim), output_dim(out_dim), num_nodes(n_node){
      input_feats = (float **) calloc(sizeof(float *), num_nodes);
      for (int i = 0; i < num_nodes; i++) {
        input_feats[i] = (float *) calloc(sizeof(float), input_dim);
      }
      output_feats = (float **) calloc(sizeof(float *), num_nodes);
      for (int i = 0; i < num_nodes; i++) {
        output_feats[i] = (float *) calloc(sizeof(float), output_dim);
      }
    }


    void random_init() {
      std::default_random_engine generator;
      std::normal_distribution<float> distribution(0.f, 0.1f);
      for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < input_dim; j++) {
          input_feats[i][j] = distribution(generator);
        }
      }
    }

    void flush(int new_output_dim) {
      float **tmp = input_feats;
      input_feats = output_feats;
      output_feats = tmp;
      input_dim = output_dim;
      for (int i = 0; i < num_nodes; i++) {
        free(output_feats[i]);
      }
      output_dim = new_output_dim;
      for (int i = 0; i < num_nodes; i++) {
        output_feats[i] = (float *) calloc(sizeof(float), output_dim);
      }
    }
};

#endif //PROJ_NODE_H
