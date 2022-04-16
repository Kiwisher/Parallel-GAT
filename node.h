#include <vector>
#include <cstdlib>
#include <random>

#ifndef PROJ_NODE_H
#define PROJ_NODE_H

class node {
public:
    int feat_dim;
    int num_heads;
    int msg_dim;
    float *input_feats;  // feat_dim
    float **msgs;  // (num_heads, msg_dim)
    float **output_feats;  // (num_heads, msg_dim)

    // for testing purpose
    int *label; // msg_dim

    node(int n_feats, int n_heads, int message_dim) : feat_dim(n_feats), num_heads(n_heads),
                                                      msg_dim(message_dim) {
      input_feats = (float *) calloc(sizeof(float), n_feats);
      msgs = (float **) calloc(sizeof(float *), num_heads);
      for (int i = 0; i < num_heads; i++) {
        msgs[i] = (float *) calloc(sizeof(float), msg_dim);
      }
      output_feats = (float **) calloc(sizeof(float *), num_heads);
      for (int i = 0; i < num_heads; i++) {
        output_feats[i] = (float *) calloc(sizeof(float), msg_dim);
      }
      label = (int *) calloc(sizeof(int), msg_dim);
    }

    void random_init() {
      std::default_random_engine generator;
      std::normal_distribution<float> distribution(0.f, 0.1f);
      for (int i = 0; i < feat_dim; i++) {
        input_feats[i] = distribution(generator);
      }
    }

    void flush() {
//      float **tmp = input_feats;
//      input_feats = output_feats;
//      output_feats = tmp;
//      zero_out();
    }
//
//    void zero_out() {
//      for (int i = 0; i < num_heads; i++) {
//        for (int j = 0; j < msg_dim; j++)
//          output_feats[i][j] = 0.f;
//      }
//    }

    ~node() {
      free(input_feats);
      for (int i = 0; i < num_heads; i++) {
        free(msgs[i]);
      }
      free(msgs);
      for (int i = 0; i < num_heads; i++) {
        free(output_feats[i]);
      }
      free(output_feats);
      free(label);
    }
};

#endif //PROJ_NODE_H
